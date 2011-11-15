//
//  ServerLoader.h
//  ProjectStatsApp
//
//  Created by Niklas Wulf on 11.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ServerLoader : NSObject <NSFetchedResultsControllerDelegate>

@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (strong, nonatomic) NSManagedObject *server;

- (id)init;
- (void)repopulateLibrary;
- (void)repopulatePlayerList;
- (void)repopulateDrinkList;
- (void)repopulatePlaceList;

@end
