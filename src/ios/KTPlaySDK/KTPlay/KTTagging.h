//
//  KTTagging.h
//  kt239_sdk
//
//  Created by qinxuliang on 15/10/12.
//  Copyright © 2015年 KTplay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KTTagging : NSObject

/**
 * 记录游戏内付费请求。
 * @param orderId 付费订单号,必选。字符只支持数字、英文字母、下划线(_)和横线(-),最大不超过64个字符。
 * @param currencyType 货币类型，必选。ISO4217规范定义的货币代码，如CNY，USD。
 * @param currencyAmount 支付金额，必选。金额必须大于0。
 * @param productId 所购买商品ID，可选。最大不能超过32个字符。
 * @param productAmount 所购买商品数量，可选。
 * @param paymentChannel 支付渠道，如:AppStore,支付宝,微信，可选。最大不能超过16个字符。
 * @return 方法调用是否成功。如果参数中包含不符合格式的内容，会导致方法调用失败。
 */
+(BOOL)onChargeRequest:(NSString *)orderId currencyType:(NSString *)currencyType currencyAmount:(double)currencyAmount productId:(NSString *)productId productAmount:(long)productAmount paymentChannel:(NSString *)paymentChannel;

/**
 * 记录游戏内付费成功。
 * @param orderId 付费订单号,必选。字符只支持数字、英文字母、下划线(_)和横线(-),最大不超过64个字符。
 * @return 方法调用是否成功。如果参数中包含不符合格式的内容，会导致方法调用失败。
 */
+(BOOL)onChargeSuccess:(NSString*) orderId;

/**
 * 记录玩家开始游戏中的某一关卡
 * @param stage 关卡ID，取值范围1~1000。
 * @return 方法调用是否成功。如果参数中包含不符合格式的内容，会导致方法调用失败。
 */
+(BOOL)onStageStart:(NSInteger) stage;

/**
 * 记录玩家完成游戏中的某一关卡
 * @param stage 关卡ID，取值范围1~1000。
 * @param duration 玩家在关卡中耗费的时间。如果游戏已有现成数据，直接传入；如果没有传0，SDK会根据关卡开始时间计算出实际耗时，单位为秒。
 * @return 方法调用是否成功。如果参数中包含不符合格式的内容，会导致方法调用失败。
 */
+(BOOL) onStagePass:(NSInteger) stage duration:(long)duration;

/**
 * 记录玩家在游戏中的某一关卡失败
 * @param stage 关卡ID，取值范围1~1000。
 * @param duration 玩家在关卡中耗费的时间。如果游戏有现成的数据直接传入；如果没有传0，SDK会根据关卡开始时间计算出实际耗时，单位为秒。
 * @return 方法调用是否成功。如果参数中包含不符合格式的内容，会导致方法调用失败。
 */
+(BOOL) onStageFailed:(NSInteger) stage duration:(long)duration;

/**
 * 记录游戏角色升级
 * @param newLevel 游戏角色新级别，取值范围1~1000。
 * @param duration 玩家升级所耗费的时间。如果游戏有现成的数据直接传入；如果没有传0，SDK会根据等级开始时间计算出实际耗时，单位为秒。
 * @return 方法调用是否成功。如果参数中包含不符合格式的内容，会导致方法调用失败。
 */
+(BOOL) onLevelUp:(NSInteger) newLevel duration:(long)duration;

/**
 * 设置玩家信息
 * @param username 玩家昵称，可选。最大不超过64个字符。
 * @param age 玩家年龄 取值范围为0-120
 * @param gender 玩家性别.0-未知，1-男，2-女
 * @return 方法调用是否成功。如果参数中包含不符合格式的内容，会导致方法调用失败。
 */
+(BOOL) setUserProfile:(NSString*) username age:(NSInteger)age gender:(NSInteger)gender;

/**
 * 记录自定义键值
 * @param key 键，必选。字符只支持数字、英文字母、下划线(_)和横线(-),最大不超过32个字符
 * @param value 值，可选。如果为空则清除之前设置的值。
 * @return 方法调用是否成功。如果参数中包含不符合格式的内容，会导致方法调用失败。
 */
+(BOOL)setValue:(NSString*)key value:(NSString*)value;

/**
 * 记录自定义键值（数值型）
 * @param key 键，必选。字符只支持数字、英文字母、下划线(_)和横线(-),最大不超过32个字符。
 * @param value 值
 * @return 方法调用是否成功。如果参数中包含不符合格式的内容，会导致方法调用失败。
 */
+(BOOL)setNumericalValue:(NSString*)key value:(long)value;

@end
