//
//  ServerLoader.m
//  ProjectStatsApp
//
//  Created by Niklas Wulf on 11.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import "ServerLoader.h"
#import "soapprojectstatsProxy.h"

@interface NSDictionary (MWBDictionary)

+ (id)dictionaryWithData:(NSData *)data;
- (id)initWithData:(NSData *)data;

@end

@implementation NSDictionary (MWBDictionary)

+ (id)dictionaryWithData:(NSData *)data {
    return [[NSDictionary alloc] initWithData:data];
}

- (id)initWithData:(NSData *)data {
    NSString *tmp = nil;
    
    self = (NSDictionary *)[NSPropertyListSerialization
                            propertyListFromData:data
                            mutabilityOption:NSPropertyListImmutable
                            format:NULL
                            errorDescription:&tmp];
    
    NSAssert1(tmp == nil,@"Fehler in plist: %@",tmp);
    
    return self;
}

@end

@implementation ServerLoader

@synthesize managedObjectContext = __managedObjectContext;
@synthesize server = __server;

- (id) init
{
    if (self = [super init])
    {
    }
    return self;
}

- (void)setServer:(NSManagedObject *)newserver
{
    if(newserver != __server) {
        __server = nil;
        __server = newserver;
        [self repopulateLibrary];
    }
}

- (void) repopulateLibrary
{
    const char* host = [[self.server valueForKey:@"host"] UTF8String];
    NSLog(@"Repopulating from server: %s", host);
    [self repopulateDrinkList];
    [self repopulatePlayerList];
    [self repopulatePlaceList];
    [self repopulateGameList];
}

- (void)repopulatePlayerList
{
    //clear all players:
    NSManagedObjectContext * context = [self managedObjectContext];
    NSFetchRequest * fetch = [[NSFetchRequest alloc] init];
    NSEntityDescription* entity = [NSEntityDescription entityForName:@"Player" inManagedObjectContext:context];
    [fetch setEntity:entity];
    NSArray * result = [context executeFetchRequest:fetch error:nil];
    for (id player in result) {
        [context deleteObject:player];
    }
    
    projectstatsProxy proxy;
    PlayerList playerList;
    const char* host = [[self.server valueForKey:@"host"] UTF8String];
    if(proxy.playerList(host,"urn:projectstats:playerList",playerList) != SOAP_OK) {
        proxy.soap_print_fault(stderr);
    }
    
    
    for(std::vector<PlayerInformation>::const_iterator it = playerList.playerList.begin(); it != playerList.playerList.end(); it++) {
        NSManagedObject *newManagedObject = [NSEntityDescription insertNewObjectForEntityForName:[entity name] inManagedObjectContext:context];
        NSString* name = [NSString stringWithUTF8String:it->name];
        NSNumber* identifier = [NSNumber numberWithInt:it->id];
        std::vector<StringIntPair>  gameHash = it->games;
        NSMutableDictionary* gamesDict = [NSMutableDictionary dictionary];
        for(std::vector<StringIntPair>::const_iterator ite = gameHash.begin(); ite != gameHash.end(); ite++) {
            [gamesDict setObject:[NSNumber numberWithInt:ite->value] forKey:[NSString stringWithUTF8String:ite->key]];
        }
        std::vector<StringIntPair> wins = it->wins;
        NSMutableDictionary* winsDict = [NSMutableDictionary dictionary];
        for(std::vector<StringIntPair>::const_iterator ite = wins.begin(); ite != wins.end(); ite++) {
            [winsDict setObject:[NSNumber numberWithInt:ite->value] forKey:[NSString stringWithUTF8String:ite->key]];
        }
        std::vector<StringIntPair> losses = it->losses;
        NSMutableDictionary* lossesDict = [NSMutableDictionary dictionary];
        for(std::vector<StringIntPair>::const_iterator ite = losses.begin(); ite != losses.end(); ite++) {
            [lossesDict setObject:[NSNumber numberWithInt:ite->value] forKey:[NSString stringWithUTF8String:ite->key]];
        }
        std::vector<StringIntPair> points = it->points;
        NSMutableDictionary* pointsDict = [NSMutableDictionary dictionary];
        for(std::vector<StringIntPair>::const_iterator ite = points.begin(); ite != points.end(); ite++) {
            [pointsDict setObject:[NSNumber numberWithInt:ite->value] forKey:[NSString stringWithUTF8String:ite->key]];
        }
        std::vector<StringDoublePair> average = it->average;
        NSMutableDictionary* averageDict = [NSMutableDictionary dictionary];
        for(std::vector<StringDoublePair>::const_iterator ite = average.begin(); ite != average.end(); ite++) {
            [averageDict setObject:[NSNumber numberWithDouble:ite->value] forKey:[NSString stringWithUTF8String:ite->key]];
        }
        [newManagedObject setValue:name forKey:@"name"];
        [newManagedObject setValue:identifier forKey:@"id"];
        [newManagedObject setValue:winsDict forKey:@"wins"];
        [newManagedObject setValue:lossesDict forKey:@"losses"];
        [newManagedObject setValue:pointsDict forKey:@"points"];
        [newManagedObject setValue:averageDict forKey:@"average"];
        [newManagedObject setValue:gamesDict forKey:@"games"];
        
    }
    
    NSError* error = nil;
    [context save:&error];
}  

