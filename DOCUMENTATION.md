# 📚 Documentation Complète - ezviz_flutter_plus

## 🚀 Utilisation depuis GitHub

**Repository** : https://github.com/Justany/ezviz_flutter_plus

### Installation

```yaml
# pubspec.yaml
dependencies:
  ezviz_flutter_plus:
    git:
      url: https://github.com/Justany/ezviz_flutter_plus.git
      ref: main
```

```bash
flutter pub get
```

**Note** : Le package s'appelle `ezviz_flutter` dans le code Dart, mais utilisez `ezviz_flutter_plus` comme nom de dépendance.

```dart
import 'package:ezviz_flutter/ezviz_flutter.dart';
```

## 🧪 Tests

### Tests unitaires
```bash
flutter test
flutter analyze  # ✅ Aucune erreur
```

### Tester via l'exemple
```bash
cd example
flutter pub get
flutter run -d windows  # ou macos, android, ios
```

## 📦 Déploiement GitHub

### Commandes rapides

```bash
# 1. Vérifier
git status

# 2. Ajouter
git add .

# 3. Commit
git commit -m "feat: Add Windows and macOS support"

# 4. Pousser
git push origin main

# 5. Tag
git tag -a v1.2.7 -m "Version 1.2.7"
git push origin v1.2.7
```

## 🪟 Windows - SDK EZVIZ

**SDK** : EZPCOpenSDK v4.3.6 (~37 MB compressé, ~130 MB décompressé)

Le SDK est inclus dans le repository. Si vous préférez l'exclure, décommenter dans `.gitignore` :
```
# windows/third_party/ezviz_sdk/
```

## 🍎 macOS

Support via API REST (déjà fonctionnel). Structure native prête pour FFI wrapper iOS SDK si nécessaire.

## 📋 Checklist avant déploiement

- [x] `flutter analyze` - Aucune erreur ✅
- [ ] `flutter test` - Tests passent
- [x] Version dans `pubspec.yaml` (1.2.7) ✅
- [x] Repository GitHub configuré ✅
- [x] Documentation à jour ✅

