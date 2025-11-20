//
//  ezviz_flutter_plugin.h
//  ezviz_flutter
//
//  Flutter plugin for EZVIZ on Windows
//  EZVIZ SDK v5.1.18 (C++) is required
//

#ifndef EZVIZ_FLUTTER_PLUGIN_H_
#define EZVIZ_FLUTTER_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>
#include <memory>

#include "ezviz_manager.h"

namespace ezviz_flutter {

class EzvizFlutterPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  EzvizFlutterPlugin();
  virtual ~EzvizFlutterPlugin();

  // Disallow copy and assign.
  EzvizFlutterPlugin(const EzvizFlutterPlugin&) = delete;
  EzvizFlutterPlugin& operator=(const EzvizFlutterPlugin&) = delete;

 private:
  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);

  // Method channel for plugin communication
  std::unique_ptr<flutter::MethodChannel<flutter::EncodableValue>> method_channel_;

  // Event channel for plugin events
  std::unique_ptr<flutter::EventChannel<flutter::EncodableValue>> event_channel_;

  // Event sink for sending events to Dart
  std::unique_ptr<flutter::EventSink<flutter::EncodableValue>> event_sink_;

  // EZVIZ manager instance
  std::unique_ptr<EzvizManager> ezviz_manager_;
};

}  // namespace ezviz_flutter

#endif  // EZVIZ_FLUTTER_PLUGIN_H_

