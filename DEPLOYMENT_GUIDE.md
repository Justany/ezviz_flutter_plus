# Guide de Déploiement GitHub - ezviz_flutter

## 📦 Préparation avant déploiement

### 1. Vérifier le .gitignore

Assurez-vous que le `.gitignore` exclut :
- Les fichiers de build
- Les SDKs volumineux (Windows SDK)
- Les fichiers temporaires

### 2. Mettre à jour la version

Dans `pubspec.yaml` :
```yaml
version: 1.2.7  # Incrémenter la version
```

### 3. Mettre à jour le CHANGELOG.md

Ajouter les nouvelles fonctionnalités :
```markdown
## [1.2.7] - 2025-01-XX
### Added
- Support Windows (EZPCOpenSDK v4.3.6)
- Support macOS (structure de base)
- Documentation complète pour desktop
```

### 4. Vérifier les métadonnées

Dans `pubspec.yaml` :
```yaml
name: ezviz_flutter
description: A comprehensive Flutter/Dart library for EZVIZ camera API integration...
homepage: https://github.com/Justany/ezviz_flutter_plus
repository: https://github.com/Justany/ezviz_flutter_plus
```

## 🚀 Déploiement sur GitHub

### Étape 1 : Vérifier Git (déjà initialisé)

```bash
# Vérifier le remote
git remote -v

# Si pas configuré, ajouter :
git remote add origin https://github.com/Justany/ezviz_flutter_plus.git

# Vérifier les fichiers à commiter
git status
```

### Étape 2 : Repository GitHub ✅

Le repository existe déjà : **https://github.com/Justany/ezviz_flutter_plus**

### Étape 3 : Ajouter et pousser les modifications

```bash
# Ajouter tous les fichiers (sauf ceux dans .gitignore)
git add .

# Commit des modifications
git commit -m "feat: Add Windows and macOS support with EZPCOpenSDK integration"

# Pousser sur GitHub
git push origin main
```

### Étape 4 : Créer un tag de version

```bash
# Créer un tag pour la version
git tag -a v1.2.7 -m "Version 1.2.7 - Windows and macOS support"

# Pousser le tag
git push origin v1.2.7
```

## 📝 Structure recommandée du repository

```
ezviz_flutter/
├── .gitignore              # Exclut les fichiers volumineux
├── README.md               # Documentation principale
├── CHANGELOG.md            # Historique des versions
├── LICENSE                 # Licence
├── pubspec.yaml           # Configuration du package
├── lib/                    # Code source Dart
├── android/               # Code Android
├── ios/                   # Code iOS
├── macos/                 # Code macOS
├── windows/               # Code Windows
├── test/                  # Tests
├── example/               # Exemple d'utilisation
└── doc/                   # Documentation supplémentaire
```

## ⚠️ Important : SDK Windows

Le SDK Windows (`windows/third_party/ezviz_sdk/`) fait environ 37 MB.

**Options** :

### Option 1 : Inclure dans Git (Recommandé pour 37 MB)

Le SDK peut être inclus directement dans le repository Git (37 MB est acceptable).

**Avantage** : Les utilisateurs ont tout immédiatement
**Inconvénient** : Repository légèrement plus lourd

### Option 2 : Exclure du Git (Alternative)

Si vous préférez exclure le SDK, ajouter dans `.gitignore` :
```
# SDK Windows (optionnel - peut être inclus car seulement 37 MB)
# windows/third_party/ezviz_sdk/
```

**Avantage** : Repository plus léger
**Inconvénient** : Les utilisateurs doivent télécharger le SDK séparément

### Option 3 : Documentation pour téléchargement

Créer un fichier `windows/SDK_DOWNLOAD.md` avec les instructions (si le SDK est exclu).

## 🔗 Utilisation depuis GitHub

### Méthode 1 : Depuis pub.dev (Recommandé)

1. Publier sur pub.dev (voir section suivante)
2. Utiliser normalement :
```yaml
dependencies:
  ezviz_flutter: ^1.2.7
```

### Méthode 2 : Depuis GitHub directement

Dans `pubspec.yaml` de votre projet :

```yaml
dependencies:
  ezviz_flutter_plus:
    git:
      url: https://github.com/Justany/ezviz_flutter_plus.git
      ref: main  # ou v1.2.7 pour une version spécifique
```

**Note** : Le package s'appelle `ezviz_flutter` dans le code, mais utilisez `ezviz_flutter_plus` comme nom de dépendance depuis GitHub.

### Méthode 3 : Depuis une branche spécifique

```yaml
dependencies:
  ezviz_flutter_plus:
    git:
      url: https://github.com/Justany/ezviz_flutter_plus.git
      ref: feature/windows-support
```

### Méthode 4 : Depuis un chemin local (développement)

```yaml
dependencies:
  ezviz_flutter_plus:
    path: ../ezviz_flutter_plus
```

## 📦 Publication sur pub.dev (Optionnel)

Si vous voulez publier sur pub.dev :

### Prérequis

1. Compte Google (pour pub.dev)
2. Package testé et fonctionnel
3. Documentation complète

### Étapes

```bash
# Vérifier le package
flutter pub publish --dry-run

# Publier
flutter pub publish
```

**Note** : pub.dev nécessite que le package soit dans un repository Git public.

## 🔄 Mise à jour continue

### Workflow recommandé

1. **Développement** : Travailler sur une branche `develop` ou `feature/*`
2. **Tests** : Tester sur toutes les plateformes
3. **Merge** : Merger dans `main`
4. **Tag** : Créer un tag de version
5. **Release** : Créer une release GitHub (optionnel)

### Créer une release GitHub

1. Aller sur GitHub → Releases → Draft a new release
2. Tag : `v1.2.7`
3. Title : `Version 1.2.7 - Windows and macOS Support`
4. Description : Copier depuis CHANGELOG.md
5. Publier

## 📋 Checklist de déploiement

- [ ] Tous les tests passent
- [ ] Version incrémentée dans `pubspec.yaml`
- [ ] CHANGELOG.md mis à jour
- [ ] README.md à jour
- [ ] `.gitignore` configuré correctement
- [ ] SDK Windows géré (exclu ou LFS)
- [ ] Repository GitHub créé
- [ ] Code poussé sur GitHub
- [ ] Tag de version créé
- [ ] Release GitHub créée (optionnel)
- [ ] Documentation d'utilisation créée

## 🎯 Exemple d'utilisation dans un projet

Une fois déployé, dans votre projet Flutter :

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

```dart
// main.dart
// Note: Le package s'appelle 'ezviz_flutter' dans le code
import 'package:ezviz_flutter/ezviz_flutter.dart';

void main() {
  EzvizConstants.setRegion(EzvizRegion.europe);
  runApp(MyApp());
}
```

**Important** : 
- Nom de dépendance dans `pubspec.yaml` : `ezviz_flutter_plus`
- Import dans le code Dart : `package:ezviz_flutter/ezviz_flutter.dart`

## 🐛 Dépannage

### Erreur : Package non trouvé
**Solution** : Vérifier l'URL GitHub et la branche/tag

### Erreur : SDK Windows manquant
**Solution** : Télécharger le SDK et le placer dans `windows/third_party/ezviz_sdk/`

### Erreur : Compilation échoue
**Solution** : Vérifier que toutes les dépendances sont présentes

