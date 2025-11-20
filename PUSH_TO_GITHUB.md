# 🚀 Pousser les modifications sur GitHub

## ✅ État actuel

- ✅ Repository GitHub : https://github.com/Justany/ezviz_flutter_plus
- ✅ Remote configuré : `origin` → https://github.com/Justany/ezviz_flutter_plus.git
- ✅ Code analysé : `flutter analyze` - Aucune erreur ✅
- ✅ Tests : Prêts à être exécutés

## 📋 Commandes pour pousser

### 1. Vérifier l'état actuel

```bash
# Voir les fichiers modifiés
git status

# Voir les différences
git diff
```

### 2. Ajouter les fichiers

```bash
# Ajouter tous les fichiers (sauf ceux dans .gitignore)
git add .

# OU ajouter spécifiquement :
git add pubspec.yaml
git add macos/
git add windows/
git add lib/ezviz_player.dart
git add .gitignore
git add *.md
```

### 3. Créer un commit

```bash
git commit -m "feat: Add Windows and macOS support

- Add Windows support with EZPCOpenSDK v4.3.6 integration
- Add macOS structure and base implementation
- Update pubspec.yaml with correct GitHub repository
- Fix all linting issues
- Add comprehensive documentation"
```

### 4. Pousser sur GitHub

```bash
# Pousser sur la branche main
git push origin main

# OU si c'est la première fois
git push -u origin main
```

### 5. Créer un tag de version

```bash
# Créer un tag annoté
git tag -a v1.2.7 -m "Version 1.2.7 - Windows and macOS support"

# Pousser le tag
git push origin v1.2.7
```

## 📝 Fichiers à vérifier avant de pousser

- [x] `pubspec.yaml` - Version et repository mis à jour ✅
- [x] `.gitignore` - SDK Windows exclu ✅
- [x] `lib/ezviz_player.dart` - Détection macOS/Windows ✅
- [x] `macos/` - Structure complète ✅
- [x] `windows/` - Structure complète avec SDK intégré ✅
- [x] Documentation - Guides créés ✅

## ⚠️ Important : SDK Windows

Le SDK Windows (`windows/third_party/ezviz_sdk/`) fait environ **37 MB**.

**Options** :
- **Inclure dans Git** (recommandé) : 37 MB est acceptable pour Git
- **Exclure du Git** : Si vous préférez, les utilisateurs devront télécharger le SDK séparément

**Si vous excluez** (décommenter dans `.gitignore`) :
1. Les utilisateurs devront télécharger le SDK depuis https://open.ys7.com/
2. Extraire dans `windows/third_party/ezviz_sdk/`
3. Voir `windows/README.md` pour les instructions

## 🔍 Vérifications finales

```bash
# Vérifier qu'il n'y a pas d'erreurs
flutter analyze

# Vérifier les tests (optionnel)
flutter test

# Vérifier les fichiers à commiter
git status
```

## 🎯 Commandes complètes (copier-coller)

```bash
# 1. Vérifier l'état
git status

# 2. Ajouter les fichiers
git add .

# 3. Commit
git commit -m "feat: Add Windows and macOS support with EZPCOpenSDK integration"

# 4. Pousser
git push origin main

# 5. Créer et pousser un tag
git tag -a v1.2.7 -m "Version 1.2.7 - Windows and macOS support"
git push origin v1.2.7
```

## 📚 Après le push

Une fois poussé sur GitHub, les utilisateurs pourront utiliser le package :

```yaml
# Dans leur pubspec.yaml
dependencies:
  ezviz_flutter_plus:
    git:
      url: https://github.com/Justany/ezviz_flutter_plus.git
      ref: main  # ou v1.2.7
```

Voir `GITHUB_USAGE.md` pour la documentation complète d'utilisation.

