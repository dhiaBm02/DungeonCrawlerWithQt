//
// Created by louss on 11/30/2022.
//

#include "Door.h"
#include "Character.h"
Door::~Door() = default;

Door::Door(const int row, const int col) :
    Tile("X", nullptr,row ,col), Passive() , trigger(nullptr)
{
    state_open=false;
}

void Door::notify(Aktive *source) {
    bool ok = !state_open;
    this->state_open=ok;
    cout<<"statttts is :  "<<getstate()<<"####"<<ok<<endl;
    trigger = source;
    setDoorTexture();
}
bool Door::getstate()const{
    cout<<"door is "<<this->state_open;
    return state_open;
}
bool Door::moveTo(Tile *destTile, Character *who) {
     return Tile::moveTo(destTile,who);
}
Tile* Door::onLeave(Tile* destTile, Character* who) {
    if (state_open) {
        return this;
    }
    else {
        return nullptr;
    }
}

Tile *Door::onEnter(Tile *fromTile, Character *who) {
    if (state_open) return this;
    return nullptr;
}

void Door::setDoorTexture() {
  if(state_open) texture ="/" ;
  else texture ="X";
}
