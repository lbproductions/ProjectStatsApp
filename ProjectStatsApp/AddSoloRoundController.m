//
//  AddSoloRoundController.m
//  ProjectStatsApp
//
//  Created by Niclas Raabe on 01.12.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import "ServerLoader.h"
#import "AddSoloRoundController.h"

const int MAXROWS = 1000;

@implementation AddSoloRoundController

@synthesize game;
@synthesize currentPlayingPlayers;
@synthesize tableView;
@synthesize pickerView;

- (id)initWithGame:(NSManagedObject *)agame
{
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad) {
        self = [super initWithNibName:@"AddSoloRoundController" bundle:nil];
    }
    else{
        //self = [super initWithNibName:@"AddNormalRoundController" bundle:nil];
    }
    if (self) {
        self.game = agame;
        pflichtSoli = [[NSMutableDictionary alloc] init];
        self.currentPlayingPlayers = [[ServerLoader instance] currentPlayingPlayers:self.game];
        for(NSManagedObject* player in self.currentPlayingPlayers){
            int playerId = [[player valueForKey:@"id"] intValue];
            int gameId = [[self.game valueForKey:@"id"] intValue];
            bool hasPflichtSolo = false;
            
            projectstatsProxy* proxy = [ServerLoader instance].proxy;
            proxy->hasPflichtSolo(playerId,gameId,hasPflichtSolo);
            [pflichtSoli setObject:[NSNumber numberWithBool:hasPflichtSolo] forKey:[NSNumber numberWithInt:playerId]];
            
        }
        soloPlayer = 0;
        soloType = @"";
        soloTypeRow = 0;
        pflichtSolo = true;
        schweinereiPlayer = 0;
        self.title = @"Add Solo-Round";
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
    int re1PlayerId = [[((NSManagedObject*)[currentPlayingPlayers objectAtIndex:soloPlayer]) valueForKey:@"id"] intValue];
    int points = MAXROWS/2 - [self.pickerView selectedRowInComponent:0];
    
    std::string typeSolo = [soloType cStringUsingEncoding:[NSString defaultCStringEncoding]];
    
    std::string result;
    proxy->addRound([ServerLoader instance].host, "urn:projectstats:addRound", gameId, re1PlayerId, 0, 0, schweinereiPlayer, 0, typeSolo, pflichtSolo, points, "", result);
    
    [self.navigationController popViewControllerAnimated:YES];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 4;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    if(section == 0) return 4;
    if(section == 1) return 6; //Buben, Damen, Trumpf, Fleischlos, Schwarz, Farb
    if(section == 2){
        if(soloType == @"Trumpf-Solo"){
            return 1;  
        }
        else{
            return 0;  
        }      
    }
    if(section == 3){
        int re1PlayerId = [[((NSManagedObject*)[currentPlayingPlayers objectAtIndex:soloPlayer]) valueForKey:@"id"] intValue];
        NSNumber* solo = (NSNumber*)[pflichtSoli objectForKey:[NSNumber numberWithInt:re1PlayerId]];
        if([solo boolValue]){
            return 0;
        }
        else{
            return 1;
        }
    } 
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
        
            if(soloPlayer == indexPath.row) {
                cell.accessoryType = UITableViewCellAccessoryCheckmark;
            }
            else {
                cell.accessoryType = UITableViewCellAccessoryNone;
            }
            break;
        case 1:
            switch (indexPath.row){
                case 0:
                    cell.textLabel.text = @"Buben-Solo";
                    break;
                case 1:
                    cell.textLabel.text = @"Damen-Solo";
                    break;
                case 2:
                    cell.textLabel.text = @"Fleischlos-Solo";
                    break;
                case 3:
                    cell.textLabel.text = @"Farb-Solo";
                    break;
                case 4:
                    cell.textLabel.text = @"Trumpf-Solo";
                    break;
                case 5:
                    cell.textLabel.text = @"Schwarz-Solo";
                    break;    
                    
            }
            if(soloTypeRow == indexPath.row) {
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
        case 3:
            if(indexPath.row == 0) {
                cell.textLabel.text = @"Pflichtsolo";
                if(pflichtSolo) {
                    cell.accessoryType = UITableViewCellAccessoryCheckmark;
                }
                else {
                    cell.accessoryType = UITableViewCellAccessoryNone;
                }
            }

        default:
            break;
    }
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if(indexPath.section == 0) {
        if(indexPath.row != soloPlayer) {
            soloPlayer = indexPath.row;
        }
        [self.tableView reloadData];
    }
    if(indexPath.section == 1) {
        switch (indexPath.row){
            case 0:
                soloType = @"Buben-Solo";
                break;
            case 1:
                soloType = @"Damen-Solo";
                break;
            case 2:
                soloType = @"Fleischlos-Solo";
                break;
            case 3:
                soloType = @"Farb-Solo";
                break;
            case 4:
                soloType = @"Trumpf-Solo";
                break;
            case 5:
                soloType = @"Schwarz-Solo";
                break;  
        }
        if(indexPath.row != soloTypeRow) {
            soloTypeRow = indexPath.row;
        }
        [self.tableView reloadData];
    }
    if(indexPath.section == 2) {
        if(indexPath.row == 0) {
            SetSchweinereiController* setSchweinereiController = [[SetSchweinereiController alloc] initWithCurrentPlayingPlayers:self.currentPlayingPlayers schweinereiPlayerId:[NSNumber numberWithInt:schweinereiPlayer ]];
            setSchweinereiController.delegate = self;
            
            [self.navigationController pushViewController:setSchweinereiController animated:YES];
        }
    }
    if(indexPath.section == 3) {
        if(indexPath.row == 0) {
            pflichtSolo = !pflichtSolo;
        }
        [self.tableView reloadData];
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
		sectionHeader = @"SoloPlayer";
	}
	if(section == 1) {
		sectionHeader = @"SoloType";
	}
	
	return sectionHeader;
}


@end
