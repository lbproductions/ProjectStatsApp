//
//  PlayerGamesViewController.h
//  ProjectStatsApp
//
//  Created by Niclas Raabe on 13.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PlayerGamesViewController : UITableViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil player:(NSManagedObject*)player context:(NSString*)context displayTitle:(NSString*)displayTitle;

@property (nonatomic, retain) IBOutlet NSManagedObject* m_player;
@property (nonatomic, retain) NSString* m_context;

@end
