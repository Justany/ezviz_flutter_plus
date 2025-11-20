# 📦 Utiliser ezviz_flutter_plus depuis GitHub

## 🔗 Repository GitHub

**URL** : https://github.com/Justany/ezviz_flutter_plus

## 📝 Installation dans votre projet Flutter

### Méthode 1 : Depuis la branche main (développement)

Dans le `pubspec.yaml` de votre projet :

```yaml
dependencies:
  ezviz_flutter_plus:
    git:
      url: https://github.com/Justany/ezviz_flutter_plus.git
      ref: main
```

### Méthode 2 : Depuis un tag de version (recommandé)

```yaml
dependencies:
  ezviz_flutter_plus:
    git:
      url: https://github.com/Justany/ezviz_flutter_plus.git
      ref: v1.2.7  # Version spécifique
```

### Méthode 3 : Depuis une branche spécifique

```yaml
dependencies:
  ezviz_flutter_plus:
    git:
      url: https://github.com/Justany/ezviz_flutter_plus.git
      ref: feature/windows-support  # Nom de la branche
```

### Méthode 4 : Chemin local (développement)

```yaml
dependencies:
  ezviz_flutter_plus:
    path: ../ezviz_flutter_plus  # Chemin relatif vers le package
```

## ⚙️ Installation

Après avoir ajouté la dépendance dans `pubspec.yaml` :

```bash
flutter pub get
```

## 📖 Utilisation dans le code

**Important** : Le package s'appelle `ezviz_flutter` dans le code Dart, même si la dépendance s'appelle `ezviz_flutter_plus`.

```dart
// Import normal
import 'package:ezviz_flutter/ezviz_flutter.dart';

void main() {
  // Configurer la région
  EzvizConstants.setRegion(EzvizRegion.europe);
  
  runApp(MyApp());
}
```

## 🪟 Support Windows

Si vous utilisez Windows, vous devez télécharger le SDK EZVIZ :

1. Télécharger depuis : https://open.ys7.com/
2. Extraire dans : `windows/third_party/ezviz_sdk/`
3. Voir `windows/README.md` pour les détails

## 🍎 Support macOS

Le support macOS utilise les API REST par défaut. Voir `macos/README.md` pour plus d'informations.

## 🔄 Mise à jour

Pour mettre à jour vers la dernière version :

```bash
flutter pub upgrade ezviz_flutter_plus
```

Ou pour forcer la mise à jour depuis Git :

```bash
flutter pub cache repair
flutter pub get
```

## 📚 Documentation

- **README principal** : https://github.com/Justany/ezviz_flutter_plus/blob/main/README.md
- **Guide Windows** : https://github.com/Justany/ezviz_flutter_plus/blob/main/windows/README.md
- **Guide macOS** : https://github.com/Justany/ezviz_flutter_plus/blob/main/macos/README.md
- **Exemples** : https://github.com/Justany/ezviz_flutter_plus/tree/main/example

## 🐛 Problèmes courants

### Erreur : Package non trouvé
**Solution** : Vérifier l'URL GitHub et la branche/tag

### Erreur : SDK Windows manquant
**Solution** : Télécharger le SDK EZVIZ et le placer dans `windows/third_party/ezviz_sdk/`

### Erreur : Import ne fonctionne pas
**Solution** : Utiliser `package:ezviz_flutter/ezviz_flutter.dart` (pas `ezviz_flutter_plus`)

## ✅ Exemple complet

```yaml
# pubspec.yaml
name: mon_app
description: Mon application Flutter

dependencies:
  flutter:
    sdk: flutter
  ezviz_flutter_plus:
    git:
      url: https://github.com/Justany/ezviz_flutter_plus.git
      ref: main
```

```dart
// main.dart
import 'package:flutter/material.dart';
import 'package:ezviz_flutter/ezviz_flutter.dart';

void main() {
  EzvizConstants.setRegion(EzvizRegion.europe);
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        body: EzvizSimplePlayer(
          deviceSerial: 'YOUR_DEVICE_SERIAL',
          channelNo: 1,
          config: EzvizPlayerConfig(
            appKey: 'YOUR_APP_KEY',
            accessToken: 'YOUR_ACCESS_TOKEN',
          ),
        ),
      ),
    );
  }
}
```

