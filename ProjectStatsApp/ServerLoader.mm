//
//  ServerLoader.m
//  ProjectStatsApp
//
//  Created by Niklas Wulf on 11.11.11.
//  Copyright (c) 2011 Technische Universität Dortmund. All rights reserved.
//

#import "ServerLoader.h"
#import "soapprojectstatsProxy.h"

@implementation ServerLoader

- (id) init
{
    if (self = [super init])
    {
    }
    return self;
}

- (void)repopulatePlayerList
{
    projectstatsProxy proxy;
    PlayerList playerList;
    proxy.playerList("127.0.0.1:1332","urn:projectstats:playerList",playerList);
    for(std::vector<PlayerInformation>::const_iterator it = playerList.playerList.begin(); it != playerList.playerList.end(); it++) {
        
        NSLog(@"id: %d, name:%s",it->id, it->name);
    }
}

@end