- (void)repopulateDrinkList
{
    //clear all drinks:
    NSManagedObjectContext * context = [self managedObjectContext];
    NSFetchRequest * fetch = [[NSFetchRequest alloc] init];
    NSEntityDescription* entity = [NSEntityDescription entityForName:@"Drink" inManagedObjectContext:context];
    [fetch setEntity:entity];
    NSArray * result = [context executeFetchRequest:fetch error:nil];
    for (id drink in result) {
        [context deleteObject:drink];
    }
    
    projectstatsProxy proxy;
    DrinkList drinkList;
    const char* host = [[self.server valueForKey:@"host"] UTF8String];
    proxy.drinkList(host ,"urn:projectstats:drinkList",drinkList);
    
    
    
    for(std::vector<DrinkInformation>::const_iterator it = drinkList.drinkList.begin(); it != drinkList.drinkList.end(); it++) {
        NSManagedObject *newManagedObject = [NSEntityDescription insertNewObjectForEntityForName:[entity name] inManagedObjectContext:context];
        NSString* name = [NSString stringWithUTF8String:it->name];
        NSNumber* identifier = [NSNumber numberWithInt:it->id];
        std::vector<StringIntPair> drinksPerPlayer = it->drinksPerPlayer;
        NSMutableDictionary* drinksPerPlayerDict = [NSMutableDictionary dictionary];
        for(std::vector<StringIntPair>::const_iterator ite = drinksPerPlayer.begin(); ite != drinksPerPlayer.end(); ite++) {
            [drinksPerPlayerDict setObject:[NSNumber numberWithInt:ite->value] forKey:[NSString stringWithUTF8String:ite->key]];
        }
        NSNumber* size = [NSNumber numberWithDouble:it->size];
        NSNumber* alc = [NSNumber numberWithDouble:it->alc];
        NSNumber* drinkCount = [NSNumber numberWithInt:it->drinkCount];
        NSString* type = [NSString stringWithUTF8String:it->type];
        [newManagedObject setValue:name forKey:@"name"];
        [newManagedObject setValue:identifier forKey:@"id"];
        [newManagedObject setValue:drinksPerPlayerDict forKey:@"drinksPerPlayer"];
        [newManagedObject setValue:size forKey:@"size"];
        [newManagedObject setValue:alc forKey:@"alc"];
        [newManagedObject setValue:type forKey:@"type"];
        [newManagedObject setValue:drinkCount forKey:@"drinkCount"];
        
    }
    
    NSError* error = nil;
    [context save:&error];
} 

