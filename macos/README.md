# macOS Implementation - EZVIZ Flutter Plugin

## 📋 Vue d'ensemble

Cette implémentation macOS utilise une stratégie hybride car EZVIZ ne fournit pas de SDK natif pour macOS.

## ⚠️ Contrainte

**EZVIZ ne fournit pas de SDK natif pour macOS**. Les stratégies suivantes sont disponibles :

## 🎯 Stratégies disponibles

### Option 1 : Wrapper iOS SDK via FFI (Recommandé mais complexe)

Utiliser le SDK iOS (`EZOpenSDK.xcframework`) via Dart FFI :

1. **Avantages** :
   - Accès à toutes les fonctionnalités natives
   - Performance optimale

2. **Inconvénients** :
   - Complexité élevée
   - Nécessite du reverse-engineering
   - Non officiellement supporté

3. **Implémentation** :
   - Créer des bindings FFI dans `lib/src/ffi/ezviz_ffi_bindings.dart`
   - Créer un wrapper C dans `macos/Classes/ezviz_ffi_wrapper.c`
   - Utiliser les bindings dans `FlutterEzvizPlugin.swift`

### Option 2 : API REST uniquement (Recommandé pour MVP)

Utiliser uniquement les API REST (déjà implémentées) :

1. **Avantages** :
   - Simple à implémenter
   - Déjà fonctionnel
   - Pas de dépendances natives

2. **Inconvénients** :
   - Pas de lecture vidéo native
   - Performance limitée pour certaines fonctionnalités

3. **Implémentation** :
   - Les fonctionnalités REST fonctionnent déjà via `ezviz_client.dart`
   - Pour la lecture vidéo, utiliser un lecteur alternatif :
     - `video_player` : Lecteur vidéo Flutter standard
     - `flutter_vlc_player` : Lecteur VLC pour Flutter

### Option 3 : SDK iOS directement (Non testé)

Essayer d'utiliser le SDK iOS directement sur macOS :

1. Modifier `macos/ezviz_flutter.podspec` :
```ruby
s.vendored_frameworks = [
  'Frameworks/EZOpenSDK.xcframework'
]
```

2. **Note** : Le SDK iOS peut ne pas être compatible avec macOS. À tester.

## 📦 Structure des fichiers

```
macos/
├── Classes/
│   ├── FlutterEzvizPlugin.swift   # Plugin principal
│   ├── EzvizManager.swift          # Gestionnaire EZVIZ
│   ├── EzvizViewFactory.swift      # Factory Platform View
│   ├── EzvizView.swift             # Vue native lecteur
│   ├── EzvizChannelNames.swift     # Définitions des canaux
│   ├── EzvizModel.swift            # Modèles de données
│   └── EzvizUtils.swift            # Utilitaires
├── Resources/
│   └── PrivacyInfo.xcprivacy       # Manifeste de confidentialité
└── ezviz_flutter.podspec          # Configuration CocoaPods
```

## 🚀 Utilisation actuelle

Par défaut, l'implémentation macOS utilise l'**Option 2 (API REST)** :

- ✅ Toutes les fonctionnalités REST fonctionnent (auth, device management, etc.)
- ⚠️ Le lecteur vidéo affiche un message placeholder
- ⚠️ Certaines fonctionnalités natives (PTZ, audio) nécessitent une implémentation supplémentaire

## 📝 Implémentation future

Les fichiers contiennent des TODOs indiquant où implémenter :
- FFI bindings pour le SDK iOS
- Intégration d'un lecteur vidéo alternatif
- Méthodes natives supplémentaires

## 🔨 Compilation

```bash
flutter build macos
```

## 🐛 Dépannage

### Erreur : Framework non trouvé
- Vérifier que le framework est dans `macos/Frameworks/`
- Vérifier la configuration dans `podspec`

### Erreur FFI
- Vérifier que les bindings sont corrects
- Vérifier la compatibilité des architectures

### Erreur de compilation Swift
- Vérifier que Swift 5.0+ est utilisé
- Vérifier les imports conditionnels

