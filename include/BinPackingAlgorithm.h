#ifndef BIN_PACKING_ALGORITHM_H
#define BIN_PACKING_ALGORITHM_H

#include <vector>
#include "Item.h"
#include "Container.h"

std::vector<Container> binPackingAlgorithm(std::vector<Item>& items, int length, int width, int height);

#endif 
