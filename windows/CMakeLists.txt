# CMakeLists.txt for ezviz_flutter Windows plugin
# EZVIZ SDK v5.1.18 (C++) is required
# Download from: https://open.ys7.com/ (EZVIZ Developer Portal)

cmake_minimum_required(VERSION 3.14)
project(ezviz_flutter_windows)

# Add Flutter library
add_subdirectory(flutter)

# Add plugin source files
add_library(ezviz_flutter_windows SHARED
  "ezviz_flutter_plugin.cpp"
  "ezviz_flutter_plugin.h"
  "ezviz_manager.cpp"
  "ezviz_manager.h"
  "ezviz_player_view.cpp"
  "ezviz_player_view.h"
)

# Configure EZVIZ SDK paths
# SDK version: EZPCOpenSDK v4.3.6 (international)
set(EZVIZ_SDK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party/ezviz_sdk/EZPCOpenSDK_v4.3.6.build20190428_international")
set(EZVIZ_INCLUDE_DIR "${EZVIZ_SDK_DIR}/inc")
set(EZVIZ_LIB_DIR "${EZVIZ_SDK_DIR}/lib/win32")
set(EZVIZ_BIN_DIR "${EZVIZ_SDK_DIR}/lib/win32")

# Include directories
target_include_directories(ezviz_flutter_windows PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "${EZVIZ_INCLUDE_DIR}"
)

# Link libraries - OpenNetStream is the main SDK library
target_link_libraries(ezviz_flutter_windows PRIVATE
  flutter_wrapper_plugin
  "${EZVIZ_LIB_DIR}/OpenNetStream.lib"
  "${EZVIZ_LIB_DIR}/NetStream.lib"
  "${EZVIZ_LIB_DIR}/PlayCtrl.lib"
  "${EZVIZ_LIB_DIR}/AudioIntercom.lib"
  "${EZVIZ_LIB_DIR}/SystemTransform.lib"
  "${EZVIZ_LIB_DIR}/hlog.lib"
  "${EZVIZ_LIB_DIR}/hpr.lib"
  "${EZVIZ_LIB_DIR}/libcurl.lib"
  "${EZVIZ_LIB_DIR}/libeay32.lib"
  "${EZVIZ_LIB_DIR}/ssleay32.lib"
  "${EZVIZ_LIB_DIR}/opensslwrap.lib"
  "${EZVIZ_LIB_DIR}/pthreadVC2.lib"
  "${EZVIZ_LIB_DIR}/udt.lib"
  "${EZVIZ_LIB_DIR}/streamclient_lib.lib"
  "${EZVIZ_LIB_DIR}/StunClientLib.lib"
  "${EZVIZ_LIB_DIR}/PushClient.lib"
  "${EZVIZ_LIB_DIR}/libCASClient.lib"
  "${EZVIZ_LIB_DIR}/libPPVClient2.lib"
  "${EZVIZ_LIB_DIR}/libGetHDSign.lib"
  "${EZVIZ_LIB_DIR}/paho-mqtt3c.lib"
  "${EZVIZ_LIB_DIR}/TTSClient.lib"
  "${EZVIZ_LIB_DIR}/MidPage.lib"
  "${EZVIZ_LIB_DIR}/AnalyzeData.lib"
  "${EZVIZ_LIB_DIR}/miniupnpc.lib"
)

# Copy EZVIZ DLLs to output directory
add_custom_command(TARGET ezviz_flutter_windows POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/OpenNetStream.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/NetStream.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/PlayCtrl.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/AudioIntercom.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/SystemTransform.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/hlog.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/hpr.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/libcurl.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/libeay32.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/ssleay32.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/opensslwrap.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/pthreadVC2.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/udt.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/streamclient_lib.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/StunClientLib.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/PushClient.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/libCASClient.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/libPPVClient2.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/libGetHDSign.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/paho-mqtt3c.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/TTSClient.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/MidPage.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/AnalyzeData.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/SuperRender.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/HXVA.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/MP_VIE.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/YUVProcess.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/AudioRender.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/OpenAL32.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
)

# Apply standard Windows settings
apply_standard_settings(ezviz_flutter_windows)

