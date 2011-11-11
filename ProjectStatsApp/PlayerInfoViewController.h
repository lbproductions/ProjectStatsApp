//
//  PlayerInfoViewController.h
//  TestApp3
//
//  Created by Niclas Raabe on 10.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PlayerInfoViewController : UIViewController{
}

-(id)init:(NSManagedObject*)player;

@property (strong, nonatomic) IBOutlet UILabel* playerName;
@property (strong, nonatomic) NSManagedObject* m_player;

@end
