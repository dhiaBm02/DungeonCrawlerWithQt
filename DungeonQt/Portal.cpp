#include "Portal.h"
#include "Character.h"

Portal::Portal(const int row, const int column, Tile *destination)
      : Tile("O", nullptr, row, column), destination(destination),portalType(1)
{

}

Tile *Portal::onEnter(Tile *fromTile, Character *who)
{
    return destination;
}

bool Portal::moveTo(Tile *destTile, Character *who)
{
    /*
    Tile* fromTile = onLeave(destTile,who);

    if(fromTile == nullptr)
        return false;


    if(destTile->onEnter(fromTile,who) == nullptr)
        return false;
    Tile* realDest = destTile->onEnter(fromTile,who);


        fromTile->setCharacter(nullptr);
        realDest->setCharacter(who);
        who->setTile(realDest);
        return true;
*/
    return Tile::moveTo(destTile,who);
}
void Portal::setPortalType(int type){
    portalType=type;
}
int Portal::getPortalType()const{
    return portalType;
}
void Portal::setDestination(Portal * p) {
destination=p;
}
