#ifndef ITEM_H
#define ITEM_H

struct Pos {
    int x;
    int y;
    int z;

    Pos() : x(-1), y(-1), z(-1) {} // Valeurs par défaut à -1 pour ne pas la confondre avec une position actuelle de (0,0,0)
    Pos(int a, int b, int c) : x(a), y(b), z(c) {}
};

class Item {
private:
    int length;
    int width;
    int height;
    Pos position; // Position actuelle de l'item dans le conteneur

public:
    Item();
    Item(int l, int w, int h);
    Item(int l, int w, int h, Pos pos);
    int getLength() const;
    int getWidth() const;
    int getHeight() const;
    Pos getPosition() const;
    void setPosition(int x, int y, int z);
};

#endif 
