#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint ezviz_flutter.podspec` to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'ezviz_flutter'
  s.version          = '0.0.1'
  s.summary          = 'A Flutter plugin for EZVIZ camera integration on macOS'
  s.description      = <<-DESC
A Flutter plugin for EZVIZ camera integration on macOS.
Note: EZVIZ does not provide a native SDK for macOS.
This implementation may use FFI to wrap the iOS SDK or fallback to REST APIs.
                       DESC
  s.homepage         = 'http://example.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Company' => 'email@example.com' }
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*'
  s.dependency 'FlutterMacOS'
  s.platform = :osx, '10.14'

  s.pod_target_xcconfig = { 
    'DEFINES_MODULE' => 'YES',
    'EXCLUDED_ARCHS[sdk=macosx*]' => 'i386'
  }
  s.swift_version = '5.0'
  
  # Ensure FlutterMacOS framework is available
  s.frameworks = 'AppKit', 'Foundation'

  # TODO: If using iOS SDK via FFI, uncomment and configure:
  # s.vendored_frameworks = [
  #   'Frameworks/EZOpenSDK.xcframework'
  # ]
  # Note: This requires the iOS SDK framework to be compatible with macOS
  # which may not be officially supported by EZVIZ
end

