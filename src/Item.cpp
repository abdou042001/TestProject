#include "Item.h"

Item::Item() : length(0), width(0), height(0) {}

Item::Item(int l, int w, int h) : length(l), width(w), height(h) {}

Item::Item(int l, int w, int h, Pos pos) : length(l), width(w), height(h), position(pos) {}

int Item::getLength() const {
    return length;
}

int Item::getWidth() const {
    return width;
}

int Item::getHeight() const {
    return height;
}

Pos Item::getPosition() const {
    return position;
}

void Item::setPosition(int x, int y, int z) {
    position.x = x;
    position.y = y;
    position.z = z;
}