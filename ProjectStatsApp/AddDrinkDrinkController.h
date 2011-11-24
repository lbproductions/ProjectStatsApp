//
//  AddDrinkDrinkController.h
//  ProjectStatsApp
//
//  Created by Niclas Raabe on 24.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AddDrinkDrinkController : UITableViewController <NSFetchedResultsControllerDelegate>

@property (strong, nonatomic) NSManagedObject* game;
@property (strong, nonatomic) NSMutableArray* selectedPlayers;
@property (strong, nonatomic) NSManagedObject* selectedDrink;
@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (strong, nonatomic) NSFetchedResultsController *fetchedResultsController;

- (id)initWithGameAndPlayers:(NSManagedObject*)agame players:(NSMutableArray*)players;
- (void)saveChanges;

@end
