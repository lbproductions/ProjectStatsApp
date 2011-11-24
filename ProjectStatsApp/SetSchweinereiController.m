//
//  SetSchweinereiController.m
//  ProjectStatsApp
//
//  Created by Niklas Wulf on 24.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import "SetSchweinereiController.h"
#import "ServerLoader.h"


@implementation SetSchweinereiController

@synthesize currentPlayingPlayers;
@synthesize delegate;
@synthesize playerId;

- (id)initWithCurrentPlayingPlayers:(NSMutableArray*)currentPlayers schweinereiPlayerId:(NSNumber *)player
{
    self = [super initWithStyle:UITableViewStyleGrouped];
    if (self) {
        self.currentPlayingPlayers = currentPlayers;
        self.playerId = player;
        
        if(self.currentPlayingPlayers.count == 4) {
            NSEntityDescription *entity = [NSEntityDescription entityForName:@"Player" 
                                                  inManagedObjectContext:[[ServerLoader instance] managedObjectContext]];
            NSManagedObject* noplayerobject = [[NSManagedObject alloc] initWithEntity:entity 
                                                   insertIntoManagedObjectContext:nil];
        
            [noplayerobject setValue:@"No player" forKey:@"name"];
            [noplayerobject setValue:[NSNumber numberWithInt:0] forKey:@"id"];
            [self.currentPlayingPlayers insertObject:noplayerobject atIndex:self.currentPlayingPlayers.count];
        }
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

    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
 
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.currentPlayingPlayers.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    }
    
    cell.textLabel.text = [[self.currentPlayingPlayers objectAtIndex:indexPath.row] valueForKey:@"name"];
    if([[self.currentPlayingPlayers objectAtIndex:indexPath.row] valueForKey:@"id"] == self.playerId){
        cell.accessoryType = UITableViewCellAccessoryCheckmark;
    }
    
    return cell;
}

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [self.delegate setSchweinereiController:self setPlayerSchweinerei:[[self.currentPlayingPlayers objectAtIndex:indexPath.row] valueForKey:@"id"]];

}

@end
