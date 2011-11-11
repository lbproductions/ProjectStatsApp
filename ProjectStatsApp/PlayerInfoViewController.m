//
//  PlayerInfoViewController.m
//  TestApp3
//
//  Created by Niclas Raabe on 10.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "PlayerInfoViewController.h"

@implementation PlayerInfoViewController

@synthesize playerName;
@synthesize m_player;

-(id)init:(NSManagedObject*)player
{
    self = [super initWithNibName:@"PlayerInfoViewController" bundle:nil];
    
    if (self) {
        self.title = @"PlayerInformation";
        self.m_player = player;
        //self.playerName.text = [[player valueForKey:@"name"] description];
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
    
    self.playerName.text = [[m_player valueForKey:@"name"] description];
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
