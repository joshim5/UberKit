//
//  UberKit.h
//  UberKit
//
// Created by Sachin Kesiraju on 8/20/14.
// Copyright (c) 2014 Sachin Kesiraju
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "NXOAuth2.h"
#import "UberProduct.h"
#import "UberPrice.h"
#import "UberTime.h"
#import "UberActivity.h"
#import "UberProfile.h"

@class UberKit;

@protocol UberKitDelegate <NSObject>
@optional
- (void) uberKit: (UberKit *) uberKit didReceiveAccessToken: (NSString *) accessToken refreshToken: (NSString *) accessToken;
- (void) uberKit: (UberKit *) uberKit loginFailedWithError: (NSError *) error;

@end

typedef void (^CompletionHandler) (NSArray *resultsArray, NSURLResponse *response, NSError *error);
typedef void (^ProfileHandler) (UberProfile *profile, NSURLResponse *response, NSError *error);

@interface UberKit : NSObject

@property (strong, nonatomic) NSString *serverToken;
@property (strong, nonatomic) NSString *clientID;
@property (strong, nonatomic) NSString *clientSecret;
@property (strong, nonatomic) NSString *redirectURL;
@property (strong, nonatomic) NSString *applicationName;

@property (weak, nonatomic) UIViewController <UberKitDelegate, UIWebViewDelegate> *delegate;

+ (UberKit *) sharedInstance;

#pragma mark - Initialization

- (instancetype) initWithServerToken: (NSString *) serverToken;
- (instancetype) initWithClientID: (NSString *) clientId ClientSecret: (NSString *) clientSecret RedirectURL: (NSString *) redirectURL ApplicationName: (NSString *) applicationName;
- (void) tokenReset;

#pragma mark - Login

- (void) startLogin;
- (NSString *) getStoredAuthToken;

#pragma mark - Product Types

- (void) getProductsForLocation: (CLLocation *) location withCompletionHandler: (CompletionHandler) completion;

# pragma mark - Place Lookups

- (void) getPlacesWithCompletionHandler:(void (^)(NSString*, NSString*))completion;

#pragma mark - Price Estimates

- (void) getPriceForUberPOOLWithStartLocation:(CLLocation *)startLocation endLocation:(CLLocation *)endLocation seatCount:(int)seatCount withCompletionHandler:(void (^)(UberPrice*))completion;

- (void) getPriceForTripWithStartLocation: (CLLocation *) startLocation endLocation:(CLLocation *) endLocation withCompletionHandler: (CompletionHandler) completion;

#pragma mark - Time Estimates

- (void) getTimeForProductArrivalWithLocation: (CLLocation *) location withCompletionHandler: (CompletionHandler) completion;

#pragma mark - User Activity

- (void) getUserActivityWithCompletionHandler:(CompletionHandler) completion;

#pragma mark - User Profie

- (void) getUserProfileWithCompletionHandler: (ProfileHandler) handler;

#pragma mark - Deep Linking

- (void) openUberApp;

#pragma mark - Hack around for WebView
- (BOOL) redirectWebView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;
- (void) redirectWebView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;
- (void) redirectWebViewDidFinishLoad:(UIWebView *)webView;

@end
