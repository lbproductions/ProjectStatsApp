//
//  PlayerTabController.h
//  TestApp3
//
//  Created by Niclas Raabe on 10.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PlayerTabController : UITabBarController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil player:(NSManagedObject*)player;

@end
