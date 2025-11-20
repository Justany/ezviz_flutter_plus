# Guide de Tests - ezviz_flutter

## 🧪 Tests avant déploiement

Avant de déployer le package sur GitHub, il est important de tester toutes les fonctionnalités.

## 📋 Checklist de tests

### 1. Tests unitaires Dart

```bash
# Lancer tous les tests unitaires
flutter test

# Lancer un test spécifique
flutter test test/unit/client/ezviz_client_test.dart

# Avec couverture
flutter test --coverage
```

**Tests à vérifier** :
- ✅ Client REST (`test/unit/client/`)
- ✅ Services (`test/unit/services/`)
- ✅ Modèles (`test/unit/models/`)
- ✅ Utilitaires (`test/unit/utils/`)

### 2. Tests d'intégration

```bash
# Tests d'intégration
flutter test integration_test/

# Test spécifique du player
flutter test integration_test/ezviz_simple_player_platform_view_test.dart
```

### 3. Tests sur chaque plateforme

#### Android
```bash
# Build et test Android
flutter build apk --debug
flutter test --platform android

# Sur un appareil/émulateur
flutter run -d <device_id>
```

#### iOS
```bash
# Build et test iOS
flutter build ios --debug --no-codesign
flutter test --platform ios

# Sur un appareil/simulateur
flutter run -d <device_id>
```

#### Windows
```bash
# Build Windows
flutter build windows --debug

# Tester la compilation
flutter run -d windows

# Vérifier que les DLLs sont copiées
# Dans build/windows/runner/Debug/ vérifier la présence des DLLs EZVIZ
```

#### macOS
```bash
# Build macOS
flutter build macos --debug

# Tester la compilation
flutter run -d macos
```

### 4. Tests de l'exemple

```bash
# Lancer l'application d'exemple
cd example
flutter pub get
flutter run

# Tester sur différentes plateformes
flutter run -d windows
flutter run -d macos
flutter run -d android
flutter run -d ios
```

## 🔍 Vérifications spécifiques

### Windows - SDK EZVIZ

1. **Vérifier la compilation** :
```bash
cd windows
# Vérifier que CMakeLists.txt est correct
# Vérifier que les chemins SDK sont corrects
```

2. **Vérifier les DLLs** :
```bash
# Après build, vérifier dans build/windows/runner/Debug/
# Que toutes les DLLs EZVIZ sont présentes :
# - OpenNetStream.dll
# - NetStream.dll
# - PlayCtrl.dll
# - etc.
```

3. **Test d'initialisation SDK** :
```dart
// Dans l'exemple, tester :
final result = await EzvizManager.initSDK(...);
print('SDK initialized: $result');
```

### macOS - Structure

1. **Vérifier la compilation Swift** :
```bash
cd macos
pod install  # Si nécessaire
# Vérifier qu'il n'y a pas d'erreurs de compilation
```

2. **Tester les API REST** :
```dart
// Les API REST doivent fonctionner
final client = EzvizClient(
  appKey: 'YOUR_APP_KEY',
  appSecret: 'YOUR_APP_SECRET',
);
```

## 🐛 Tests de régression

### Vérifier la compatibilité Android/iOS

```bash
# S'assurer que les modifications n'ont pas cassé Android/iOS
flutter test --platform android
flutter test --platform ios
```

### Vérifier les widgets

```bash
# Tests des widgets
flutter test test/widget/
```

## 📊 Rapport de tests

Créer un rapport de tests :

```bash
# Générer un rapport HTML
flutter test --reporter expanded

# Avec couverture
flutter test --coverage
genhtml coverage/lcov.info -o coverage/html
```

## ✅ Checklist finale avant déploiement

- [ ] Tous les tests unitaires passent (`flutter test`)
- [ ] Tests d'intégration passent
- [ ] Compilation réussie sur Android
- [ ] Compilation réussie sur iOS
- [ ] Compilation réussie sur Windows (avec SDK)
- [ ] Compilation réussie sur macOS
- [ ] Exemple fonctionne sur toutes les plateformes
- [ ] Pas d'erreurs de lint (`flutter analyze`)
- [ ] Documentation à jour
- [ ] CHANGELOG.md mis à jour
- [ ] Version dans pubspec.yaml incrémentée

## 🚨 Problèmes courants

### Windows - DLLs manquantes
**Solution** : Vérifier que `CMakeLists.txt` copie bien les DLLs

### macOS - Erreurs de compilation Swift
**Solution** : Vérifier les imports et la version Swift

### Tests échouent
**Solution** : Vérifier les mocks et les dépendances

## 📝 Commandes utiles

```bash
# Analyser le code
flutter analyze

# Formater le code
dart format .

# Vérifier les dépendances
flutter pub outdated

# Nettoyer
flutter clean
flutter pub get
```

