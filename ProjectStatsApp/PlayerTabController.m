//
//  PlayerTabController.m
//  TestApp3
//
//  Created by Niclas Raabe on 10.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "PlayerTabController.h"

#import "PlayerInfoViewController.h"
#import "PlayerStatsViewController.h"

@implementation PlayerTabController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil player:(NSManagedObject*)player
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        NSMutableArray *m_players = [NSMutableArray arrayWithCapacity:2];
        [m_players addObject:(PlayerInfoViewController*)[[PlayerInfoViewController alloc] init:player]];
        [m_players addObject:(PlayerStatsViewController*)[[PlayerStatsViewController alloc] initWithNibName:@"PlayerStatsViewController" bundle:nil]];
        [self setViewControllers:m_players];
        [self setSelectedViewController:[[self viewControllers] objectAtIndex:0]];
    }
    return self;
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

@end
