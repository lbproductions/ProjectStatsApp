//
//  LibraryViewController.h
//  ProjectStatsApp
//
//  Created by Niclas Raabe on 11.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ServerLoader.h"

@interface LibraryViewController : UITableViewController <NSFetchedResultsControllerDelegate>

- (id)initWithStyle:(UITableViewStyle)style managedObjectContext:(NSManagedObjectContext*)context;

@property (strong, nonatomic) NSFetchedResultsController *fetchedResultsController;
@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (strong, nonatomic) ServerLoader *serverLoader;

@end
