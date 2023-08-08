//
// Created by louss on 11/30/2022.
//
#include "Pit_Rampe.h"
#include "Character.h"
Pit::Pit(int row, int col) :
        Tile("_", nullptr, row, col) {}

Tile *Pit::onEnter(Tile *fromTile, Character *who) {
    return this;
}

bool Pit::moveTo(Tile *destTile, Character *who) {

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
    return true;
}

Tile *Pit::onLeave(Tile *destTile, Character *who) {
    if(destTile->getTexture()=="<" || destTile->getTexture()=="_"){
        return this;
    }
    return nullptr;
}

Pit::~Pit() = default;
Rampe::~Rampe() = default;

Rampe::Rampe(int row, int col) :
        Tile("<", nullptr, row, col) {}

Tile *Rampe::onEnter(Tile *fromTile, Character *who) {
    return this;
}

bool Rampe::moveTo(Tile *destTile, Character *who) {
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
    return true;
}

Tile *Rampe::onLeave(Tile *destTile, Character *who) {
    return this;
}
