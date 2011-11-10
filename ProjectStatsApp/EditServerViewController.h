//
//  EditServerViewController.h
//  ServerView
//
//  Created by Niklas Wulf on 10.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface EditServerViewController : UITableViewController {
    UITableViewCell *nameCell;
    UITableViewCell *hostCell;
    UITableViewCell *usernameCell;
    UITableViewCell *passwordCell;
}

@property (nonatomic, retain) IBOutlet UITableViewCell *nameCell;
@property (nonatomic, retain) IBOutlet UITableViewCell *hostCell;
@property (nonatomic, retain) IBOutlet UITableViewCell *usernameCell;
@property (nonatomic, retain) IBOutlet UITableViewCell *passwordCell;

@property (nonatomic, retain) IBOutlet UITextField *nameTextView;
@property (nonatomic, retain) IBOutlet UITextField *hostTextView;
@property (nonatomic, retain) IBOutlet UITextField *usernameTextView;
@property (nonatomic, retain) IBOutlet UITextField *passwordTextView;

@property (nonatomic, retain) NSManagedObject* server;

- (void)configureView;
- (void)saveChanges;
- (void)dismissChanges;

@end
