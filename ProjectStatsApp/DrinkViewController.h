//
//  DrinkViewController.h
//  ProjectStatsApp
//
//  Created by Niclas Raabe on 14.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <CoreData/CoreData.h>

@interface DrinkViewController : UITableViewController <NSFetchedResultsControllerDelegate>

- (id)init:(NSManagedObjectContext*)context;
- (void)configureCell:(UITableViewCell *)cell atIndexPath:(NSIndexPath *)indexPath;

@property (nonatomic, strong) NSMutableArray *drinks;
@property (strong, nonatomic) NSFetchedResultsController *fetchedResultsController;
@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;

@end
