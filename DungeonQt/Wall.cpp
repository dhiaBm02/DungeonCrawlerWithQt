#include "Wall.h"
#include "Character.h"

Wall::Wall(const int row, const int column)
    : Tile("#", nullptr, row, column)
{

}

Tile *Wall::onEnter(Tile *fromTile, Character *who)
{
    return nullptr;
}

bool Wall::moveTo(Tile *destTile, Character *who)
{
    return false;
}
