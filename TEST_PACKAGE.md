# 🧪 Comment Tester un Package Flutter

## ⚠️ Important : Package vs Application

Ce projet est un **package Flutter**, pas une application. Vous ne pouvez pas faire `flutter run` directement.

## ✅ Tests disponibles

### 1. Tests unitaires et d'intégration

```bash
# Lancer tous les tests
flutter test

# Tests avec couverture
flutter test --coverage

# Test spécifique
flutter test test/unit/client/ezviz_client_test.dart
```

### 2. Analyse du code

```bash
# Vérifier le code (maintenant sans erreurs ✅)
flutter analyze
```

### 3. Tester via l'exemple

Le dossier `example/` contient une application de démonstration :

```bash
cd example
flutter pub get
flutter run
```

**Plateformes disponibles** :
```bash
# Android
flutter run -d android

# iOS
flutter run -d ios

# Windows (nécessite le SDK EZVIZ)
flutter run -d windows

# macOS
flutter run -d macos
```

### 4. Test de compilation (sans exécution)

Pour vérifier que le package compile correctement :

```bash
# Vérifier la compilation Dart
flutter pub get
dart analyze

# Pour Windows (vérifier CMake)
cd windows
# Vérifier que CMakeLists.txt est valide
```

## 📦 Tester le package dans un projet externe

### Méthode 1 : Path local (développement)

Dans votre projet Flutter :

```yaml
# pubspec.yaml
dependencies:
  ezviz_flutter_plus:
    path: ../ezviz_flutter_plus  # Chemin relatif
```

```bash
flutter pub get
flutter run
```

### Méthode 2 : Depuis GitHub (après déploiement)

```yaml
# pubspec.yaml
dependencies:
  ezviz_flutter_plus:
    git:
      url: https://github.com/Justany/ezviz_flutter_plus.git
      ref: main
```

**Note** : Le package s'appelle `ezviz_flutter` dans le code, mais utilisez `ezviz_flutter_plus` comme nom de dépendance.

## 🔍 Vérifications spécifiques par plateforme

### Windows

1. **Vérifier que le SDK est présent** :
```bash
ls windows/third_party/ezviz_sdk/
# Doit contenir les dossiers inc/, lib/, etc.
```

2. **Tester la compilation** :
```bash
cd example
flutter build windows --debug
# Vérifier build/windows/runner/Debug/ pour les DLLs
```

### macOS

1. **Vérifier la compilation Swift** :
```bash
cd macos
# Vérifier qu'il n'y a pas d'erreurs
```

2. **Tester l'exemple** :
```bash
cd example
flutter run -d macos
```

### Android/iOS

```bash
cd example
flutter run -d android
flutter run -d ios
```

## ✅ Checklist avant déploiement

- [x] `flutter analyze` - Aucune erreur ✅
- [ ] `flutter test` - Tous les tests passent
- [ ] Exemple fonctionne sur Android
- [ ] Exemple fonctionne sur iOS
- [ ] Exemple compile sur Windows (si SDK présent)
- [ ] Exemple compile sur macOS
- [ ] Documentation à jour

## 🚀 Commandes rapides

```bash
# Tests complets
flutter test && flutter analyze

# Nettoyer et retester
flutter clean && flutter pub get && flutter test

# Tester l'exemple
cd example && flutter pub get && flutter run
```

