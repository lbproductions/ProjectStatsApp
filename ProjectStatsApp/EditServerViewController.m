//
//  EditServerViewController.m
//  ServerView
//
//  Created by Niklas Wulf on 10.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import "ServerLoader.h"
#import "EditServerViewController.h"
#import "ServerTableViewController.h"

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
@synthesize delegate;

- (id)init
{
    self = [super initWithStyle:UITableViewStylePlain];
    if (self) {
        NSEntityDescription *entity = [NSEntityDescription entityForName:@"Server" inManagedObjectContext:[[ServerLoader instance] managedObjectContext]];
        self.server = [[NSManagedObject alloc] initWithEntity:entity insertIntoManagedObjectContext:nil];
        
        [self.server setValue:@"New Server" forKey:@"displayName"];
        isAddServer = true;
    }
    return self;
}

- (id)initWithServer:(NSManagedObject*)server
{
    self = [super initWithStyle:UITableViewStylePlain];
    if (self) {
        self.server = server;
        isAddServer = false;
    }
    return self;
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
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
    
    [self.delegate editServerViewController:self didSaveServer:self.server isAddServer:isAddServer];
}

- (void)dismissChanges
{
    [self.delegate editServerViewController:self didSaveServer:nil isAddServer:isAddServer];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    [[NSBundle mainBundle] loadNibNamed:@"EditServerViewController" owner:self options:nil];
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemCancel target:self action:@selector(dismissChanges)];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemSave target:self action:@selector(saveChanges)];
    [self configureView];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    
    self.server = nil;
    self.delegate = nil;
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

@end
