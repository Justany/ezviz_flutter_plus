//
//  EzvizViewFactory.swift
//  ezviz_flutter
//
//  Platform view factory for EZVIZ video player on macOS
//  Note: This will need to use FFI wrapper or alternative video player
//

import Foundation
import FlutterMacOS
import AppKit

@objc
public class EzvizViewFactory: NSObject, FlutterPlatformViewFactory {
    private var messenger: FlutterBinaryMessenger
    
    @objc
    public init(messenger: FlutterBinaryMessenger) {
        self.messenger = messenger
        super.init()
    }
    
    @objc
    public func create(withFrame frame: CGRect, viewIdentifier viewId: Int64, arguments args: Any?) -> FlutterPlatformView {
        return EzvizView(messenger: messenger, viewId: viewId, frame: frame)
    }
    
    public func createArgsCodec() -> FlutterMessageCodec & NSObjectProtocol {
        return FlutterStandardMessageCodec.sharedInstance()
    }
}

