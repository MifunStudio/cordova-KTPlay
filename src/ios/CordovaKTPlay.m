#import <Cordova/CDV.h>
#import "CordovaKTPlay.h"
#import "KTPlay.h"
#import "KTAccountManager.h"

@implementation CordovaKTPlay

- (void)init:(CDVInvokedUrlCommand*)command
{
    NSString *appid = [command.arguments objectAtIndex:0];
    NSString *appSecret = [command.arguments objectAtIndex:1];
    [KTPlay startWithAppKey:appid appSecret:appSecret];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)showLoginView:(CDVInvokedUrlCommand*)command
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [KTAccountManager showLoginView:NO success:^(KTUser * account) {
            CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
        } failure:^(NSError *error) {
            NSString *errMsg = [error localizedDescription];
            CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:errMsg];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
        }];
    });
}

- (void)showCommunity:(CDVInvokedUrlCommand*)command
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [KTPlay show];
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    });
}

@end
