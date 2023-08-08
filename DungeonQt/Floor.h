#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include "Tile.h"

using namespace std;
class Floor : public Tile
{
public:
    explicit Floor(int row, int column);
     Tile* onEnter(Tile* fromTile, Character* who) override;
     bool moveTo(Tile* destTile, Character* who) override;
     void setTexture(string);
private:

};

#endif // FLOOR_H

