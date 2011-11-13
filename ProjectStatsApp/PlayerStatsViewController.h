//
//  PlayerStatsViewController.h
//  TestApp3
//
//  Created by Niclas Raabe on 10.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PlayerStatsViewController : UITableViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil player:(NSManagedObject*)player;

@property (nonatomic, retain) IBOutlet NSManagedObject* m_player;
@property (nonatomic, retain) IBOutlet UITableViewCell *gamesCell;
@property (nonatomic, retain) IBOutlet UITableViewCell *winsCell;

@end
