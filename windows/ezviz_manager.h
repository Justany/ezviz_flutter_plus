//
//  ezviz_manager.h
//  ezviz_flutter
//
//  EZVIZ SDK manager for Windows
//  EZVIZ SDK v5.1.18 (C++) is required
//

#ifndef EZVIZ_MANAGER_H_
#define EZVIZ_MANAGER_H_

#include <string>
#include <memory>
#include <map>

// Include EZVIZ SDK headers
#include "OpenNetStreamInterFace.h"
#include "OpenNetStreamDefine.h"
#include "OpenNetStreamError.h"
#include <string>
#include <map>
#include <vector>

namespace ezviz_flutter {

class EzvizManager {
 public:
  EzvizManager();
  ~EzvizManager();

  // Disallow copy and assign.
  EzvizManager(const EzvizManager&) = delete;
  EzvizManager& operator=(const EzvizManager&) = delete;

  // Initialize SDK
  bool InitSDK(const std::map<std::string, std::string>& params);

  // Destroy SDK
  void Destroy();

  // Get SDK version
  std::string GetSDKVersion();

  // Enable/disable logging
  void EnableLog(bool enable);

  // Enable/disable P2P
  void EnableP2P(bool enable);

  // Set access token
  void SetAccessToken(const std::string& accessToken);

  // Session management
  std::string AllocSession(OpenSDK_MessageHandler handler, void* userData);
  bool FreeSession(const std::string& sessionId);

  // Get access token
  std::string GetAccessToken() const { return access_token_; }
  
  // Check if initialized
  bool IsInitialized() const { return is_initialized_; }

 private:
  bool is_initialized_;
  std::string app_key_;
  std::string access_token_;
  std::string auth_addr_;
  std::string platform_addr_;
  
  // Session management
  std::map<std::string, void*> sessions_;  // session_id -> user_data
  std::map<std::string, OpenSDK_MessageHandler> session_handlers_;
  
  // Message handler for SDK callbacks
  static void MessageCallback(const char* szSessionId, unsigned int iMsgType, 
                              unsigned int iErrorCode, const char* pMessageInfo, void* pUser);
};

}  // namespace ezviz_flutter

#endif  // EZVIZ_MANAGER_H_

