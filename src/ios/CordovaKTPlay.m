#import <Cordova/CDV.h>
#import "CordovaKTPlay.h"
#import "KTPlay.h"

@implementation CordovaKTPlay

- (void)init:(CDVInvokedUrlCommand*)command
{
    NSString *appid = [command.arguments objectAtIndex:0];
    NSString *appSecret [command.arguments objectAtIndex:1];
    [KTPlay startWithAppKey:appid appSecret:appSecret];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)showCommunity:(CDVInvokedUrlCommand*)command
{

    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end
