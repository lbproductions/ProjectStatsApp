//
//  PlaceViewController.h
//  ProjectStatsApp
//
//  Created by Niclas Raabe on 15.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <CoreData/CoreData.h>

@interface PlaceViewController : UITableViewController <NSFetchedResultsControllerDelegate>

- (id)init:(NSManagedObjectContext*)context;
- (void)configureCell:(UITableViewCell *)cell atIndexPath:(NSIndexPath *)indexPath;

@property (strong, nonatomic) NSFetchedResultsController *fetchedResultsController;
@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;

@end
