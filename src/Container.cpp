#include "Container.h"
#include "Utils.h"
#include <limits>

Container::Container()
    : capacityLength(0), capacityWidth(0), capacityHeight(0),
      maxXItem(), maxYItem(), maxZItem(), items() {}

Container::Container(int length, int width, int height)   
    : capacityLength(length), capacityWidth(width), capacityHeight(height),
      maxXItem(length, width, height, Pos(0, 0, 0)), 
      maxYItem(length, width, height, Pos(0, 0, 0)), 
      maxZItem(length, width, height, Pos(0, 0, 0)), 
      items() {}


// Vérifie si l'objet peut s'insérer dans le conteneur et retourne l'indice de l'item virtuel maximal approprié 
// (voir Container.h pour comprendre l'hypothèse).
std::pair<bool, int> Container::canFit(const Item& item) const {
    bool fitX = compareItems(item, maxXItem);
    bool fitY = compareItems(item, maxYItem);
    bool fitZ = compareItems(item, maxZItem);

    if (fitX || fitY || fitZ) {
        // Trouver l'indice de l'item virtuel possible qui a le volume minimal
        int index = -1;
        int minVolume = std::numeric_limits<int>::max();
        
        if (fitX) {
            int volumeX = maxXItem.getLength() * maxXItem.getWidth() * maxXItem.getHeight();
            if (volumeX < minVolume) {
                index = 0;
                minVolume = volumeX;
            }
        }
        
        if (fitY) {
            int volumeY = maxYItem.getLength() * maxYItem.getWidth() * maxYItem.getHeight();
            if (volumeY < minVolume) {
                index = 1;
                minVolume = volumeY;
            }
        }
        
        if (fitZ) {
            int volumeZ = maxZItem.getLength() * maxZItem.getWidth() * maxZItem.getHeight();
            if (volumeZ < minVolume) {
                index = 2;
            }
        }

        return std::make_pair(true, index);
    }

    return std::make_pair(false, -1);
}


void Container::updateMaxItems(const Item& item, const int index) {
    // à completer
}

void Container::addItem(const Item& item, const int index) {
    if (index != -1) {
        // Mettre à jour la position de l'objet
        Pos pos;
        if (index == 0) {
            pos = maxXItem.getPosition();
        } else if (index == 1) {
            pos = maxYItem.getPosition();
        } else if (index == 2) {
            pos = maxZItem.getPosition();
        }

        Item mutableItem = item; // Créez une copie modifiable de l'objet
        mutableItem.setPosition(pos.x, pos.y, pos.z);
        
        items.push_back(mutableItem);
        
        // Mettre à jour les dimensions maximales virtuelles du conteneur
        updateMaxItems(mutableItem, index); // Passer également l'indice ici
    }
}



int Container::getItemCount() const {
    return items.size();
}
