#include "BinPackingAlgorithm.h"
#include <algorithm>


/*
Important : l'algo ne fonctionne pas encore, il doit encore etre complété mais voici l'idée
Algo ::
1. Tri des objets par ordre decroissant de leur taille totale (longueur * largeur * hauteur).
2. Initialisation des conteneurs vides.
3. Pour chaque objet dans la liste triée :
     3.1. Trouver le conteneur existant avec le meilleur ajustement pour l'objet :
          3.1.1. Pour chaque conteneur existant :
                    3.1.1.1. Si l'objet peut s'insérer dans le conteneur sans dépasser la capacité et
                                 si le conteneur a le volume disponible le plus proche du volume de l'objet, 
                                 alors ce conteneur est sélectionné.
          3.1.2. Si aucun conteneur ne convient, créer un nouveau conteneur et l'ajouter à la liste.
     3.2. Ajouter l'objet au conteneur sélectionné.
     3.3. Mettre à jour les dimensions maximales virtuelles du conteneur 
4. Fin de la boucle.
5. Retourner la liste des conteneurs avec les objets placés.
*/



// Fonction de comparaison pour le tri des objets par taille totale décroissante
bool compareTotalSize(const Item& item1, const Item& item2) {
    return (item1.getLength() * item1.getWidth() * item1.getHeight()) > (item2.getLength() * item2.getWidth() * item2.getHeight());
}


// n'est pas optimisé et ne vas pas marchier sans completer la methode Container::updateMaxItems. Manque de temps :/
std::vector<Container> binPackingAlgorithm(std::vector<Item>& items, int length, int width, int height) {
    // Tri des objets par taille totale décroissante
    std::sort(items.begin(), items.end(), compareTotalSize);

    std::vector<Container> containers;
    // Initialisation des conteneurs vides
    containers.push_back(Container(length, width, height));

    // Pour chaque objet dans la liste triée
    for (const auto& item : items) {
        bool placed = false;
        // Pour chaque conteneur existant
        for (auto& container : containers) {
            std::pair<bool, int> fitResult = container.canFit(item);
            if (fitResult.first) { // Si l'objet peut s'insérer dans le conteneur
                container.addItem(item, fitResult.second);
                placed = true;
                break;
            }
        }
        if (!placed) { // Si aucun conteneur existant ne convient, créer un nouveau conteneur
            containers.push_back(Container(length, width, height));
            containers.back().addItem(item, 0); // Ajouter l'objet au nouveau conteneur
        }
    }
    return containers;
}
