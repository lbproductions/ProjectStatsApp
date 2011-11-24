//
//  AddNormalRoundController.m
//  ProjectStatsApp
//
//  Created by Niklas Wulf on 24.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import "AddNormalRoundController.h"
#import "ServerLoader.h"

const int MAXROWS = 1000;

@implementation AddNormalRoundController

@synthesize game;
@synthesize currentPlayingPlayers;
@synthesize tableView;
@synthesize pickerView;

- (id)initWithGame:(NSManagedObject *)agame
{
    self = [super initWithNibName:@"AddNormalRoundController" bundle:nil];
    if (self) {
        self.game = agame;
        self.currentPlayingPlayers = [[ServerLoader instance] currentPlayingPlayers:self.game];
        player1 = 0;
        player2 = 1;
        self.title = @"Add Round";
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
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (void)saveChanges
{
    //TODO runde hinzufügen
    
    [self.navigationController popViewControllerAnimated:YES];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 2;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    if(section == 0) return 4;
    if(section == 1) return 1;
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
            
            
            if(player1 == indexPath.row || player2 == indexPath.row) {
                cell.accessoryType = UITableViewCellAccessoryCheckmark;
            }
            else {
                cell.accessoryType = UITableViewCellAccessoryNone;
            }
            break;
            
        case 1:
            if(indexPath.row == 0) {
                cell.textLabel.text = @"Set Schweinerei";
                cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
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
        if(indexPath.row != player1 && indexPath.row != player2) {
            player2 = player1;
            player1 = indexPath.row;
        }
        [self.tableView reloadData];
    }
    if(indexPath.section == 2) {
        if(indexPath.row == 0) {
            
        }
    }
//    else if(indexPath.section == 1) {
//        selectedSchmeisserei = indexPath.row;
//        [self.tableView reloadData];
//    }
//    else if(indexPath.section == 2) {
//        NSManagedObject* player = (NSManagedObject*)[currentPlayingPlayers objectAtIndex:selectedPlayer];
//        
//        int gameId = [[self.game valueForKey:@"id"] intValue];
//        int playerId = [[player valueForKey:@"id"] intValue];
//        std::string result = "";
//        std::string schmeisserei = [[self tableView:self.tableView cellForRowAtIndexPath:[NSIndexPath indexPathForRow:selectedSchmeisserei inSection:1]].textLabel.text UTF8String];
//        
//        projectstatsProxy* proxy = [[ServerLoader instance] proxy];
//        proxy->addSchmeisserei([ServerLoader instance].host, "urn:projectstats:addSchmeisserei", gameId, playerId, schmeisserei, result);
//        [self.navigationController popViewControllerAnimated:YES];
//    }
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

@end
