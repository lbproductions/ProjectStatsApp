//
//  AddHochzeitRoundController.h
//  ProjectStatsApp
//
//  Created by Niclas Raabe on 01.12.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SetSchweinereiController.h"

@interface AddHochzeitRoundController : UIViewController<UITableViewDataSource, UITableViewDelegate, UIPickerViewDataSource, UIPickerViewDelegate, SetSchweinereiDelegate> 

{
    UITableView* tableView;
    UIPickerView* pickerView;
    int hochzeitPlayer, teammate, schweinereiPlayer;
}

@property (strong, nonatomic) IBOutlet UITableView* tableView;
@property (strong, nonatomic) IBOutlet UIPickerView* pickerView;

@property (strong, nonatomic) NSManagedObject* game;
@property (strong, nonatomic) NSMutableArray* currentPlayingPlayers;

- (id)initWithGame:(NSManagedObject*)agame;

- (void)saveChanges;

@end
