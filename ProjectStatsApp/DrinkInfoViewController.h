//
//  DrinkInfoViewController.h
//  ProjectStatsApp
//
//  Created by Niclas Raabe on 15.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DrinkInfoViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>

-(id)init:(NSManagedObject*)drink;
- (void)configureCell:(UITableViewCell *)cell atIndexPath:(NSIndexPath *)indexPath;

@property (strong, nonatomic) IBOutlet UILabel* drinkName;
@property (strong, nonatomic) IBOutlet NSManagedObject* m_drink;
@property (strong, nonatomic) IBOutlet NSMutableArray* m_keys;

@end
