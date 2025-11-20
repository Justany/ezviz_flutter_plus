//
//  ezviz_flutter_plugin.cpp
//  ezviz_flutter
//
//  Flutter plugin implementation for EZVIZ on Windows
//  EZVIZ SDK v5.1.18 (C++) is required
//

#include "ezviz_flutter_plugin.h"

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>
#include <memory>
#include <sstream>

#include "ezviz_manager.h"

namespace ezviz_flutter {

// Channel method names (matching Dart definitions)
namespace EzvizChannelMethods {
  constexpr char methodChannelName[] = "ezviz_flutter";
  constexpr char platformVersion[] = "getPlatformVersion";
  constexpr char initSDK[] = "initSDK";
  constexpr char sdkVersion[] = "getSdkVersion";
  constexpr char enableLog[] = "enableLog";
  constexpr char enableP2P[] = "enableP2P";
  constexpr char setAccessToken[] = "setAccessToken";
  constexpr char deviceInfo[] = "getDeviceInfo";
  constexpr char deviceInfoList[] = "getDeviceInfoList";
  constexpr char setVideoLevel[] = "setVideoLevel";
  constexpr char controlPTZ[] = "controlPTZ";
  constexpr char loginNetDevice[] = "loginNetDevice";
  constexpr char logoutNetDevice[] = "logoutNetDevice";
  constexpr char netControlPTZ[] = "netControlPTZ";
  constexpr char getDeviceList[] = "getDeviceList";
  constexpr char addDevice[] = "addDevice";
  constexpr char deleteDevice[] = "deleteDevice";
  constexpr char probeDeviceInfo[] = "probeDeviceInfo";
  constexpr char openLoginPage[] = "openLoginPage";
  constexpr char logout[] = "logout";
  constexpr char getAccessToken[] = "getAccessToken";
  constexpr char getAreaList[] = "getAreaList";
  constexpr char setServerUrl[] = "setServerUrl";
  constexpr char searchRecordFile[] = "searchRecordFile";
  constexpr char searchDeviceRecordFile[] = "searchDeviceRecordFile";
  constexpr char openSound[] = "openSound";
  constexpr char closeSound[] = "closeSound";
  constexpr char startVoiceTalk[] = "startVoiceTalk";
  constexpr char stopVoiceTalk[] = "stopVoiceTalk";
  constexpr char capturePicture[] = "capturePicture";
  constexpr char startRecording[] = "startRecording";
  constexpr char stopRecording[] = "stopRecording";
  constexpr char isRecording[] = "isRecording";
  constexpr char startConfigWifi[] = "startConfigWifi";
  constexpr char startConfigAP[] = "startConfigAP";
  constexpr char stopConfig[] = "stopConfig";
}

// Event channel names
namespace EzvizChannelEvents {
  constexpr char eventChannelName[] = "ezviz_flutter_event";
}

void EzvizFlutterPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel = std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
      registrar->messenger(), EzvizChannelMethods::methodChannelName,
      &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<EzvizFlutterPlugin>();
  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  // Register event channel
  auto event_channel = std::make_unique<flutter::EventChannel<flutter::EncodableValue>>(
      registrar->messenger(), EzvizChannelEvents::eventChannelName,
      &flutter::StandardMethodCodec::GetInstance());

  // TODO: Set up event stream handler
  // event_channel->SetStreamHandler(...);

  // Register platform view factory for video player
  // TODO: Register EzvizPlayerViewFactory

  registrar->AddPlugin(std::move(plugin));
}

EzvizFlutterPlugin::EzvizFlutterPlugin() {
  ezviz_manager_ = std::make_unique<EzvizManager>();
}

EzvizFlutterPlugin::~EzvizFlutterPlugin() {
  // Cleanup
  if (ezviz_manager_) {
    ezviz_manager_->Destroy();
  }
}

void EzvizFlutterPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
  
  const std::string& method = method_call.method_name();

  if (method == EzvizChannelMethods::platformVersion) {
    // Get Windows version
    OSVERSIONINFOEX osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    
    std::ostringstream version;
    version << "Windows ";
    if (GetVersionEx((OSVERSIONINFO*)&osvi)) {
      version << osvi.dwMajorVersion << "." << osvi.dwMinorVersion;
    }
    
    result->Success(flutter::EncodableValue(version.str()));
    
  } else if (method == EzvizChannelMethods::sdkVersion) {
    // Get EZVIZ SDK version
    std::string version = ezviz_manager_->GetSDKVersion();
    result->Success(flutter::EncodableValue(version));
    
  } else if (method == EzvizChannelMethods::initSDK) {
    // Initialize EZVIZ SDK
    auto args = std::get_if<flutter::EncodableMap>(method_call.arguments());
    if (args) {
      // Extract initialization parameters
      std::map<std::string, std::string> params;
      
      auto appKey = args->find(flutter::EncodableValue("appKey"));
      if (appKey != args->end()) {
        params["appKey"] = std::get<std::string>(appKey->second);
      }
      
      auto accessToken = args->find(flutter::EncodableValue("accessToken"));
      if (accessToken != args->end()) {
        params["accessToken"] = std::get<std::string>(accessToken->second);
      }
      
      auto baseUrl = args->find(flutter::EncodableValue("baseUrl"));
      if (baseUrl != args->end()) {
        params["baseUrl"] = std::get<std::string>(baseUrl->second);
      }
      
      auto enableLog = args->find(flutter::EncodableValue("enableLog"));
      if (enableLog != args->end()) {
        params["enableLog"] = std::get<bool>(enableLog->second) ? "true" : "false";
      }
      
      auto enableP2P = args->find(flutter::EncodableValue("enableP2P"));
      if (enableP2P != args->end()) {
        params["enableP2P"] = std::get<bool>(enableP2P->second) ? "true" : "false";
      }
      
      bool success = ezviz_manager_->InitSDK(params);
      flutter::EncodableMap response;
      response[flutter::EncodableValue("success")] = flutter::EncodableValue(success);
      response[flutter::EncodableValue("message")] = flutter::EncodableValue(
        success ? "SDK initialized" : "SDK initialization failed"
      );
      result->Success(flutter::EncodableValue(response));
    } else {
      result->Error("INVALID_ARGUMENT", "Invalid arguments for initSDK");
    }
    
  } else if (method == EzvizChannelMethods::enableLog) {
    // Enable logging
    auto args = std::get_if<flutter::EncodableMap>(method_call.arguments());
    if (args) {
      auto enableLog = args->find(flutter::EncodableValue("enableLog"));
      if (enableLog != args->end()) {
        bool enable = std::get<bool>(enableLog->second);
        ezviz_manager_->EnableLog(enable);
        result->Success();
      } else {
        result->Error("INVALID_ARGUMENT", "enableLog parameter missing");
      }
    } else {
      result->Error("INVALID_ARGUMENT", "Invalid arguments");
    }
    
  } else if (method == EzvizChannelMethods::enableP2P) {
    // Enable P2P
    auto args = std::get_if<flutter::EncodableMap>(method_call.arguments());
    if (args) {
      auto enableP2P = args->find(flutter::EncodableValue("enableP2P"));
      if (enableP2P != args->end()) {
        bool enable = std::get<bool>(enableP2P->second);
        ezviz_manager_->EnableP2P(enable);
        result->Success();
      } else {
        result->Error("INVALID_ARGUMENT", "enableP2P parameter missing");
      }
    } else {
      result->Error("INVALID_ARGUMENT", "Invalid arguments");
    }
    
  } else if (method == EzvizChannelMethods::setAccessToken) {
    // Set access token
    auto args = std::get_if<flutter::EncodableMap>(method_call.arguments());
    if (args) {
      auto accessToken = args->find(flutter::EncodableValue("accessToken"));
      if (accessToken != args->end()) {
        std::string token = std::get<std::string>(accessToken->second);
        ezviz_manager_->SetAccessToken(token);
        result->Success();
      } else {
        result->Error("INVALID_ARGUMENT", "accessToken parameter missing");
      }
    } else {
      result->Error("INVALID_ARGUMENT", "Invalid arguments");
    }
    
  } else if (method == EzvizChannelMethods::deviceInfo) {
    // TODO: Get device info
    result->Error("NOT_IMPLEMENTED", "Device info not yet implemented");
    
  } else if (method == EzvizChannelMethods::deviceInfoList) {
    // TODO: Get device list
    result->Success(flutter::EncodableValue(flutter::EncodableList()));
    
  } else if (method == EzvizChannelMethods::getDeviceList) {
    // TODO: Get device list
    result->Success(flutter::EncodableValue(flutter::EncodableList()));
    
  } else if (method == EzvizChannelMethods::addDevice) {
    // TODO: Add device
    result->Success(flutter::EncodableValue(false));
    
  } else if (method == EzvizChannelMethods::deleteDevice) {
    // TODO: Delete device
    result->Success(flutter::EncodableValue(false));
    
  } else if (method == EzvizChannelMethods::probeDeviceInfo) {
    // TODO: Probe device info
    result->Success();
    
  } else if (method == EzvizChannelMethods::openLoginPage) {
    // TODO: Open login page (may need web view on Windows)
    result->Success(flutter::EncodableValue(false));
    
  } else if (method == EzvizChannelMethods::logout) {
    // TODO: Logout
    result->Success(flutter::EncodableValue(false));
    
  } else if (method == EzvizChannelMethods::getAccessToken) {
    // TODO: Get access token
    result->Success();
    
  } else if (method == EzvizChannelMethods::getAreaList) {
    // TODO: Get area list
    result->Success(flutter::EncodableValue(flutter::EncodableList()));
    
  } else if (method == EzvizChannelMethods::setServerUrl) {
    // TODO: Set server URL
    result->Success(flutter::EncodableValue(false));
    
  } else if (method == EzvizChannelMethods::searchRecordFile) {
    // TODO: Search record files
    result->Success(flutter::EncodableValue(flutter::EncodableList()));
    
  } else if (method == EzvizChannelMethods::searchDeviceRecordFile) {
    // TODO: Search device record files
    result->Success(flutter::EncodableValue(flutter::EncodableList()));
    
  } else if (method == EzvizChannelMethods::controlPTZ) {
    // TODO: Control PTZ
    result->Error("NOT_IMPLEMENTED", "PTZ control not yet implemented");
    
  } else if (method == EzvizChannelMethods::loginNetDevice) {
    // TODO: Login net device
    result->Error("NOT_IMPLEMENTED", "Net device login not yet implemented");
    
  } else if (method == EzvizChannelMethods::logoutNetDevice) {
    // TODO: Logout net device
    result->Error("NOT_IMPLEMENTED", "Net device logout not yet implemented");
    
  } else if (method == EzvizChannelMethods::netControlPTZ) {
    // TODO: Net control PTZ
    result->Error("NOT_IMPLEMENTED", "Net PTZ control not yet implemented");
    
  } else if (method == EzvizChannelMethods::openSound) {
    // TODO: Open sound
    result->Success(flutter::EncodableValue(false));
    
  } else if (method == EzvizChannelMethods::closeSound) {
    // TODO: Close sound
    result->Success(flutter::EncodableValue(false));
    
  } else if (method == EzvizChannelMethods::startVoiceTalk) {
    // TODO: Start voice talk
    result->Success(flutter::EncodableValue(false));
    
  } else if (method == EzvizChannelMethods::stopVoiceTalk) {
    // TODO: Stop voice talk
    result->Success(flutter::EncodableValue(false));
    
  } else if (method == EzvizChannelMethods::capturePicture) {
    // TODO: Capture picture
    result->Success();
    
  } else if (method == EzvizChannelMethods::startRecording) {
    // TODO: Start recording
    result->Success(flutter::EncodableValue(false));
    
  } else if (method == EzvizChannelMethods::stopRecording) {
    // TODO: Stop recording
    result->Success(flutter::EncodableValue(false));
    
  } else if (method == EzvizChannelMethods::isRecording) {
    // TODO: Check recording status
    result->Success(flutter::EncodableValue(false));
    
  } else if (method == EzvizChannelMethods::startConfigWifi) {
    // TODO: Start WiFi config
    result->Success(flutter::EncodableValue(false));
    
  } else if (method == EzvizChannelMethods::startConfigAP) {
    // TODO: Start AP config
    result->Success(flutter::EncodableValue(false));
    
  } else if (method == EzvizChannelMethods::stopConfig) {
    // TODO: Stop config
    result->Success(flutter::EncodableValue(false));
    
  } else {
    result->NotImplemented();
  }
}

}  // namespace ezviz_flutter

