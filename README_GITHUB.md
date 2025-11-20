# 📦 Utiliser ezviz_flutter_plus depuis GitHub

## 🔗 Repository

**GitHub** : https://github.com/Justany/ezviz_flutter_plus

## ⚡ Installation rapide

Dans votre `pubspec.yaml` :

```yaml
dependencies:
  ezviz_flutter_plus:
    git:
      url: https://github.com/Justany/ezviz_flutter_plus.git
      ref: main
```

Puis :
```bash
flutter pub get
```

## 📖 Utilisation

**Important** : Le package s'appelle `ezviz_flutter` dans le code Dart, même si la dépendance s'appelle `ezviz_flutter_plus`.

```dart
import 'package:ezviz_flutter/ezviz_flutter.dart';

void main() {
  EzvizConstants.setRegion(EzvizRegion.europe);
  runApp(MyApp());
}
```

## 🪟 Support Windows

Le SDK Windows (~37 MB) est inclus dans le repository. Si vous préférez le télécharger séparément :

1. Télécharger depuis : https://open.ys7.com/
2. Extraire dans : `windows/third_party/ezviz_sdk/`

## 🍎 Support macOS

Le support macOS utilise les API REST par défaut. Voir `macos/README.md` pour plus d'informations.

## 📚 Documentation

- **Guide complet** : Voir `README.md`
- **Guide Windows** : `windows/README.md`
- **Guide macOS** : `macos/README.md`
- **Exemples** : Dossier `example/`

