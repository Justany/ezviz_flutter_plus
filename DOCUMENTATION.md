# 📚 Documentation - ezviz_flutter_plus

## 🔗 Repository GitHub

**URL** : https://github.com/Justany/ezviz_flutter_plus

## 📦 Installation

### Depuis GitHub

```yaml
# pubspec.yaml
dependencies:
  ezviz_flutter_plus:
    git:
      url: https://github.com/Justany/ezviz_flutter_plus.git
      ref: main  # ou v1.2.7 pour une version spécifique
```

```bash
flutter pub get
```

**Important** : Le package s'appelle `ezviz_flutter` dans le code Dart, même si la dépendance s'appelle `ezviz_flutter_plus`.

```dart
import 'package:ezviz_flutter/ezviz_flutter.dart';
```

## 🧪 Tests

```bash
# Tests unitaires
flutter test

# Analyse du code
flutter analyze  # ✅ Aucune erreur

# Tester via l'exemple
cd example
flutter pub get
flutter run -d windows  # ou macos, android, ios
```

## 🚀 Déploiement sur GitHub

### Commandes rapides

```bash
# 1. Vérifier l'état
git status

# 2. Ajouter les fichiers
git add .

# 3. Commit
git commit -m "feat: Add Windows and macOS support with EZPCOpenSDK integration"

# 4. Pousser
git push origin main

# 5. Créer un tag
git tag -a v1.2.7 -m "Version 1.2.7 - Windows and macOS support"
git push origin v1.2.7
```

## 🪟 Support Windows

**SDK** : EZPCOpenSDK v4.3.6 (~37 MB compressé, ~130 MB décompressé)

Le SDK est inclus dans le repository. Si vous préférez l'exclure, décommenter dans `.gitignore` :
```
# windows/third_party/ezviz_sdk/
```

**Fonctionnalités implémentées** :
- ✅ Initialisation SDK
- ✅ Lecture vidéo en direct
- ✅ Gestion des sessions
- ✅ Configuration (logging, P2P)

Voir `windows/README.md` pour les détails.

## 🍎 Support macOS

**Stratégie** : API REST (déjà fonctionnel) + structure native prête pour FFI wrapper iOS SDK

**Fonctionnalités** :
- ✅ API REST (auth, device management, etc.)
- ⚠️ Lecture vidéo native : Nécessite FFI wrapper ou lecteur alternatif

Voir `macos/README.md` pour les détails.

## 📋 Checklist avant déploiement

- [x] `flutter analyze` - Aucune erreur ✅
- [ ] `flutter test` - Tests passent
- [x] Version dans `pubspec.yaml` (1.2.7) ✅
- [x] Repository GitHub configuré ✅
- [x] Documentation à jour ✅

## 📚 Documentation détaillée

- **Analyse technique** : `ANALYSE_MACOS_WINDOWS.md`
- **Guide Windows** : `windows/README.md`
- **Guide macOS** : `macos/README.md`
- **Intégration SDK** : `INTEGRATION_GUIDE.md`
- **État d'implémentation** : `IMPLEMENTATION_STATUS.md`
