#ifndef WALL_H
#define WALL_H

#include "Tile.h"

class Wall : public Tile
{
public:
    explicit Wall(int row, int column);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    bool moveTo(Tile* destTile, Character* who) override;
private:

};

#endif // WALL_H
