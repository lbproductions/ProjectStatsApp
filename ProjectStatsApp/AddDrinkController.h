//
//  AddDrinkController.h
//  ProjectStatsApp
//
//  Created by Niclas Raabe on 24.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AddDrinkController : UITableViewController <UITableViewDataSource, UITableViewDelegate>

@property (strong, nonatomic) NSManagedObject* game;
@property (strong, nonatomic) NSMutableArray* playersSortedByPosition;
@property (strong, nonatomic) NSMutableArray* selectedPlayers;

- (id)initWithGame:(NSManagedObject*)agame;
- (void) nextStepPressed;

@end
