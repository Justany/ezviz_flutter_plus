//
//  EzvizModel.swift
//  ezviz_flutter
//
//  Data models for EZVIZ on macOS
//

import Foundation

// PTZ Action constants
let Action_START = "EZPTZAction_START"
let Action_STOP  = "EZPTZAction_STOP"
let Command_Left = "EZPTZCommand_Left"
let Command_Right = "EZPTZCommand_Right"
let Command_Up = "EZPTZCommand_Up"
let Command_Down = "EZPTZCommand_Down"
let Command_ZoomIn = "EZPTZCommand_ZoomIn"
let Command_ZoomOut = "EZPTZCommand_ZoomOut"

// TODO: If using iOS SDK via FFI, add extensions for EZDeviceInfo, etc.
// #if canImport(EZOpenSDKFramework)
// import EZOpenSDKFramework
//
// extension EZDeviceInfo {
//     func toJSON() -> [String: Any] {
//         return [
//             "deviceSerial": self.deviceSerial,
//             "deviceName": self.deviceName,
//             "isSupportPTZ": self.isSupportPTZ,
//             "cameraNum": self.cameraNum,
//         ]
//     }
// }
// #endif

// Device info model for REST API
struct EzvizDeviceInfo {
    let deviceSerial: String
    let deviceName: String
    let isSupportPTZ: Bool
    let cameraNum: Int
    
    func toJSON() -> [String: Any] {
        return [
            "deviceSerial": deviceSerial,
            "deviceName": deviceName,
            "isSupportPTZ": isSupportPTZ,
            "cameraNum": cameraNum,
        ]
    }
}

// Player status model
struct EzvizPlayerStatus {
    let status: Int
    let message: String?
    let errorCode: Int?
    
    func toJSON() -> [String: Any] {
        var json: [String: Any] = ["status": status]
        if let message = message {
            json["message"] = message
        }
        if let errorCode = errorCode {
            json["errorCode"] = errorCode
        }
        return json
    }
}

