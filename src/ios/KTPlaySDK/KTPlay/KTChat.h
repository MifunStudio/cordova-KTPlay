//
//  KTChat.h
//  kt239_sdk
//
//  Created by qinxuliang on 15/4/14.
//  Copyright (c) 2015年 KTplay. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef void (^KTChatOnGroupMessageChangedBlock)(NSString *groupId,NSInteger unreadCount);

@interface KTChat : NSObject


+(void)showGroupChatView:(NSString *)groupId;

+(void)addGroupMessageChangedCallback:(NSString*)groupId onGroupMessageChangedBlock:(KTChatOnGroupMessageChangedBlock)onGroupMessageChangedBlock;

+(void)removeGroupMessage:(NSString*)groupId;

@end
