//
//  AddTrumpfabgabeRoundController.m
//  ProjectStatsApp
//
//  Created by Niclas Raabe on 01.12.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import "AddTrumpfabgabeRoundController.h"
#import "ServerLoader.h"

const int MAXROWS = 1000;

@implementation AddTrumpfabgabeRoundController

@synthesize game;
@synthesize currentPlayingPlayers;
@synthesize tableView;
@synthesize pickerView;

- (id)initWithGame:(NSManagedObject *)agame
{
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad) {
        self = [super initWithNibName:@"AddTrumpfabgabeRoundController" bundle:nil];
    }
    else{
        //self = [super initWithNibName:@"AddNormalRoundController" bundle:nil];
    }
    if (self) {
        self.game = agame;
        self.currentPlayingPlayers = [[ServerLoader instance] currentPlayingPlayers:self.game];
        trumpfabgabePlayer = 0;
        abgabenTaker = 1;
        schweinereiPlayer = 0;
        self.title = @"Add Trumpfabgaben-Round";
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
    
    [self.pickerView selectRow:MAXROWS/2 inComponent:0 animated:NO];
    
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(saveChanges)];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}


- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
        return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
    } else {
        return YES;
    }
}

- (void)saveChanges
{
    projectstatsProxy* proxy = [ServerLoader instance].proxy;
    
    int gameId = [[self.game valueForKey:@"id"] intValue];
    int re1PlayerId = [[((NSManagedObject*)[currentPlayingPlayers objectAtIndex:trumpfabgabePlayer]) valueForKey:@"id"] intValue];
    int re2PlayerId = [[((NSManagedObject*)[currentPlayingPlayers objectAtIndex:abgabenTaker]) valueForKey:@"id"] intValue];
    int points = MAXROWS/2 - [self.pickerView selectedRowInComponent:0];
    
    std::string result;
    proxy->addRound([ServerLoader instance].host, "urn:projectstats:addRound", gameId, re1PlayerId, re2PlayerId, 0, schweinereiPlayer, re1PlayerId, "", false, points, "", result);
    
    [self.navigationController popViewControllerAnimated:YES];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 3;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    if(section == 0) return 4;
    if(section == 1) return 4;
    if(section == 2) return 1;
    return 0;
}

- (UITableViewCell *)tableView:(UITableView *)atableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"AddSchmeissereiTableViewCell";
    
    UITableViewCell *cell = [atableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    }
    
    switch (indexPath.section) {
        case 0:
            cell.textLabel.text = [((NSManagedObject*)[currentPlayingPlayers objectAtIndex:indexPath.row]) valueForKey:@"name"];
            
            
            if(trumpfabgabePlayer == indexPath.row) {
                cell.accessoryType = UITableViewCellAccessoryCheckmark;
            }
            else {
                cell.accessoryType = UITableViewCellAccessoryNone;
            }
            break;
        case 1:
            cell.textLabel.text = [((NSManagedObject*)[currentPlayingPlayers objectAtIndex:indexPath.row]) valueForKey:@"name"];
            
            
            if(abgabenTaker == indexPath.row) {
                cell.accessoryType = UITableViewCellAccessoryCheckmark;
            }
            else {
                cell.accessoryType = UITableViewCellAccessoryNone;
            }
            break;    
        case 2:
            if(indexPath.row == 0) {
                cell.textLabel.text = @"Set Schweinerei";
                if(schweinereiPlayer > 0) {
                    cell.accessoryType = UITableViewCellAccessoryCheckmark;
                }
                else {
                    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
                }
            }
            
            break;
        default:
            break;
    }
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if(indexPath.section == 0) {
        if(indexPath.row != trumpfabgabePlayer && indexPath.row != abgabenTaker) {
            trumpfabgabePlayer = indexPath.row;
        }
        [self.tableView reloadData];
    }
    if(indexPath.section == 1) {
        if(indexPath.row != trumpfabgabePlayer && indexPath.row != abgabenTaker) {
            abgabenTaker = indexPath.row;
        }
        [self.tableView reloadData];
        [self.tableView reloadData];
    }
    if(indexPath.section == 2) {
        if(indexPath.row == 0) {
            SetSchweinereiController* setSchweinereiController = [[SetSchweinereiController alloc] initWithCurrentPlayingPlayers:self.currentPlayingPlayers schweinereiPlayerId:[NSNumber numberWithInt:schweinereiPlayer ]];
            setSchweinereiController.delegate = self;
            
            [self.navigationController pushViewController:setSchweinereiController animated:YES];
        }
    }
}

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    return 1;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    if(component == 0) {
        return MAXROWS;
    }
    
    return 0;
}

- (NSString *)pickerView:(UIPickerView *)thePickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    return [NSString stringWithFormat:@"%@", [NSNumber numberWithInt:MAXROWS/2 - row]];
}

- (void)setSchweinereiController:(SetSchweinereiController*)controller setPlayerSchweinerei:(NSNumber*)playerId;
{
    schweinereiPlayer = [playerId intValue];
    [self.navigationController popViewControllerAnimated:YES];
    [self.tableView reloadData];
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
	
	NSString *sectionHeader = nil;
	
	if(section == 0) {
		sectionHeader = @"TrumpfabgabePlayer";
	}
	if(section == 1) {
		sectionHeader = @"TrumpfabgabeTaker";
	}
	
	return sectionHeader;
}


@end
