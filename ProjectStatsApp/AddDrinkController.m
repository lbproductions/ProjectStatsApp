//
//  AddDrinkController.m
//  ProjectStatsApp
//
//  Created by Niclas Raabe on 24.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import "AddDrinkController.h"
#import "ServerLoader.h"
#import "AddDrinkDrinkController.h"

@implementation AddDrinkController

@synthesize game;
@synthesize playersSortedByPosition;
@synthesize selectedPlayers;

- (id)initWithGame:(NSManagedObject *)agame
{
    self = [super initWithNibName:@"AddDrinkController" bundle:nil];
    if (self) {
        self.game = agame;
        self.playersSortedByPosition = [[ServerLoader instance] currentPlayingPlayers:self.game];
        self.title = @"Add Drink - Players";
        self.selectedPlayers = [[NSMutableArray alloc] initWithCapacity:self.playersSortedByPosition.count];
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
    
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(nextStepPressed)];
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

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.playersSortedByPosition.count;
}

- (UITableViewCell *)tableView:(UITableView *)atableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"AddDrinkTableViewCell";
    
    UITableViewCell *cell = [atableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    }
    
    cell.textLabel.text = [((NSManagedObject*)[self.playersSortedByPosition objectAtIndex:indexPath.row]) valueForKey:@"name"];
     
    if([self.selectedPlayers containsObject:[self.playersSortedByPosition objectAtIndex:indexPath.row]]){
        cell.accessoryType = UITableViewCellAccessoryCheckmark;
    }
    else{
        cell.accessoryType = UITableViewCellAccessoryNone;
    }    
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if(![self.selectedPlayers containsObject:[self.playersSortedByPosition objectAtIndex:indexPath.row]]){
        [self.selectedPlayers addObject:[self.playersSortedByPosition objectAtIndex:indexPath.row]];
    }
    else{
        [self.selectedPlayers removeObject:[self.playersSortedByPosition objectAtIndex:indexPath.row]];
    }
    
    [self.tableView reloadData];
}

- (void) nextStepPressed
{
    AddDrinkDrinkController* drinks = [[AddDrinkDrinkController alloc] initWithGameAndPlayers:self.game players:self.selectedPlayers];
    [self.navigationController pushViewController:drinks animated:YES];
}

@end
