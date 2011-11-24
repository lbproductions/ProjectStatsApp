//
//  SetSchweinereiController.h
//  ProjectStatsApp
//
//  Created by Niklas Wulf on 24.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SetSchweinereiController : UITableViewController

@property (strong, nonatomic) id delegate;
@property (strong, nonatomic) NSMutableArray* currentPlayingPlayers;
@property (strong, nonatomic) NSNumber* playerId;


- (id)initWithCurrentPlayingPlayers:(NSMutableArray*)currentPlayers schweinereiPlayerId:(NSNumber*)playerId;

@end

@protocol SetSchweinereiDelegate <NSObject>

- (void)setSchweinereiController:(SetSchweinereiController*)controller setPlayerSchweinerei:(NSNumber*)playerId;

@end