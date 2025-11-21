# 🔧 Dépannage macOS

## Erreur : Unable to find module dependency: 'Flutter'

### Problème
```
error: Unable to find module dependency: 'Flutter'
import Flutter
```

### Solution ✅

Les fichiers Swift macOS doivent utiliser `FlutterMacOS` au lieu de `Flutter`.

**Fichiers corrigés** :
- ✅ `macos/Classes/FlutterEzvizPlugin.swift` - Utilise `import FlutterMacOS`
- ✅ `macos/Classes/EzvizManager.swift` - Utilise `import FlutterMacOS`
- ✅ `macos/Classes/EzvizViewFactory.swift` - Utilise `import FlutterMacOS`
- ✅ `macos/Classes/EzvizView.swift` - Utilise `import FlutterMacOS`
- ✅ `macos/ezviz_flutter.podspec` - Dépendance `FlutterMacOS` configurée

### Vérification

```bash
# Nettoyer et reconstruire
cd macos
pod deintegrate
pod install

# Dans le projet Flutter
flutter clean
flutter pub get
flutter run -d macos
```

## Autres problèmes courants

### Erreur : Pod install échoue
```bash
cd macos
pod repo update
pod install
```

### Erreur : Compilation Swift
Vérifier que Swift 5.0+ est utilisé dans le podspec.

### Erreur : Framework non trouvé
Vérifier que `FlutterMacOS` est bien dans les dépendances du podspec.

