# Analyse et Plan d'Action : Support macOS et Windows

## 📋 Vue d'ensemble du package

Le package `ezviz_flutter` est un plugin Flutter complet pour l'intégration des caméras EZVIZ. Il fournit :
- **Lecture vidéo en direct** (live streaming)
- **Contrôle PTZ** (Pan, Tilt, Zoom)
- **Gestion des appareils**
- **Audio/Intercom** (communication bidirectionnelle)
- **Enregistrement et captures d'écran**
- **Configuration Wi-Fi**
- **Gestion des alarmes**
- **Cloud storage**

## 🏗️ Architecture actuelle

### Plateformes supportées
- ✅ **Android** : Implémentation complète avec SDK natif
- ✅ **iOS** : Implémentation complète avec SDK natif
- ❌ **macOS** : Non supporté
- ❌ **Windows** : Non supporté
- ❌ **Web** : Non supporté (mentionné dans le code)

### Composants clés

#### 1. **Code Dart (Cross-platform)**
- `lib/src/ezviz_client.dart` : Client HTTP REST pour les API EZVIZ (fonctionne sur toutes les plateformes)
- `lib/src/` : Services REST (auth, device, live, ptz, alarm, etc.)
- `lib/widgets/` : Widgets Flutter (EzvizSimplePlayer, PTZ controls, etc.)

#### 2. **Code natif (Platform-specific)**
- **Android** (`android/`) :
  - `FlutterEzvizPlugin.kt` : Plugin principal avec Method Channels
  - `EzvizPlayerFactory.kt` : Factory pour Platform Views
  - SDK EZVIZ via Maven : `io.github.ezviz-open:ezviz-sdk:5.13`
  
- **iOS** (`ios/`) :
  - `FlutterEzvizPlugin.swift` : Plugin principal avec Method Channels
  - `EzvizViewFactory.swift` : Factory pour Platform Views
  - SDK EZVIZ via CocoaPods : `EZOpenSDK`

#### 3. **Communication Flutter ↔ Native**
- **Method Channels** : `ezviz_flutter` (méthodes principales)
- **Method Channels** : `ezviz_flutter_player_{id}` (contrôle du lecteur)
- **Event Channels** : `ezviz_flutter_event` (événements)
- **Event Channels** : `ezviz_flutter_player_event_{id}` (événements du lecteur)

#### 4. **Platform Views**
- Utilise `AndroidView` (Android) et `UiKitView` (iOS) pour afficher le lecteur vidéo natif
- Code Dart : `lib/ezviz_player.dart` (lignes 332-363)

## 🔍 Analyse des dépendances natives

### SDKs EZVIZ requis

#### Android
- **SDK** : `io.github.ezviz-open:ezviz-sdk:5.13` (Maven)
- **Bibliothèques natives** : `.so` files (armeabi-v7a, arm64-v8a)
- **Fonctionnalités** : Lecture vidéo, PTZ, audio, enregistrement

#### iOS
- **SDK** : `EZOpenSDK` (CocoaPods)
- **Frameworks** : `EZOpenSDKFramework.framework`, `EZOpenSDK.xcframework`
- **Fonctionnalités** : Lecture vidéo, PTZ, audio, enregistrement

### ✅ Disponibilité des SDKs EZVIZ (Vérifié)

**Résultat de la vérification officielle** :

| Plateforme | Version | Disponibilité | Format |
|------------|---------|---------------|--------|
| Android | v5.7 | ✅ Disponible | Maven + .so files |
| iOS | v5.7 | ✅ Disponible | CocoaPods + xcframework |
| **Windows** | **v4.3.6** | **✅ Disponible** | **SDK natif C++ (EZPCOpenSDK, ~37 MB)** |
| **macOS** | - | **❌ Non disponible** | - |

**Conclusion** :
- ✅ **Windows** : SDK C++ disponible → Implémentation native possible
- ❌ **macOS** : Pas de SDK natif → Nécessite une stratégie alternative

**Stratégies pour macOS** :
1. **Option 1 (Recommandée)** : Wrapper du SDK iOS via Dart FFI
   - Le framework `EZOpenSDK.xcframework` iOS est universel
   - Flutter supporte la liaison C/C++ native sur macOS via `dart:ffi`
   - Nécessite du reverse-engineering du framework iOS
   
