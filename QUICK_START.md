# 🚀 Guide Rapide - Tests et Déploiement

## ⚡ Tests rapides

### 1. Tests unitaires
```bash
flutter test
```

### 2. Analyse du code
```bash
flutter analyze
```

### 3. Test de compilation (via l'exemple)
```bash
cd example
flutter pub get

# Windows (nécessite SDK EZVIZ)
flutter build windows --debug

# macOS
flutter build macos --debug

# Android
flutter build apk --debug

# iOS
flutter build ios --debug --no-codesign
```

**Note** : C'est un package, pas une app. Utilisez le dossier `example/` pour tester.

### 4. Test de l'exemple
```bash
cd example
flutter pub get
flutter run
```

## 📦 Déploiement GitHub (5 minutes)

### Étape 1 : Préparer
```bash
# Vérifier que tout est commité
git status

# Mettre à jour la version dans pubspec.yaml
# version: 1.2.7
```

### Étape 2 : Repository GitHub existant ✅

Le repository est déjà créé : **https://github.com/Justany/ezviz_flutter_plus**

### Étape 3 : Pousser le code
```bash
# Si pas encore initialisé
git init
git add .
git commit -m "feat: Add Windows and macOS support"

# Connecter à GitHub (déjà configuré)
git remote add origin https://github.com/Justany/ezviz_flutter_plus.git
# OU si déjà configuré, vérifier :
git remote -v

# Pousser le code
git branch -M main
git push -u origin main

# Créer un tag
git tag -a v1.2.7 -m "Version 1.2.7 - Windows and macOS support"
git push origin v1.2.7
```

## 🔗 Utiliser depuis GitHub

Dans votre projet Flutter, ajoutez dans `pubspec.yaml` :

```yaml
dependencies:
  ezviz_flutter_plus:
    git:
      url: https://github.com/Justany/ezviz_flutter_plus.git
      ref: main  # ou v1.2.7 pour une version spécifique
```

**Note** : Le nom du package dans le code est `ezviz_flutter`, mais le repository GitHub est `ezviz_flutter_plus`.

Puis :
```bash
flutter pub get
```

## ⚠️ Important : SDK Windows

Le SDK Windows fait **~37 MB compressé** (~130 MB décompressé).

**Options** :
- **Inclure dans Git** (recommandé) : 37 MB compressé est acceptable
- **Exclure du Git** : Les utilisateurs devront télécharger le SDK séparément

**Si vous excluez** (décommenter dans `.gitignore`) :
1. Télécharger le SDK depuis https://open.ys7.com/
2. Extraire dans `windows/third_party/ezviz_sdk/`
3. Voir `windows/README.md` pour les détails

## 📚 Documentation complète

- `TESTING_GUIDE.md` - Guide de tests détaillé
- `DEPLOYMENT_GUIDE.md` - Guide de déploiement complet
- `README.md` - Documentation principale

