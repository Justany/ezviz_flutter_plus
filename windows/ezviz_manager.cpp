//
//  ezviz_manager.cpp
//  ezviz_flutter
//
//  EZVIZ SDK manager implementation for Windows
//  Using EZPCOpenSDK v4.3.6 (OpenNetStream)
//

#include "ezviz_manager.h"

#include <iostream>
#include <sstream>

namespace ezviz_flutter {

// Static callback handler
void EzvizManager::MessageCallback(const char* szSessionId, unsigned int iMsgType, 
                                   unsigned int iErrorCode, const char* pMessageInfo, void* pUser) {
  // This will be called by the SDK for various events
  // We need to forward this to Flutter via Event Channel
  // For now, just log it
  std::cout << "EZVIZ SDK Message: Session=" << (szSessionId ? szSessionId : "null")
            << ", Type=" << iMsgType << ", Error=" << iErrorCode << std::endl;
  
  // TODO: Forward to Flutter Event Channel
  // The pUser parameter can be used to identify which manager instance to use
}

EzvizManager::EzvizManager() : is_initialized_(false) {
  auth_addr_ = "https://openauth.ys7.com";
  platform_addr_ = "https://open.ys7.com";
}

EzvizManager::~EzvizManager() {
  Destroy();
}

bool EzvizManager::InitSDK(const std::map<std::string, std::string>& params) {
  if (is_initialized_) {
    return true;
  }

  // Extract parameters
  auto appKeyIt = params.find("appKey");
  auto accessTokenIt = params.find("accessToken");
  auto baseUrlIt = params.find("baseUrl");
  auto enableLogIt = params.find("enableLog");
  auto enableP2PIt = params.find("enableP2P");

  if (appKeyIt != params.end()) {
    app_key_ = appKeyIt->second;
  }

  if (baseUrlIt != params.end()) {
    // Use custom base URL for platform
    platform_addr_ = baseUrlIt->second;
    auth_addr_ = baseUrlIt->second;  // Usually same for auth
  }

  // Initialize OpenNetStream SDK
  OPENSDK_RESULT result = OpenSDK_InitLib(
    auth_addr_.c_str(),
    platform_addr_.c_str(),
    app_key_.c_str()
  );

  if (result != 0) {
    std::cerr << "Failed to initialize EZVIZ SDK: " << result << std::endl;
    return false;
  }

  // Set access token if provided
  if (accessTokenIt != params.end()) {
    access_token_ = accessTokenIt->second;
    OpenSDK_SetAccessToken(access_token_.c_str());
  }

  // Configure logging
  if (enableLogIt != params.end() && enableLogIt->second == "true") {
    // Set log level (assuming 1 = debug, adjust based on SDK docs)
    OpenSDK_SetConfigInfo(CONFIG_LOG_LEVEL, 1);
  }

  // Configure P2P
  if (enableP2PIt != params.end() && enableP2PIt->second == "false") {
    // Close P2P if disabled
    OpenSDK_SetConfigInfo(CONFIG_CLOSE_P2P, 1);
  }

  is_initialized_ = true;
  return true;
}

void EzvizManager::Destroy() {
  if (!is_initialized_) {
    return;
  }

  // Free all sessions
  for (auto& session : sessions_) {
    OpenSDK_FreeSession(session.first.c_str());
  }
  sessions_.clear();
  session_handlers_.clear();

  // Finalize SDK
  OpenSDK_FiniLib();

  is_initialized_ = false;
}

std::string EzvizManager::GetSDKVersion() {
  // OpenNetStream SDK doesn't provide a version function directly
  // Return the known version
  return "EZPCOpenSDK-v4.3.6";
}

void EzvizManager::EnableLog(bool enable) {
  if (!is_initialized_) {
    return;
  }
  
  // Set log level: 0 = none, 1 = error, 2 = warning, 3 = info, 4 = debug
  OpenSDK_SetConfigInfo(CONFIG_LOG_LEVEL, enable ? 4 : 0);
}

void EzvizManager::EnableP2P(bool enable) {
  if (!is_initialized_) {
    return;
  }
  
  // Close P2P if disabled, enable by default
  OpenSDK_SetConfigInfo(CONFIG_CLOSE_P2P, enable ? 0 : 1);
}

void EzvizManager::SetAccessToken(const std::string& accessToken) {
  access_token_ = accessToken;
  
  if (is_initialized_) {
    OpenSDK_SetAccessToken(access_token_.c_str());
  }
}

std::string EzvizManager::AllocSession(OpenSDK_MessageHandler handler, void* userData) {
  if (!is_initialized_) {
    return "";
  }

  // Allocate a session with the message handler
  char sessionId[64] = {0};
  OPENSDK_RESULT result = OpenSDK_AllocSession(sessionId, sizeof(sessionId), handler, userData);
  
  if (result == 0) {
    std::string session(sessionId);
    sessions_[session] = userData;
    session_handlers_[session] = handler;
    return session;
  }
  
  return "";
}

bool EzvizManager::FreeSession(const std::string& sessionId) {
  if (!is_initialized_ || sessions_.find(sessionId) == sessions_.end()) {
    return false;
  }

  OPENSDK_RESULT result = OpenSDK_FreeSession(sessionId.c_str());
  
  if (result == 0) {
    sessions_.erase(sessionId);
    session_handlers_.erase(sessionId);
    return true;
  }
  
  return false;
}

}  // namespace ezviz_flutter