2. **Option 2** : Fallback sur API REST uniquement
   - Fonctionnalités REST disponibles (auth, device management, etc.)
   - Pas de lecture vidéo native (nécessiterait un lecteur alternatif)
   
3. **Option 3** : Utiliser un lecteur vidéo alternatif
   - `video_player` ou `flutter_vlc_player` pour la lecture
   - Contrôles PTZ via API REST si disponibles

## 📝 Plan d'action pour macOS

### ⚠️ Contrainte : Pas de SDK natif EZVIZ pour macOS

**Stratégie choisie** : Wrapper du SDK iOS via Dart FFI (Option 1)

### Phase 1 : Préparation
1. ✅ Vérifier la disponibilité du SDK EZVIZ pour macOS → ❌ Non disponible
2. ✅ Créer la structure de dossiers `macos/`
3. ✅ Configurer le `pubspec.yaml` pour déclarer le support macOS

### Phase 2 : Implémentation alternative macOS

#### Option A : Wrapper iOS SDK via FFI (Recommandé)
1. **Créer le plugin Swift avec FFI** :
   - `macos/Classes/FlutterEzvizPlugin.swift` : Plugin principal
   - `macos/Classes/EzvizFFIWrapper.swift` : Wrapper FFI pour le SDK iOS
   - `macos/Classes/EzvizManager.swift` : Gestionnaire EZVIZ
   - `macos/Classes/EzvizViewFactory.swift` : Factory pour Platform Views
   - `macos/Classes/EzvizView.swift` : Vue native pour le lecteur

2. **Intégrer le SDK iOS via FFI** :
   - Utiliser `EZOpenSDK.xcframework` (framework iOS universel)
   - Créer des bindings Dart FFI dans `lib/src/ffi/ezviz_ffi_bindings.dart`
   - Wrapper Swift pour exposer les fonctions C nécessaires

3. **Implémenter les Method Channels** :
   - Toutes les méthodes définies dans `EzvizChannelMethods`
   - Toutes les méthodes définies dans `EzvizPlayerChannelMethods`
   - Utiliser FFI pour appeler les fonctions natives

4. **Implémenter les Event Channels** :
   - `EzvizChannelEvents`
   - `EzvizPlayerChannelEvents`

#### Option B : Fallback API REST (Alternative)
Si l'Option A est trop complexe :
- Utiliser uniquement les API REST (déjà fonctionnelles)
- Implémenter un lecteur vidéo alternatif (`video_player` ou `flutter_vlc_player`)
- Contrôles PTZ via API REST

### Phase 3 : Adaptation du code Dart
1. **Mettre à jour `lib/ezviz_player.dart`** :
   - ✅ Détection de macOS ajoutée
   - Utiliser Platform View macOS ou fallback selon l'option choisie

2. **Tests** :
   - Tester toutes les fonctionnalités sur macOS
   - Vérifier la compatibilité avec les widgets existants

## 📝 Plan d'action pour Windows

### ✅ SDK EZVIZ Windows disponible (v4.3.6 - EZPCOpenSDK)

**Stratégie** : Implémentation native directe avec SDK C++

### Phase 1 : Préparation
1. ✅ Vérifier la disponibilité du SDK EZVIZ pour Windows → ✅ Disponible (v4.3.6)
2. ✅ Créer la structure de dossiers `windows/`
3. ✅ Configurer le `pubspec.yaml` pour déclarer le support Windows

### Phase 2 : Implémentation native Windows
1. **Télécharger et intégrer le SDK EZVIZ Windows** :
   - Télécharger le SDK v4.3.6 (EZPCOpenSDK) depuis le portail EZVIZ (~37 MB)
   - Extraire les DLL, headers et bibliothèques
   - Placer dans `windows/third_party/ezviz_sdk/`

2. **Créer le plugin C++** :
   - `windows/ezviz_flutter_plugin.cpp` : Plugin principal (C++)
   - `windows/ezviz_flutter_plugin.h` : Headers
   - `windows/ezviz_player_view.cpp` : Vue native pour le lecteur (HWND)
   - `windows/ezviz_player_view.h` : Headers
   - `windows/ezviz_manager.cpp` : Gestionnaire EZVIZ
   - `windows/ezviz_manager.h` : Headers

3. **Configurer CMakeLists.txt** :
   - Ajouter les chemins vers le SDK EZVIZ
   - Lier les bibliothèques nécessaires
   - Configurer les dépendances

