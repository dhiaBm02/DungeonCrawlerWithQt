//
// Created by louss on 11/30/2022.
//

#ifndef PG2_DUNGEONCRAWLER_DOOR_H
#define PG2_DUNGEONCRAWLER_DOOR_H

#include "Tile.h"
#include "Wall.h"
#include "Floor.h"
#include "Passive.h"
#include "Aktive.h"

class Door :  public Tile, public Passive {
public:
    Door(int row, int col);
    ~Door()                                      override;
public:
    void setDoorTexture() ;
    bool moveTo(Tile *destTile, Character *who)  override;
    void notify(Aktive *source)                  override;
    Tile* onLeave(Tile* destTile, Character* who)override;
    Tile *onEnter(Tile *fromTile, Character *who)override;
    bool getstate()const;
private:
    bool state_open;
    Aktive *trigger;
};

#endif //PG2_DUNGEONCRAWLER_DOOR_H
































