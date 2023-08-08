//
// Created by louss on 11/30/2022.
//

#include "Switch.h"
#include "Door.h"
#include "Character.h"
Switch::Switch(const int row, const int column) :
        Tile("?", nullptr, row, column) {}

Tile * Switch::onEnter(Tile *fromTile, Character *who) {
    activate();
    return this;
}
void Switch::activate() {
    for (Passive *pass: Passive_Container) {
        pass->notify(static_cast<Aktive *>(this));
    }
}

