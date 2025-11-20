//
//  ezviz_player_view.h
//  ezviz_flutter
//
//  Platform view for EZVIZ video player on Windows
//  EZVIZ SDK v5.1.18 (C++) is required
//

#ifndef EZVIZ_PLAYER_VIEW_H_
#define EZVIZ_PLAYER_VIEW_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/platform_view.h>
#include <windows.h>
#include <memory>
#include <string>

// Include EZVIZ SDK headers
#include "OpenNetStreamInterFace.h"
#include "OpenNetStreamDefine.h"
#include "OpenNetStreamError.h"
#include "ezviz_manager.h"

namespace ezviz_flutter {

class EzvizPlayerView : public flutter::PlatformView {
 public:
  EzvizPlayerView(
      flutter::PluginRegistrarWindows* registrar,
      int view_id,
      flutter::MethodChannel<flutter::EncodableValue>* method_channel);

  ~EzvizPlayerView();

  // Get the native window handle
  HWND GetNativeView();

  // Initialize player with device info
  bool InitPlayerByDevice(const std::string& deviceSerial, int cameraNo);

  // Initialize player with URL
  bool InitPlayerByUrl(const std::string& url);

  // Initialize player with user info
  bool InitPlayerByUser(int userId, int cameraNo, int streamType);

  // Start real play
  bool StartRealPlay();

  // Stop real play
  bool StopRealPlay();

  // Start replay
  bool StartReplay(const std::string& startTime, const std::string& endTime);

  // Stop replay
  bool StopReplay();

  // Pause playback
  bool PausePlayback();

  // Resume playback
  bool ResumePlayback();

  // Release player
  void Release();

  // Set play verify code
  void SetPlayVerifyCode(const std::string& verifyCode);

  // Set play speed
  void SetPlaySpeed(float speed);

  // Seek playback
  void SeekPlayback(int position);

  // Get OSD time
  std::string GetOSDTime();

  // Get playback time
  int GetPlaybackTime();

  // Start local record
  bool StartLocalRecord(const std::string& filePath);

  // Stop local record
  bool StopLocalRecord();

  // Check if local recording
  bool IsLocalRecording();

  // Capture image
  std::string CaptureImage(const std::string& filePath);

 private:
  flutter::PluginRegistrarWindows* registrar_;
  int view_id_;
  flutter::MethodChannel<flutter::EncodableValue>* method_channel_;
  HWND native_view_;
  
  // EZVIZ SDK session
  std::string session_id_;
  std::string device_serial_;
  int camera_no_;
  bool is_playing_;
  
  // Message handler for SDK callbacks
  static void MessageHandler(const char* szSessionId, unsigned int iMsgType, 
                            unsigned int iErrorCode, const char* pMessageInfo, void* pUser);
};

}  // namespace ezviz_flutter

#endif  // EZVIZ_PLAYER_VIEW_H_

