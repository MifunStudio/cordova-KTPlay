#import <UIKit/UIKit.h>
#import <Cordova/CDVPlugin.h>

@interface CordovaKTPlay : CDVPlugin

- (void)init:(CDVInvokedUrlCommand*)command;
- (void)showCommunity:(CDVInvokedUrlCommand*)command;

@end
