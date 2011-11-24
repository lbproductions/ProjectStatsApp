//
//  ServerLoader.h
//  ProjectStatsApp
//
//  Created by Niklas Wulf on 11.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "soapprojectstatsProxy.h"

@interface ServerLoader : NSObject <NSFetchedResultsControllerDelegate> {
    projectstatsProxy* proxy;
}

@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (strong, nonatomic) NSManagedObject *server;

+ (ServerLoader*)instance;

- (void)saveContext;
- (projectstatsProxy*)proxy;
- (void)setProxy:(projectstatsProxy*)newproxy;
- (const char*)host;

- (void)repopulateLibrary;
- (void)repopulatePlayerList;
- (void)repopulateDrinkList;
- (void)repopulatePlaceList;
- (void)repopulateGameList;

- (NSMutableArray*)currentPlayingPlayers:(NSManagedObject*)game;

@end
