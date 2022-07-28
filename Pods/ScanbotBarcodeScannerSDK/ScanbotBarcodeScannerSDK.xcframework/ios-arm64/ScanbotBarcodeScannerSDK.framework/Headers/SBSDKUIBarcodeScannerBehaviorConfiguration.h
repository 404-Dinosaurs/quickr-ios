//
//  SBSDKUIBarcodeScannerBehaviorConfiguration.h
//  ScanbotSDK
//
//  Created by Yevgeniy Knizhnik on 5/16/18.
//  Copyright © 2018 doo GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SBSDKBarcodeImageGenerationType.h"
#import "SBSDKBarcodeAdditionalParameters.h"
#import "SBSDKZoomRange.h"
#import "SBSDKBarcodeScanner.h"
#import "SBSDKUIBarcodeFiltering.h"

/**
 * Configuration for the behavior of  barcodes.
 */
@interface SBSDKUIBarcodeScannerBehaviorConfiguration : NSObject

/**
 * Specifies the way of barcode images generation or disables this generation at all.
 * Use, if you want to receive a full sized image with barcodes.
 * Defaults to SBSDKBarcodeImageGenerationTypeNone.
 */
@property (nonatomic, assign) SBSDKBarcodeImageGenerationType barcodeImageGenerationType;

/** Whether flash is toggled on or off. */
@property (nonatomic, assign, getter=isFlashEnabled) BOOL flashEnabled;

/** Whether scanner screen should make a sound on successful barcode detection. */
@property (nonatomic, assign, getter=isSuccessBeepEnabled) BOOL successBeepEnabled;

/**
 * Time in seconds until the screen is automatically cancelled.
 * Set to 0 to disable automatic cancellation. Defaults to 0 (disabled).
 * */
@property (nonatomic, assign) NSTimeInterval autoCancelTimeout;

/**
 * Additional parameters for tweaking the detection of barcodes.
 */
@property (nonatomic, strong, nonnull) SBSDKBarcodeAdditionalParameters *additionalParameters;

/**
 * The range of valid camera zoom factors. Default value is (1.0; 3.0).
 */
@property (nonatomic, strong, nonnull) SBSDKZoomRange *cameraZoomRange;

/**
 * The relative zoom level of the camera relative to `zoomRange`.
 * The minimum value is 0.0 (zoomed out), the maximum value is 1.0 (zoomed in).
 * The default value is 0.0, zoomed out.
 *
 * You can use this value to zoom the camera programmatically but also to set an initial zoom factor.
 */
@property (nonatomic, assign) CGFloat cameraZoomFactor;

/**
 * When this property is set to YES, the zoom can be activated by double tapping
 * somewhere in the receivers view.
 * The default value is YES.
 */
@property(nonatomic, assign, getter=isDoubleTapToZoomEnabled) BOOL doubleTapToZoomEnabled;

/**
 * When this property is set to YES, the zoom can be activated by a pinch gesture
 * somewhere in the receivers view.
 * The default value is YES.
 */
@property(nonatomic, assign, getter=isPinchToZoomEnabled) BOOL pinchToZoomEnabled;

/**
 * Defines, if zooming in or out should be animated.
 * The default value is YES;
 */
@property (nonatomic, assign) BOOL shouldAnimateZooming;

/**
 * The barcode detectors engine mode.
 * The default value is SBSDKBarcodeEngineModeNextGen.
 */
@property (nonatomic, assign) SBSDKBarcodeEngineMode engineMode;

/**
 * Additional filter to reject or accept barcode scanner results.
 * The default value is an instance of SBSDKUIBarcodeFilter.
 */
@property (nonatomic, strong, nonnull) SBSDKUIBarcodeFilter* barcodeFilter;

/**
 * Disables auto-focus and locks the lens at the specified focus lock lens position. The default value is NO.
 */
@property (nonatomic, assign, getter=isFocusLockEnabled) BOOL focusLockEnabled;

/**
 * The position of the lens. Values can be between 0.0f (minimum focusing distance) and
 * 1.0f (maximum focusing distance). The value will be clamped to [0.0f, 1.0f]. The default value is 0.0.
 */
@property (nonatomic, assign) CGFloat focusLockPosition;

@end
