//
//  EzvizChannelNames.swift
//  ezviz_flutter
//
//  Channel names and method definitions for macOS platform
//  Note: macOS does not have a native EZVIZ SDK, so this implementation
//  may need to use FFI to wrap the iOS SDK or fallback to REST APIs
//

import Foundation

// 插件方法名称定义
class EzvizChannelMethods {
    /// 插件入口名称
    static let methodChannelName = "ezviz_flutter";
    /// 获取平台版本号 测试通路使用
    static let platformVersion = "getPlatformVersion";
    /// 初始化SDK
    static let initSDK = "initSDK";
    /// 获取SDK版本号
    static let sdkVersion = "getSdkVersion";
    /// 是否开启日志
    static let enableLog = "enableLog";
    /// 是否开启P2P
    static let enableP2P = "enableP2P";
    /// 设置accessToken
    static let setAccessToken = "setAccessToken";
    /// 获取设备信息
    static let deviceInfo = "getDeviceInfo";
    /// 获取设备信息列表
    static let deviceInfoList = "getDeviceInfoList";
    /// 设置视频通道清晰度
    static let setVideoLevel = "setVideoLevel";
    /// 云台控制
    static let controlPTZ = "controlPTZ";
    /// 登录网络设备
    static let loginNetDevice = "loginNetDevice";
    /// 登出网络设备
    static let logoutNetDevice = "logoutNetDevice";
    /// NetDevice 云台控制
    static let netControlPTZ = "netControlPTZ";
    /// 获取设备列表 (with pagination)
    static let getDeviceList = "getDeviceList";
    /// 添加设备
    static let addDevice = "addDevice";
    /// 删除设备
    static let deleteDevice = "deleteDevice";
    /// 探测设备信息
    static let probeDeviceInfo = "probeDeviceInfo";
    /// 打开登录页面
    static let openLoginPage = "openLoginPage";
    /// 登出
    static let logout = "logout";
    /// 获取访问令牌
    static let getAccessToken = "getAccessToken";
    /// 获取区域列表
    static let getAreaList = "getAreaList";
    /// 设置服务器URL
    static let setServerUrl = "setServerUrl";
    /// 搜索录像文件
    static let searchRecordFile = "searchRecordFile";
    /// 搜索设备录像文件
    static let searchDeviceRecordFile = "searchDeviceRecordFile";
    /// 开启声音
    static let openSound = "openSound";
    /// 关闭声音
    static let closeSound = "closeSound";
    /// 开始对讲
    static let startVoiceTalk = "startVoiceTalk";
    /// 停止对讲
    static let stopVoiceTalk = "stopVoiceTalk";
    /// 截屏
    static let capturePicture = "capturePicture";
    /// 开始录像
    static let startRecording = "startRecording";
    /// 停止录像
    static let stopRecording = "stopRecording";
    /// 获取录像状态
    static let isRecording = "isRecording";
    /// Wi-Fi配网
    static let startConfigWifi = "startConfigWifi";
    /// 热点配网
    static let startConfigAP = "startConfigAP";
    /// 停止配网
    static let stopConfig = "stopConfig";
}

// 插件事件名称定义
class EzvizChannelEvents {
    /// 插件event入口名称
    static let eventChannelName = "ezviz_flutter_event";
    /// 播放器状态事件
    static let playerStatusChange = "playerStatusChange";
    /// 对讲错误事件
    static let talkError = "talkError";
    /// Wi-Fi配网结果事件
    static let wifiConfigResult = "wifiConfigResult";
    /// 设备添加结果事件
    static let deviceAddResult = "deviceAddResult";
    /// 设备状态变化事件
    static let deviceStatusChange = "deviceStatusChange";
    /// 推送消息事件
    static let pushMessageReceived = "pushMessageReceived";
    /// 录像搜索结果事件
    static let recordSearchResult = "recordSearchResult";
}

// 插件播放器方法名称定义
class EzvizPlayerChannelMethods {
    /// 插件播放器入口名称
    static let methodChannelName = "ezviz_flutter_player";
    /// 初始化播放器设备(设备信息)
    static let initPlayerByDevice = "initPlayerByDevice";
    /// 初始化播放器设备(Url)
    static let initPlayerUrl = "initPlayerUrl";
    /// 初始化播放器设备(用户信息)
    static let initPlayerByUser = "initPlayerByUser";
    /// 开始直播
    static let startRealPlay = "startRealPlay";
    /// 结束直播
    static let stopRealPlay = "stopRealPlay";
    /// 开始回播
    static let startReplay = "startReplay";
    /// 结束回播
    static let stopReplay = "stopReplay";
    /// 暂停回放
    static let pausePlayback = "pausePlayback";
    /// 恢复回放
    static let resumePlayback = "resumePlayback";
    /// 释放播放器
    static let playerRelease = "playerRelease";
    /// 设置播放密码
    static let setPlayVerifyCode = "setPlayVerifyCode";
    /// 设置播放速度
    static let setPlaySpeed = "setPlaySpeed";
    /// 拖动播放进度
    static let seekPlayback = "seekPlayback";
    /// 获取OSD时间
    static let getOSDTime = "getOSDTime";
    /// 获取播放进度
    static let getPlaybackTime = "getPlaybackTime";
    /// 设置播放窗口
    static let setPlayWindow = "setPlayWindow";
    /// 开始本地录像
    static let startLocalRecord = "startLocalRecord";
    /// 停止本地录像
    static let stopLocalRecord = "stopLocalRecord";
    /// 是否在本地录像
    static let isLocalRecording = "isLocalRecording";
    /// 截取图片
    static let captureImage = "captureImage";
    /// 缩放播放窗口
    static let scalePlayWindow = "scalePlayWindow";
}

// 插件播放器事件名称定义
class EzvizPlayerChannelEvents {
    /// 插件event入口名称
    static let eventChannelName = "ezviz_flutter_player_event";
    /// 播放器状态事件
    static let playerStatusChange = "playerStatusChange";
}

