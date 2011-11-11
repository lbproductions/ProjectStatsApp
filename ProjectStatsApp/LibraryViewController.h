//
//  LibraryViewController.h
//  ProjectStatsApp
//
//  Created by Niclas Raabe on 11.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LibraryViewController : UITableViewController{
    IBOutlet UITableViewCell *cellPlayers;
    IBOutlet UITableViewCell *cellGames;
    IBOutlet UITableViewCell *cellDrinks;
    IBOutlet UITableViewCell *cellPlaces;
}

@property (nonatomic, retain) IBOutlet UITableViewCell *cellPlayers;
@property (nonatomic, retain) IBOutlet UITableViewCell *cellGames;
@property (nonatomic, retain) IBOutlet UITableViewCell *cellDrinks;
@property (nonatomic, retain) IBOutlet UITableViewCell *cellPlaces;
@end
