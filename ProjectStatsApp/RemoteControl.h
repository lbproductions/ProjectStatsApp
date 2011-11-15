//
//  RemoteControl.h
//  ProjectStatsApp
//
//  Created by Niklas Wulf on 15.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface RemoteControl : UITableViewController

@property (strong, nonatomic) NSManagedObject* game;

- (id)initWithGame:(NSManagedObject*)somegame;

@end
