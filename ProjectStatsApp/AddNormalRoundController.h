//
//  AddNormalRoundController.h
//  ProjectStatsApp
//
//  Created by Niklas Wulf on 24.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SetSchweinereiController.h"

@interface AddNormalRoundController : UIViewController <UITableViewDataSource, UITableViewDelegate, UIPickerViewDataSource, UIPickerViewDelegate, SetSchweinereiDelegate> {
    UITableView* tableView;
    UIPickerView* pickerView;
    int player1, player2, schweinereiPlayer;
}

@property (strong, nonatomic) IBOutlet UITableView* tableView;
@property (strong, nonatomic) IBOutlet UIPickerView* pickerView;

@property (strong, nonatomic) NSManagedObject* game;
@property (strong, nonatomic) NSMutableArray* currentPlayingPlayers;

- (id)initWithGame:(NSManagedObject*)agame;

- (void)saveChanges;

@end
