// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This header is available in the Test module. Import via "@import camera.Test;"

#import <camera/CameraPlugin.h>
#import <camera/FLTThreadSafeFlutterResult.h>

/// Methods exposed for unit testing.
@interface CameraPlugin ()

// All FLTCam's state access and capture session related operations should be on run on this queue.
@property(nonatomic, strong) dispatch_queue_t captureSessionQueue;

/// Inject @p FlutterTextureRegistry and @p FlutterBinaryMessenger for unit testing.
- (instancetype)initWithRegistry:(NSObject<FlutterTextureRegistry> *)registry
                       messenger:(NSObject<FlutterBinaryMessenger> *)messenger
    NS_DESIGNATED_INITIALIZER;

/// Hide the default public constructor.
- (instancetype)init NS_UNAVAILABLE;

/// Handles `FlutterMethodCall`s and ensures result is send on the main dispatch queue.
///
/// @param call The method call command object.
/// @param result A wrapper around the `FlutterResult` callback which ensures the callback is called
/// on the main dispatch queue.
- (void)handleMethodCallAsync:(FlutterMethodCall *)call result:(FLTThreadSafeFlutterResult *)result;

/// Called by the @c NSNotificationManager each time the device's orientation is changed.
///
/// @param notification @c NSNotification instance containing a reference to the `UIDevice` object
/// that triggered the orientation change.
- (void)orientationChanged:(NSNotification *)notification;

@end
