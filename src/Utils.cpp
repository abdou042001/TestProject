#include "Utils.h"

//retourne true si tous les dims de item2 sont supr à celles de item1 
bool compareItems(const Item& item1, const Item& item2) {  
    return (item1.getLength() <= item2.getLength() && item1.getWidth() <= item2.getWidth() && item1.getHeight() <= item2.getHeight());
}
