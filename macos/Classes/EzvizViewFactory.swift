//
//  EzvizViewFactory.swift
//  ezviz_flutter
//
//  Platform view factory for EZVIZ video player on macOS
//  Note: This will need to use FFI wrapper or alternative video player
//  Note: FlutterMacOS Platform Views support may be limited
//  Currently, macOS uses a Container placeholder in Dart code
//

import Foundation
import FlutterMacOS
import AppKit

// For now, we'll keep the factory structure but it may not be used
// until FlutterMacOS fully supports Platform Views
@objc
public class EzvizViewFactory: NSObject {
    private var messenger: FlutterBinaryMessenger
    
    @objc
    public init(messenger: FlutterBinaryMessenger) {
        self.messenger = messenger
        super.init()
    }
}

