//
//  ServerTableViewController.h
//  ServerView
//
//  Created by Niklas Wulf on 10.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "EditServerViewController.h"
#import "ServerLoader.h"

@interface ServerTableViewController : UITableViewController <NSFetchedResultsControllerDelegate>

@property (strong, nonatomic) NSFetchedResultsController *fetchedResultsController;
@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (strong, nonatomic) EditServerViewController* editServerViewController;
@property (strong, nonatomic) ServerLoader *serverLoader;

- (void)configureCell:(UITableViewCell *)cell atIndexPath:(NSIndexPath *)indexPath;

@end
