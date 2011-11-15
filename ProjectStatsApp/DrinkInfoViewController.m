//
//  DrinkInfoViewController.m
//  ProjectStatsApp
//
//  Created by Niclas Raabe on 15.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import "DrinkInfoViewController.h"

@implementation DrinkInfoViewController

@synthesize m_drink;
@synthesize drinkName;
@synthesize m_keys;

-(id)init:(NSManagedObject*)drink
{
    self = [super initWithNibName:@"DrinkInfoViewController" bundle:nil];
    
    if (self) {
        self.title = @"DrinkInformation";
        self.m_drink = drink;
        self.m_keys = [[NSMutableArray alloc] init];
        
        NSMutableDictionary* dict = (NSMutableDictionary*)[self.m_drink valueForKey:@"drinksPerPlayer"];
        NSEnumerator *enumerator = [dict keyEnumerator];
        id object;
        
        while ((object = [enumerator nextObject])) {
            [self.m_keys addObject:object];
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
    
    self.drinkName.text = [[self.m_drink valueForKey:@"name"] description];

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
    return 5;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    if(section == 4){
        return self.m_keys.count; 
    }
    else{
        return 1;
    }    
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

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
	
	NSString *sectionHeader = nil;
	
	if(section == 4) {
		sectionHeader = @"DrinksPerPlayer";
	}
	
	
	return sectionHeader;
}

- (void)configureCell:(UITableViewCell *)cell atIndexPath:(NSIndexPath *)indexPath
{
    NSManagedObject *managedObject = self.m_drink;
    switch (indexPath.section) {
        case 0:
            switch (indexPath.row) {
                case 0:
                    cell.textLabel.text = @"Type";
                    cell.detailTextLabel.text = [[managedObject valueForKey:@"type"] description];
                    break;                    
                default:
                    break;
            }
            break;
            
        case 1:
            switch (indexPath.row) {
                case 0:
                    cell.textLabel.text = @"Size";
                    cell.detailTextLabel.text = [[managedObject valueForKey:@"size"] description];
                    break; 
                default:
                    break;
            }
            break;
        case 2:
            switch (indexPath.row) {
                case 0:
                    cell.textLabel.text = @"Alcohol Percentage";
                    cell.detailTextLabel.text = [[managedObject valueForKey:@"alc"] description];
                    break; 
                default:
                    break;
            }
            break;
        case 3:
            switch (indexPath.row) {
                case 0:
                    cell.textLabel.text = @"DrinkCount";
                    cell.detailTextLabel.text = [[managedObject valueForKey:@"drinkCount"] description];
                    break; 
                default:
                    break;
            }
            break;
        case 4:
            NSDictionary* dict = (NSMutableDictionary*)[self.m_drink valueForKey:@"drinksPerPlayer"];
            NSEnumerator *e = [self.m_keys objectEnumerator];
            id object;
            NSUInteger i = 0;
            while (object = [e nextObject]) {
                if(i == indexPath.row){
                    cell.textLabel.text = object;
                    cell.detailTextLabel.text = [[dict objectForKey:object] stringValue];
                }    
                i++;
            }
            switch (indexPath.row) {
                case 0:
                    
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

@end
