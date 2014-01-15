/* Copyright (c) 2011 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

/// This class provides a way to make easy asynchronous requests to Google for
/// conversion or remarketing pings.
@interface GoogleConversionPing : NSObject

/// Supported conversion ping types.
typedef enum {
  kGoogleConversion,
  kDoubleClickConversion
} ConversionType;

/// Reports a conversion to Google.  Use the code as follows:
///   \code
///   [GoogleConversionPing pingWithConversionId:@"your id here"
///                                        label:@"your label here"
///                                        value:@"your app's price here"
///                                 isRepeatable:YES/NO];
///   \endcode
/// For example, to track downloads of your app, add the code to your
/// application delegate's application:didFinishLaunchingWithOptions: method.
+ (void)pingWithConversionId:(NSString *)conversionId
                       label:(NSString *)label
                       value:(NSString *)value
                isRepeatable:(BOOL)isRepeatable;

/// Reports a conversion to the ad network according to the type.  Use the code
/// as follows:
///   \code
///   [GoogleConversionPing
///        pingWithConversionId:@"your id here"
///                        type:kGoogleConversion/kDoubleClickConversion
///                       label:@"your label here"
///                       value:@"your app's price here"
///                isRepeatable:YES/NO];
///   \endcode
/// For example, to track downloads of your app, add the code to your
/// application delegate's application:didFinishLaunchingWithOptions: method.
/// Use this method only for the DFP (Doubleclick for Publishers) app conversion
/// tracking. To track Adwords and Admob conversions, please use
/// -pingWithConversionId:label:value:isRepeatable: which does not require the
/// conversion type.
+ (void)pingWithConversionId:(NSString *)conversionId
                        type:(ConversionType)type
                       label:(NSString *)label
                       value:(NSString *)value
                isRepeatable:(BOOL)isRepeatable;

/// Report a remarketing ping to Google.
+ (void)pingRemarketingWithConversionId:(NSString *)conversionId
                                  label:(NSString *)label
                             screenName:(NSString *)screenName
                       customParameters:(NSDictionary *)customParameters;

/// Register a click referrer from the Google ad click url.
+ (BOOL)registerReferrer:(NSURL *)clickUrl;

/// Returns the Google Conversion SDK version.
+ (NSString *)sdkVersion;

#pragma mark - Deprecated

/// UDID has been deprecated and this SDK only uses the IDFA as of version
/// 1.2.0. Setting the |idfaOnly| parameter is a no-op.
+ (void)pingWithConversionId:(NSString *)conversionId
                       label:(NSString *)label
                       value:(NSString *)value
                isRepeatable:(BOOL)isRepeatable
                    idfaOnly:(BOOL)idfaOnly DEPRECATED_ATTRIBUTE;

@end
