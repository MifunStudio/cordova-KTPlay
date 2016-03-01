#import <UIKit/UIKit.h>
#import <Cordova/CDVPlugin.h>

@interface CordovaKTPlay : CDVPlugin

- (void)init:(CDVInvokedUrlCommand*)command;
- (void)showLoginView:(CDVInvokedUrlCommand*)command;
- (void)showCommunity:(CDVInvokedUrlCommand*)command;

@end
