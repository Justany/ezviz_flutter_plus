# Windows Implementation - EZVIZ Flutter Plugin

## 📋 Vue d'ensemble

Cette implémentation Windows utilise le SDK EZVIZ v5.1.18 (C++) pour fournir toutes les fonctionnalités natives.

## 🔧 Configuration requise

1. **SDK EZVIZ Windows v4.3.6 (EZPCOpenSDK)**
   - Télécharger depuis : https://open.ys7.com/
   - Taille : ~37 MB
   - Format : SDK C++ avec DLL, headers et bibliothèques

2. **Flutter Desktop Support**
   - Flutter SDK avec support Windows
   - Visual Studio 2019 ou supérieur
   - CMake 3.14 ou supérieur

## 📦 Structure des fichiers

```
windows/
├── CMakeLists.txt                 # Configuration CMake
├── ezviz_flutter_plugin.cpp       # Plugin principal
├── ezviz_flutter_plugin.h          # Headers du plugin
├── ezviz_manager.cpp               # Gestionnaire EZVIZ
├── ezviz_manager.h                 # Headers du gestionnaire
├── ezviz_player_view.cpp           # Vue native pour le lecteur
├── ezviz_player_view.h             # Headers de la vue
└── runner/
    └── main.cpp                    # Point d'entrée (si nécessaire)
```

## 🚀 Installation du SDK

1. Télécharger le SDK EZVIZ Windows v5.1.18
2. Extraire dans `windows/third_party/ezviz_sdk/`
3. Structure attendue :
   ```
   windows/third_party/ezviz_sdk/
   ├── include/          # Headers (.h)
   ├── lib/              # Bibliothèques (.lib)
   └── bin/              # DLLs (.dll)
   ```

## ⚙️ Configuration CMakeLists.txt

Décommenter et configurer les lignes dans `CMakeLists.txt` :

```cmake
set(EZVIZ_SDK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party/ezviz_sdk")
set(EZVIZ_INCLUDE_DIR "${EZVIZ_SDK_DIR}/include")
set(EZVIZ_LIB_DIR "${EZVIZ_SDK_DIR}/lib")
set(EZVIZ_BIN_DIR "${EZVIZ_SDK_DIR}/bin")
```

## 🔨 Compilation

```bash
flutter build windows
```

## 📝 Implémentation

Les fichiers contiennent des TODOs indiquant où intégrer les appels au SDK EZVIZ. Consulter la documentation du SDK EZVIZ Windows pour les détails d'API.

## 🐛 Dépannage

### Erreur : DLL non trouvée
- Vérifier que les DLLs sont copiées dans le répertoire de sortie
- Vérifier le chemin dans `CMakeLists.txt`

### Erreur : Bibliothèque non trouvée
- Vérifier les chemins dans `CMakeLists.txt`
- Vérifier que les fichiers `.lib` sont présents

### Erreur de compilation
- Vérifier que les headers EZVIZ sont inclus
- Vérifier la compatibilité des versions du SDK

