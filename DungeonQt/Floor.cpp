#include "Floor.h"
#include "Character.h"
#include<QDebug>
using namespace std;

Floor::Floor(const int row, const int column)
     : Tile(".", nullptr, row, column)
{

}

Tile *Floor::onEnter(Tile *fromTile, Character *who)
{
    return this;
}

bool Floor::moveTo(Tile *destTile, Character *who)
{
    return Tile::moveTo(destTile,who);

    Tile* fromTile = onLeave(destTile,who);

    if(fromTile == nullptr)
        return false;

    Tile* realDest = destTile->onEnter(fromTile,who);
    if(realDest == nullptr) {
        return false;
    }

    fromTile->setCharacter(nullptr);
    realDest->setCharacter(who);
    who->setTile(realDest);
    qDebug()<<"the last mov from moveto" <<who->getlastmov();


    return true;
}

void Floor::setTexture(string text) {
 texture=text;
}

