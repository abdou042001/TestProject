#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include "Item.h"

class Container {
private:
    int capacityLength;
    int capacityWidth;
    int capacityHeight;
    std::vector<Item> items;
    Item maxXItem; // un Item virtuel qui represente l'objet maximal qu'on peut ajouter en maximisant X (length)
    Item maxYItem; // un Item virtuel .. maximisant Y (width)
    Item maxZItem; // un Item virtuel .. maximisant Z (height)

    // petite remarque : 
    // le choix des maxItem selon les trois dimensions est juste une simplification généralisable.
    // On peut encore generaliser les max Item dans un vecteurs 
    // contenant tous les espaces libres possibles et maximals.

public:
    Container();
    Container(int length, int width, int height);
    void addItem(const Item& item, const int index);
    std::pair<bool, int> canFit(const Item& item) const;
    int getItemCount() const;

private:
    void updateMaxItems(const Item& item, const int index);
};

#endif // CONTAINER_H
