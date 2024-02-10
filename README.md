# Projet de Bin Packing 3D

Ce projet implémente un algorithme de bin packing 3D en C++ pour optimiser l'empaquetage d'objets dans des conteneurs de capacité fixe. L'algo est décrit mais il n'est pas transcrit complétement. 

## Structure du projet

Le projet est organisé comme suit :

- `src/` : Répertoire contenant les fichiers sources.
  - `BinPackingAlgorithm.cpp` : Implémentation de l'algorithme de bin packing.
  - `Container.cpp` : Implémentation de la classe Container pour représenter les conteneurs.
  - `Item.cpp` : Implémentation de la classe Item pour représenter les objets.
  - `main.cpp` : Programme principal.
  - `Utils.cpp` : Fonctions utilitaires.
  
- `include/` : Répertoire contenant les fichiers d'en-tête.
  - `BinPackingAlgorithm.h` : Déclarations de l'algorithme de bin packing.
  - `Container.h` : Déclarations de la classe Container.
  - `Item.h` : Déclarations de la classe Item.
  - `Utils.h` : Déclarations des fonctions utilitaires.

- `build/` : Répertoire généré par CMake pour les fichiers de construction.

## Compilation

Pour compiler le projet, vous pouvez utiliser CMake :

```bash
cd build
cmake ..
make
```


## Exécution

Une fois compilé, vous pouvez exécuter le programme principal :

```bash
./BinPacking3D
```

## Remarques

Ce projet n'est pas fini. Certaines fonctionnalités sont manquantes ou non optimisées, notamment la fonction `Container::updateMaxItems` et l'algorithme final.