# Guide d'Intégration - Support macOS et Windows

## 📋 Vue d'ensemble

Ce guide explique comment finaliser l'intégration des SDKs EZVIZ pour macOS et Windows dans le package `ezviz_flutter`.

## ✅ État actuel

- ✅ Structure de base créée pour macOS et Windows
- ✅ Code Dart adapté pour détecter macOS et Windows
- ✅ `pubspec.yaml` mis à jour
- ⚠️ SDKs EZVIZ à intégrer

## 🔧 Windows - Intégration du SDK EZVIZ v5.1.18

### Étape 1 : Télécharger le SDK

1. Accéder au portail développeur EZVIZ : https://open.ys7.com/
2. Télécharger le SDK Windows v4.3.6 (EZPCOpenSDK) - ~37 MB
3. Extraire le SDK dans `windows/third_party/ezviz_sdk/`

### Étape 2 : Configurer CMakeLists.txt

Modifier `windows/CMakeLists.txt` pour configurer les chemins du SDK :

```cmake
# Décommenter et configurer ces lignes :
set(EZVIZ_SDK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party/ezviz_sdk")
set(EZVIZ_INCLUDE_DIR "${EZVIZ_SDK_DIR}/include")
set(EZVIZ_LIB_DIR "${EZVIZ_SDK_DIR}/lib")
set(EZVIZ_BIN_DIR "${EZVIZ_SDK_DIR}/bin")

# Ajouter les includes
target_include_directories(ezviz_flutter_windows PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "${EZVIZ_INCLUDE_DIR}"
)

# Lier les bibliothèques
target_link_libraries(ezviz_flutter_windows PRIVATE
  flutter_wrapper_plugin
  "${EZVIZ_LIB_DIR}/EZOpenSDK.lib"
  # Ajouter d'autres bibliothèques nécessaires
)

# Copier les DLLs
add_custom_command(TARGET ezviz_flutter_windows POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${EZVIZ_BIN_DIR}/EZOpenSDK.dll" $<TARGET_FILE_DIR:ezviz_flutter_windows>
)
```

### Étape 3 : Implémenter les méthodes dans ezviz_manager.cpp

1. Inclure les headers du SDK EZVIZ dans `ezviz_manager.h` :
```cpp
#include "EZOpenSDK.h"
#include "EZPlayer.h"
// etc.
```

2. Implémenter les méthodes dans `ezviz_manager.cpp` en utilisant les APIs du SDK

3. Implémenter les méthodes du lecteur dans `ezviz_player_view.cpp`

### Étape 4 : Tester

```bash
flutter build windows
flutter run -d windows
```

## 🍎 macOS - Stratégies d'intégration

### Option 1 : Wrapper iOS SDK via FFI (Recommandé)

#### Étape 1 : Obtenir le SDK iOS

1. Le SDK iOS (`EZOpenSDK.xcframework`) est déjà disponible via CocoaPods
2. Copier le framework dans `macos/Frameworks/`

#### Étape 2 : Créer des bindings FFI

1. Créer `lib/src/ffi/ezviz_ffi_bindings.dart` :
```dart
import 'dart:ffi';
import 'package:ffi/ffi.dart';

// Bindings FFI pour le SDK iOS
```

2. Créer un wrapper C dans `macos/Classes/ezviz_ffi_wrapper.c` :
```c
// Wrapper C pour exposer les fonctions du SDK iOS
```

#### Étape 3 : Implémenter dans FlutterEzvizPlugin.swift

Utiliser les bindings FFI pour appeler les fonctions du SDK iOS

### Option 2 : Fallback API REST uniquement

Si l'Option 1 est trop complexe :

1. Les fonctionnalités REST fonctionnent déjà (via `ezviz_client.dart`)
2. Pour la lecture vidéo, utiliser un lecteur alternatif :
   - `video_player` : Lecteur vidéo Flutter standard
   - `flutter_vlc_player` : Lecteur VLC pour Flutter

3. Adapter `EzvizView.swift` pour utiliser le lecteur alternatif

### Option 3 : Utiliser le SDK iOS directement (Non testé)

1. Modifier `macos/ezviz_flutter.podspec` :
```ruby
s.vendored_frameworks = [
  'Frameworks/EZOpenSDK.xcframework'
]
```

2. **Note** : Le SDK iOS peut ne pas être compatible avec macOS. À tester.

## 📝 Checklist d'intégration

### Windows
- [ ] SDK EZVIZ v5.1.18 téléchargé et extrait
- [ ] `CMakeLists.txt` configuré avec les chemins du SDK
- [ ] Headers EZVIZ inclus dans les fichiers C++
- [ ] Méthodes implémentées dans `ezviz_manager.cpp`
- [ ] Méthodes du lecteur implémentées dans `ezviz_player_view.cpp`
- [ ] DLLs copiées dans le répertoire de sortie
- [ ] Tests effectués

### macOS
- [ ] Stratégie choisie (FFI, REST, ou SDK iOS direct)
- [ ] Si FFI : Bindings créés
- [ ] Si REST : Lecteur alternatif intégré
- [ ] Méthodes implémentées dans `FlutterEzvizPlugin.swift`
- [ ] Méthodes du lecteur implémentées dans `EzvizView.swift`
- [ ] Tests effectués

## 🐛 Dépannage

### Windows

**Erreur : DLL non trouvée**
- Vérifier que les DLLs sont copiées dans le répertoire de sortie
- Vérifier le chemin dans `CMakeLists.txt`

**Erreur : Bibliothèque non trouvée**
- Vérifier les chemins dans `CMakeLists.txt`
- Vérifier que les fichiers `.lib` sont présents

**Erreur de compilation**
- Vérifier que les headers EZVIZ sont inclus
- Vérifier la compatibilité des versions du SDK

### macOS

**Erreur : Framework non trouvé**
- Vérifier que le framework est dans `macos/Frameworks/`
- Vérifier la configuration dans `podspec`

**Erreur FFI**
- Vérifier que les bindings sont corrects
- Vérifier la compatibilité des architectures

## 📚 Ressources

- [EZVIZ Developer Portal](https://open.ys7.com/)
- [Flutter Desktop Support](https://docs.flutter.dev/development/platform-integration/desktop)
- [Flutter FFI](https://dart.dev/guides/libraries/c-interop)
- [CMake Documentation](https://cmake.org/documentation/)

## ⚠️ Notes importantes

1. **Windows** : Le SDK C++ est disponible et officiellement supporté
2. **macOS** : Pas de SDK natif, nécessite une stratégie alternative
3. **Compatibilité** : Tester soigneusement sur chaque plateforme
4. **Performance** : Les implémentations natives offriront de meilleures performances que les API REST

