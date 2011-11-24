//
//  PlaceInfoViewController.h
//  ProjectStatsApp
//
//  Created by Niclas Raabe on 15.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>

@interface PlaceInfoViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>

-(id)init:(NSManagedObject*)place;
- (void)configureCell:(UITableViewCell *)cell atIndexPath:(NSIndexPath *)indexPath;
-(CLLocationCoordinate2D) addressLocation;

@property (strong, nonatomic) IBOutlet UILabel* streetName;
@property (strong, nonatomic) IBOutlet UILabel* townName;
@property (strong, nonatomic) IBOutlet NSManagedObject* m_place;
@property (strong, nonatomic) IBOutlet MKMapView* m_mapView;

@end
