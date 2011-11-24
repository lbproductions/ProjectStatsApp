//
//  PlaceInfoViewController.m
//  ProjectStatsApp
//
//  Created by Niclas Raabe on 15.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import "PlaceInfoViewController.h"

@implementation PlaceInfoViewController

@synthesize m_place;
@synthesize streetName;
@synthesize townName;
@synthesize m_mapView;

-(id)init:(NSManagedObject*)place
{
    self = [super initWithNibName:@"PlaceInfoViewController" bundle:nil];
    
    if (self) {
        self.title = @"PlaceInformation";
        self.m_place = place;
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
    
    NSString* street = [[self.m_place valueForKey:@"strasse"] description];
    street = [street stringByAppendingString:@" "];
    street = [street stringByAppendingString:[[self.m_place valueForKey:@"number"] description]];
    self.streetName.text = street;
    NSString* town = [[self.m_place valueForKey:@"plz"] description];
    town = [town stringByAppendingString:@" "];
    town = [town stringByAppendingString:[[self.m_place valueForKey:@"ort"] description]];
    self.townName.text = town;
    
    [self.m_mapView setCenterCoordinate:[self addressLocation]];
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
    // Return the number of sections.
    return 3;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    if(section == 0){
        return 4;
    }
    /*
    if(section == 4){
        return self.m_keys.count; 
    }
     */
    //else{
        return 1;
    //}    
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if(cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue2 reuseIdentifier:CellIdentifier];
    }
    [self configureCell:cell atIndexPath:indexPath];
    return cell;
}
/*
- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
	
	NSString *sectionHeader = nil;
	
	if(section == 4) {
		sectionHeader = @"DrinksPerPlayer";
	}
	
	
	return sectionHeader;
}
*/

- (void)configureCell:(UITableViewCell *)cell atIndexPath:(NSIndexPath *)indexPath
{
    NSManagedObject *managedObject = self.m_place;
    switch (indexPath.section) {
        case 0:
            switch (indexPath.row) {
                case 0:
                    cell.textLabel.text = @"Straße";
                    cell.detailTextLabel.text = [[managedObject valueForKey:@"strasse"] description];
                    break;  
                case 1:
                    cell.textLabel.text = @"Number";
                    cell.detailTextLabel.text = [[managedObject valueForKey:@"number"] description];
                    break;
                case 2:
                    cell.textLabel.text = @"PLZ";
                    cell.detailTextLabel.text = [[managedObject valueForKey:@"plz"] description];
                    break;
                case 3:
                    cell.textLabel.text = @"Town";
                    cell.detailTextLabel.text = [[managedObject valueForKey:@"ort"] description];
                    break; 
                default:
                    break;
            }
            break;
        case 1:
            switch (indexPath.row) {
                case 0:
                    cell.textLabel.text = @"Comment";
                    cell.detailTextLabel.text = [[managedObject valueForKey:@"comment"] description];
                    break; 
                default:
                    break;
            }
            break; 
        case 2:
            switch (indexPath.row) {
                case 0:
                    cell.textLabel.text = @"Games";
                    cell.detailTextLabel.text = [[managedObject valueForKey:@"gameCount"] description];
                    break; 
                default:
                    break;
            }
            break;    
    }
    cell.editingAccessoryType = UITableViewCellAccessoryDetailDisclosureButton;
    cell.accessoryType = UITableViewCellAccessoryNone;
    //[cell.imageView setImage:[UIImage imageNamed:@"player.png"]];
}

-(CLLocationCoordinate2D) addressLocation {
    NSString *urlString = [NSString stringWithFormat:@"http://maps.google.com/maps/geo?q=address&output=csv", 
                           [[[self.m_place valueForKey:@"name"] description] stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
    NSLog(urlString);
    NSString *locationString = [NSString stringWithContentsOfURL:[NSURL URLWithString:urlString]];
    NSArray *listItems = [locationString componentsSeparatedByString:@","];
    
    double latitude = 0.0;
    double longitude = 0.0;
    
    if([listItems count] >= 4 && [[listItems objectAtIndex:0] isEqualToString:@"200"]) {
        latitude = [[listItems objectAtIndex:2] doubleValue];
        longitude = [[listItems objectAtIndex:3] doubleValue];
    }
    else {
        //Show error
    }
    CLLocationCoordinate2D location;
    location.latitude = latitude;
    location.longitude = longitude;
    
    return location;
}


@end
