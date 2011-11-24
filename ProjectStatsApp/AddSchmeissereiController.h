//
//  AddSchmeissereiController.h
//  ProjectStatsApp
//
//  Created by Niklas Wulf on 15.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AddSchmeissereiController : UITableViewController {
    UITableViewCell* saveCell;
    int selectedPlayer;
    int selectedSchmeisserei;
}

- (id)initWithGame:(NSManagedObject*)agame;

@property (strong, nonatomic) IBOutlet UITableViewCell *saveCell;
@property (strong, nonatomic) NSManagedObject* game;
@property (strong, nonatomic) NSMutableArray* currentPlayingPlayers;

@end