4. **Implémenter les Method Channels** :
   - Toutes les méthodes définies dans `EzvizChannelMethods`
   - Toutes les méthodes définies dans `EzvizPlayerChannelMethods`
   - Utiliser les APIs du SDK EZVIZ Windows

5. **Implémenter les Event Channels** :
   - `EzvizChannelEvents`
   - `EzvizPlayerChannelEvents`
   - Callbacks du SDK EZVIZ vers Event Channels

### Phase 3 : Adaptation du code Dart
1. **Mettre à jour `lib/ezviz_player.dart`** :
   - ✅ Détection de Windows ajoutée
   - Utiliser Platform View Windows pour le lecteur vidéo

2. **Tests** :
   - Tester toutes les fonctionnalités sur Windows
   - Vérifier la compatibilité avec les widgets existants

## 🎯 Stratégie de fallback

Si les SDKs natifs ne sont pas disponibles pour macOS/Windows :

### Option 1 : API REST uniquement
- ✅ Fonctionnalités REST : Auth, Device Management, Cloud Storage
- ❌ Pas de lecture vidéo native (nécessiterait un lecteur web/HTML5)
- ❌ Pas de PTZ natif (nécessiterait des API REST si disponibles)

### Option 2 : Lecteur vidéo alternatif
- Utiliser `video_player` ou `flutter_vlc_player` pour la lecture
- Adapter les flux vidéo EZVIZ pour ces lecteurs
- Implémenter les contrôles PTZ via API REST

## 📦 Structure de fichiers à créer

### macOS
```
macos/
├── Classes/
│   ├── FlutterEzvizPlugin.swift
│   ├── EzvizManager.swift
│   ├── EzvizViewFactory.swift
│   ├── EzvizView.swift
│   ├── EzvizModel.swift
│   └── EzvizUtils.swift
├── Resources/
│   └── PrivacyInfo.xcprivacy
└── ezviz_flutter.podspec
```

### Windows
```
windows/
├── CMakeLists.txt
├── ezviz_flutter_plugin.cpp
├── ezviz_flutter_plugin.h
├── ezviz_player_view.cpp
├── ezviz_player_view.h
├── ezviz_manager.cpp
├── ezviz_manager.h
└── runner/
    └── main.cpp (si nécessaire)
```

## ✅ Checklist de validation

### macOS
- [ ] SDK EZVIZ disponible et intégré
- [ ] Plugin Swift créé et fonctionnel
- [ ] Method Channels implémentés
- [ ] Event Channels implémentés
- [ ] Platform View pour le lecteur vidéo
- [ ] Code Dart adapté pour macOS
- [ ] Tests unitaires passent
- [ ] Tests d'intégration passent
- [ ] Documentation mise à jour

### Windows
- [ ] SDK EZVIZ disponible et intégré
- [ ] Plugin C++ créé et fonctionnel
- [ ] Method Channels implémentés
- [ ] Event Channels implémentés
- [ ] Platform View pour le lecteur vidéo
- [ ] Code Dart adapté pour Windows
- [ ] Tests unitaires passent
- [ ] Tests d'intégration passent
- [ ] Documentation mise à jour

## 🔗 Ressources

- [Flutter Desktop Support](https://docs.flutter.dev/development/platform-integration/desktop)
- [Flutter Platform Channels](https://docs.flutter.dev/development/platform-integration/platform-channels)
- [Flutter Platform Views](https://docs.flutter.dev/development/platform-integration/platform-views)
- [EZVIZ Developer Documentation](https://open.ys7.com/)

## 📝 Notes importantes

1. **SDKs EZVIZ** : La première étape critique est de vérifier si EZVIZ fournit des SDKs pour macOS et Windows. Sans SDKs natifs, certaines fonctionnalités (lecture vidéo, PTZ natif) ne seront pas disponibles.

2. **Platform Views** : macOS et Windows supportent les Platform Views dans Flutter, mais l'implémentation diffère d'Android/iOS.

3. **API REST** : Les fonctionnalités basées sur les API REST (via `ezviz_client.dart`) fonctionnent déjà sur toutes les plateformes sans modification.

4. **Compatibilité** : Il faut s'assurer que les nouvelles plateformes n'affectent pas le fonctionnement existant sur Android et iOS.

