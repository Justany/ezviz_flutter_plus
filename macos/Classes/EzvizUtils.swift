//
//  EzvizUtils.swift
//  ezviz_flutter
//
//  Utility functions for EZVIZ on macOS
//

import Foundation

// Note: ezvizLog is defined in FlutterEzvizPlugin.swift to avoid duplication

// Date formatting utilities
func dateToStr(_ date: Date) -> String {
    let formatter = DateFormatter()
    formatter.dateFormat = "yyyy-MM-dd HH:mm:ss"
    return formatter.string(from: date)
}

func strToDate(_ str: String) -> Date? {
    let formatter = DateFormatter()
    formatter.dateFormat = "yyyy-MM-dd HH:mm:ss"
    return formatter.date(from: str)
}

// JSON utilities
func jsonToString(_ json: [String: Any]) -> String? {
    guard let data = try? JSONSerialization.data(withJSONObject: json, options: []) else {
        return nil
    }
    return String(data: data, encoding: .utf8)
}

func stringToJson(_ str: String) -> [String: Any]? {
    guard let data = str.data(using: .utf8) else {
        return nil
    }
    return try? JSONSerialization.jsonObject(with: data, options: []) as? [String: Any]
}