- (void)repopulatePlaceList
{
    //clear all drinks:
    NSManagedObjectContext * context = [self managedObjectContext];
    NSFetchRequest * fetch = [[NSFetchRequest alloc] init];
    NSEntityDescription* entity = [NSEntityDescription entityForName:@"Place" inManagedObjectContext:context];
    [fetch setEntity:entity];
    NSArray * result = [context executeFetchRequest:fetch error:nil];
    for (id place in result) {
        [context deleteObject:place];
    }
    
    projectstatsProxy proxy;
    PlaceList placeList;
    const char* host = [[self.server valueForKey:@"host"] UTF8String];
    proxy.placeList(host ,"urn:projectstats:placeList",placeList);
    
    
    
    for(std::vector<PlaceInformation>::const_iterator it = placeList.placeList.begin(); it != placeList.placeList.end(); it++) {
        NSManagedObject *newManagedObject = [NSEntityDescription insertNewObjectForEntityForName:[entity name] inManagedObjectContext:context];
        NSString* name = [NSString stringWithUTF8String:it->name];
        NSNumber* identifier = [NSNumber numberWithInt:it->id];
        /*
        std::vector<char*> players = it->players;
        NSMutableArray* playersList = [[NSMutableArray alloc] init];
        for(std::vector<char*>::const_iterator ite = players.begin(); ite != players.end(); ite++) {
            //[playersList addObject:[NSString stringWithUTF8String:ite]];
        }
         */
        NSNumber* number = [NSNumber numberWithInt:it->number];
        NSNumber* plz = [NSNumber numberWithInt:it->plz];
        NSNumber* gameCount = [NSNumber numberWithInt:it->gameCount];
        NSString* strasse = [NSString stringWithUTF8String:it->strasse];
        NSString* comment = [NSString stringWithUTF8String:it->comment];
        NSString* ort = [NSString stringWithUTF8String:it->ort];
        [newManagedObject setValue:name forKey:@"name"];
        [newManagedObject setValue:identifier forKey:@"id"];
        //[newManagedObject setValue:playersList forKey:@"players"];
        [newManagedObject setValue:plz forKey:@"plz"];
        [newManagedObject setValue:number forKey:@"number"];
        [newManagedObject setValue:gameCount forKey:@"gameCount"];
        [newManagedObject setValue:comment forKey:@"comment"];
        [newManagedObject setValue:strasse forKey:@"strasse"];
        [newManagedObject setValue:ort forKey:@"ort"];
        
    }
    
    NSError* error = nil;
    [context save:&error];
} 

- (void)repopulateGameList
{
    //clear all games:
    NSManagedObjectContext * context = [self managedObjectContext];
    NSFetchRequest * fetch = [[NSFetchRequest alloc] init];
    NSEntityDescription* entity = [NSEntityDescription entityForName:@"Game" inManagedObjectContext:context];
    [fetch setEntity:entity];
    NSArray * result = [context executeFetchRequest:fetch error:nil];
    for (id game in result) {
        [context deleteObject:game];
    }
    
    projectstatsProxy proxy;
    GameList gameList;
    const char* host = [[self.server valueForKey:@"host"] UTF8String];
    proxy.gameList(host ,"urn:projectstats:gameList",gameList);
    
    
    
    for(std::vector<GameInformation>::const_iterator it = gameList.gameList.begin(); it != gameList.gameList.end(); it++) {
        NSManagedObject *newManagedObject = [NSEntityDescription insertNewObjectForEntityForName:[entity name] inManagedObjectContext:context];
        NSString* name = [NSString stringWithUTF8String:it->name];
        NSNumber* identifier = [NSNumber numberWithInt:it->id];
        
        [newManagedObject setValue:name forKey:@"name"];
        [newManagedObject setValue:identifier forKey:@"id"];
    }
    
    NSError* error = nil;
    [context save:&error];
} 
@end
