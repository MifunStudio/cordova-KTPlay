//
//  KTAppFrame.h
//  KTAppFrame
//
//  Created by Jayden Zhao on 15/3/30.
//  Copyright (c) 2015年 KTPlay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AvailabilityMacros.h>

//插屏通知状态
typedef enum{
    KTInterstitialNotificationWillAppear = 1, // 即将展现
    KTInterstitialNotificationDidCancel,    // 主动关闭（点击关闭按钮）
    KTInterstitialNotificationDidFinish     // 被动关闭
} KTInterstitialNotificationEvent;


@class KTUser;

@interface KTRewardItem : NSObject

/// 奖励名称
@property (nonatomic,copy) NSString * name;

/// 奖励ID
@property (nonatomic,copy) NSString * typeId;

/// 奖励值
@property (nonatomic) long long value;

@end


/**
 *    @brief    KTPlay奖励回调
 *    @param    rewards 奖励内容（KTRewardItem数组）
 *    @see      KTRewardItem
 */
typedef  void (^KTDidDispatchRewardsBlock)(NSArray * rewards);

/**
 *    @brief    打开KTPlay主窗口回调
 */
typedef  void (^KTViewDidAppearBlock)();

/**
 *    @brief    关闭KTPlay主窗口回调
 */
typedef  void (^KTViewDidDisappearBlock)();

/**
 *    @brief   用户新动态回调（新动态包含话题被回复，被称赞，有新的好友邀请等
 *    @param   hasNewActivity 有未读的新动态
 */

typedef  void (^KTActivityStatusChangedBlock)(BOOL hasNewActivity);

/**
 *    @brief   KTPlay SDK的可用状态变更回调
 *    @param   isEnabled 当前状态
 */
typedef  void (^KTAvailabilityChangedBlock)(BOOL isEnabled);


/**
 *    @brief   KTPlay SDK 深度链接回调
 *    @param   linkScheme 深度链接方案
 */
typedef void(^KTDeepLinkBlock)(NSString *linkScheme);


/**
 *    @brief   KTPlay SDK 强通知回调
 *    @param
 */
typedef void (^KTInterstitialNotificationBlock)(NSString *identifier,KTInterstitialNotificationEvent notificationEvent);

/**
 * KTPlay
 */
@interface KTPlay : NSObject



/**
 *  @brief 初始化 KTPlaySDK
 *  @param appKey KTPlay App Key，在KTPlay开发者网站新建应用后获取
 *  @param appSecret KTPlay App Secret，在KTPlay开发者网站新建应用后获取
 *
 *  startWithAppKey方法必须在游戏AppDelgate的didFinishLaunchingWithOptions方法中调用
 **/

+(void)startWithAppKey:(NSString *)appKey appSecret:(NSString *)appSecret;

/**
 *  @brief 设置用于显示KTPlay窗口的父容器
 *  @param parentView KTPlay窗口的父容器
 *
 *  默认情况下,KTPlay会使用[[[[UIApplication sharedApplication] keyWindow] rootViewController] view]作为父容器，
 */

+(void)setKTParentView:(UIView *)parentView __attribute__((deprecated("")));

/**
 *  @brief 打开KTPlay主窗口
 */
+(void)show;

/**
 *  @brief 关闭KTPlay主窗口
 *
 *  通常情况下不需要调用此方法，KTPlay窗口由玩家主动关闭
 */

+(void)dismiss;

/**
 *  @brief 分享图片/文本到KTPlay社区
 *  @param imagePath 图片的绝对路径,为nil时，不分享图片
 *  @param description 图片的描述,为nil时，没有默认内容描述
 */

+(void)shareImageToKT:(NSString *)imagePath description:(NSString *)description;

/**
 *  @brief 截取游戏当前画面并分享到KTPlay社区
 *  @param description 图片的描述
 */

+(void)shareScreenshotToKT:(NSString *)description;


/**
 *  @brief 设置监听者，监听奖励发放事件
 *  @param block KTPlay奖励回调
 */
+(void)setDidDispatchRewardsBlock:(KTDidDispatchRewardsBlock)block;


/**
 *  @brief 设置监听者，监听打开KTPlay主窗口事件
 *  @param block 打开KTPlay主窗口回调
 */

+(void)setViewDidAppearBlock:(KTViewDidAppearBlock)block;


/**
 *  @brief 设置监听者，监听关闭KTPlay主窗口事件
 *  @param block 关闭KTPlay主窗口回调
 */

+(void)setViewDidDisappearBlock:(KTViewDidDisappearBlock)block;


/**
 *  @brief 设置监听者，监听用户新动态
 *  @param block 用户新动态回调
 */
+(void)setActivityStatusChangedBlock:(KTActivityStatusChangedBlock)block;

/**
 *  @brief 设置监听者，监听KTPlay SDK的可用状态变更
 *  @param block KTPlay SDK的可用状态变更回调
 */

+(void)setAvailabilityChangedBlock:(KTAvailabilityChangedBlock)block;

/** @brief 设置监听者，监听DeepLink事件
 *
 */

+(void)setDeepLinkBlock:(KTDeepLinkBlock)block;
/**
 * @brief 判断KTplay是否可用
 * @return KTplay是否可用
 *
 *  KTPlay不可用的情况包括：<br/>
 *  1、设备不被支持<br/>
 *  2、在Portal上关闭 <br/>
 *  3、未获取到服务器配置信息（断网） <br/>
 */
+(BOOL)isEnabled;


/**
 * @brief 判断KTplay主窗口是否处于打开状态
 * @return KTplay主窗口是否打开
 *
 */

+(BOOL)isShowing;

/**
 * @brief 设置截图旋转角度
 * @param degrees 截图旋转角度（注意，是角度而不是弧度，取值如90,180等）
 *
 *
 * 通常不需要调用此方法，在截图角度不正常时（可能由游戏引擎或会游戏开发方式导致），再调用此方法进行调整
 */
+(void)setScreenshotRotation:(float)degrees;

/**
 *  @brief 处理SNS客户端返回的信息
 *  @param url AppDelegate的openURL方法中传入的url。
 *
 *
 *  为确保SNS（微信，QQ，新浪微博等）功能正确使用，请确保该方法在- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation中被调用
 *
 */
+(void)handleOpenURL:(NSURL *)url;


/**
 * @brief 启用/禁用通知功能
 * @param enabled YES/NO 启用/禁用
 *
 *
 */
+(void)setNotificationEnabled:(BOOL)enabled;


/** @brief 打开KTPlay礼包兑换窗口
 *
 */
+(void)showRedemptionView;


/** @brief 打开KTPlay强通知窗口（插屏通知窗口）
 *
 */
+(void)showInterstitialNotification:(NSString *)identifier  notificationBlock:(KTInterstitialNotificationBlock)block;


/** @brief 请求KTPlay指定内容插屏通知数据
 *
 */
+(void)requestInterstitialNotification:(NSString *)identifier;


/** @brief 本地是否包含指定插屏内容
 *
 */
+(BOOL)hasInterstitialNotification:(NSString *)identifier;

/**
 * 分享视频到KTplay社区
 * @param videoPath 要分享的视频文件地址（本地文件，不支持网络地址），如果为空则由玩家从本地视频中选择。
 * @param description 视频描述信息
 */
+(void) shareVideoToKT:(NSString*)videoPath description:(NSString*)description;

@end
