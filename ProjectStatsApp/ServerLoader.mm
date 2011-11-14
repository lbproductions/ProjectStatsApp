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

- (id) init
{
    if (self = [super init])
    {
    }
    return self;
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
    proxy.playerList("127.0.0.1:1332","urn:projectstats:playerList",playerList);
    
    
    
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

@end
