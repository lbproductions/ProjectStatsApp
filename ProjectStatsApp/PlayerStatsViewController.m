//
//  PlayerStatsViewController.m
//  TestApp3
//
//  Created by Niclas Raabe on 10.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "PlayerStatsViewController.h"

#import "PlayerGamesViewController.h"

@implementation PlayerStatsViewController

@synthesize gamesCell;
@synthesize winsCell;
@synthesize lossesCell;
@synthesize averageCell;
@synthesize pointsCell;
@synthesize m_player;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil player:(NSManagedObject*)player
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.m_player = player;
        self.title = @"PlayerStats";      
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
    //self.gamesCell.detailTextLabel.text = [[self.m_player valueForKey:@"games"] stringValue]; 
    self.gamesCell.detailTextLabel.text = [[(NSMutableDictionary*)[self.m_player valueForKey:@"games"]objectForKey:@"General"] stringValue]; 
    self.winsCell.detailTextLabel.text = [[(NSMutableDictionary*)[self.m_player valueForKey:@"wins"]objectForKey:@"General"] stringValue]; 
    self.lossesCell.detailTextLabel.text = [[(NSMutableDictionary*)[self.m_player valueForKey:@"losses"]objectForKey:@"General"] stringValue]; 
    self.pointsCell.detailTextLabel.text = [[(NSMutableDictionary*)[self.m_player valueForKey:@"points"]objectForKey:@"General"] stringValue]; 
    self.averageCell.detailTextLabel.text = [[(NSMutableDictionary*)[self.m_player valueForKey:@"average"]objectForKey:@"General"] stringValue]; 
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
    return 5;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"CellIdentifier";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {          
                switch (indexPath.row) {
                    case 0:
                        cell = self.gamesCell;
                        break;
                        
                    case 1:
                        cell = self.winsCell;
                        break;
                    case 2:
                        cell = self.lossesCell;
                        break;
                    case 3:
                        cell = self.pointsCell;
                        break;
                    case 4:
                        cell = self.averageCell;
                        break;
                    default:
                        break;
                }

        }
        
    return cell;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
	
	NSString *sectionHeader = nil;
	
	if(section == 0) {
		sectionHeader = @"Stats";
	}
	
	return sectionHeader;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSString* context;
    NSString* display;
    if(indexPath.row == 0){
        context = @"games";
        display = @"Games";
    }
    if(indexPath.row == 1){
        context = @"wins";
        display = @"Wins";
    }
    if(indexPath.row == 2){
        context = @"losses";
        display = @"Losses";
    }
    if(indexPath.row == 3){
        context = @"points";
        display = @"Points";
    }
    if(indexPath.row == 4){
        context = @"average";
        display = @"Average";
    }
    
    PlayerGamesViewController* gamesView = [[PlayerGamesViewController alloc] initWithNibName:@"PlayerGamesViewController" bundle:nil player:self.m_player context:context displayTitle:display];
    
    [self.navigationController pushViewController:gamesView animated:YES];
    
}



@end
