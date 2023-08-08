#include "levelchanger.h"
#include "Character.h"
#include"Dungeoncrawler.h"



LevelChanger::LevelChanger(int row, int column, Tile *destination, Level * nextlev):
    Portal(row,column,destination),Aktive(),toLevel(nextlev)
{
    this->texture="L";
}

bool LevelChanger::moveTo(Tile *destTile, Character *who)
{
    return Tile::moveTo(destTile,who);

    if(destTile->getCol()==this->col && destTile->getRow()==this->row) return false;
    Tile* fromTile = onLeave(destTile,who);

    if(fromTile == nullptr)
        return false;


    if(destTile->onEnter(fromTile,who) == nullptr)
        return false;

    fromTile->setCharacter(nullptr);
    destTile->setCharacter(who);
    who->setTile(destTile);


    return true;
}
void LevelChanger::activate(){
    for (Passive *pass: Passive_Container) {
        pass->notify(static_cast<Aktive *>(this));
    }
}

Level *LevelChanger::getToLevel() const
{
    return toLevel;
}

Tile *LevelChanger::onEnter(Tile *fromTile, Character *who)
{
    if(who->getTexture()!="C") return nullptr ;
    if (who->getlastmov()==5) return destination;
    activate();
    return destination;
}

void LevelChanger::setToLevel(Level *newToLevel)
{
    toLevel = newToLevel;
}
