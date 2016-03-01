#import <Cordova/CDV.h>
#import "CordovaKTPlay.h"

@implementation CordovaKTPlay

- (void)showCommunity:(CDVInvokedUrlCommand*)command
{
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end
