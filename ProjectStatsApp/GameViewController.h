//
//  GameViewController.h
//  ProjectStatsApp
//
//  Created by Niklas Wulf on 15.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface GameViewController : UITableViewController <NSFetchedResultsControllerDelegate>

- (id)init:(NSManagedObjectContext*)context;
- (void)configureCell:(UITableViewCell *)cell atIndexPath:(NSIndexPath *)indexPath;

@property (strong, nonatomic) NSFetchedResultsController *fetchedResultsController;
@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;

@end
