//
//  ServerLoader.m
//  ProjectStatsApp
//
//  Created by Niklas Wulf on 11.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import "ServerLoader.h"
#import "soapprojectstatsProxy.h"

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
        [newManagedObject setValue:name forKey:@"name"];
        [newManagedObject setValue:identifier forKey:@"id"];
    }
    
    NSError* error = nil;
    [context save:&error];
}  

@end
