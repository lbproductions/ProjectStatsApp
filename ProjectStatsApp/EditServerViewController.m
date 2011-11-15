//
//  EditServerViewController.m
//  ServerView
//
//  Created by Niklas Wulf on 10.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import "AppDelegate.h"
#import "EditServerViewController.h"

@implementation EditServerViewController

@synthesize server = _server;

@synthesize hostCell;
@synthesize nameCell;
@synthesize usernameCell;
@synthesize passwordCell;
@synthesize nameTextView;
@synthesize hostTextView;
@synthesize usernameTextView;
@synthesize passwordTextView;

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        [self configureView];
    }
    return self;
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

- (void)setServer:(NSManagedObject *)newserver
{
    if(_server != newserver) {
        _server = newserver;
        [self configureView];
    }
}

- (void)configureView
{
    if(self.server) {
        self.title = [self.server valueForKey:@"displayName"];
        self.nameTextView.text = [self.server valueForKey:@"displayName"];
        self.hostTextView.text = [self.server valueForKey:@"host"];
        self.usernameTextView.text = [self.server valueForKey:@"username"];
        self.passwordTextView.text = [self.server valueForKey:@"password"];
        
        [self.nameTextView becomeFirstResponder];
    }
}

#pragma mark - View lifecycle

-(void)saveChanges
{    
    [self.server setValue:self.nameTextView.text forKey:@"displayName"];
    [self.server setValue:self.hostTextView.text forKey:@"host"];
    [self.server setValue:self.usernameTextView.text forKey:@"username"];
    [self.server setValue:self.passwordTextView.text forKey:@"password"];
    AppDelegate *appDelegate = [[UIApplication sharedApplication] delegate];
    NSManagedObjectContext *context = [appDelegate managedObjectContext];
    
    NSError *error;
    [context save:&error];
    
    [UIView 
     transitionWithView:self.navigationController.view
     duration:0.7
     options:UIViewAnimationOptionTransitionFlipFromLeft
     animations:^{ 
         [self.navigationController popViewControllerAnimated:NO];
     }
     completion:NULL];
}

- (void)dismissChanges
{
    [UIView 
     transitionWithView:self.navigationController.view
     duration:0.7
     options:UIViewAnimationOptionTransitionFlipFromRight
     animations:^{ 
         [self.navigationController popViewControllerAnimated:NO];
     }
     completion:NULL];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    [[NSBundle mainBundle] loadNibNamed:@"EditServerViewController" owner:self options:nil];
    
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemCancel target:self action:@selector(dismissChanges)];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemSave target:self action:@selector(saveChanges)];
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
    return 2;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    if(section == 0) return 2;
    if (section == 1) return 2;
    return 0;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
	
	NSString *sectionHeader = nil;
	
	if(section == 0) {
		sectionHeader = @"Server";
	}
	if(section == 1) {
		sectionHeader = @"Login information";
	}
	
	
	return sectionHeader;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"CellIdentifier";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {          
        switch (indexPath.section) {
            case 0:
                switch (indexPath.row) {
                    case 0:
                        cell = nameCell;
                        self.nameCell = nil;
                        break;
                        
                    case 1:
                        cell = hostCell;
                        self.hostCell = nil;
                        break;
                        
                    default:
                        break;
                }
                break;
                
            case 1:
                switch (indexPath.row) {
                    case 0:
                        cell = usernameCell;
                        self.usernameCell = nil;
                        break;
                        
                    case 1:
                        cell = passwordCell;
                        self.passwordCell = nil;
                        break;
                        
                    default:
                        break;
                }
                break;
            default:
                break;
        }
        
    }
    return cell;
}

/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:indexPath] withRowAnimation:UITableViewRowAnimationFade];
    }   
    else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath
{
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Navigation logic may go here. Create and push another view controller.
    /*
     <#DetailViewController#> *detailViewController = [[<#DetailViewController#> alloc] initWithNibName:@"<#Nib name#>" bundle:nil];
     // ...
     // Pass the selected object to the new view controller.
     [self.navigationController pushViewController:detailViewController animated:YES];
     */
}

@end
