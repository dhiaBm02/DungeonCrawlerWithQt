//
// Created by louss on 11/30/2022.
//

#ifndef PG2_DUNGEONCRAWLER_PIT_RAMPE_H
#define PG2_DUNGEONCRAWLER_PIT_RAMPE_H
#include "Tile.h"
class Pit: public Tile {
public:
    Pit(int row,int col);
~Pit() override;
    Tile * onEnter(Tile *fromTile, Character *who) override;
    bool moveTo(Tile *destTile, Character *who) override;
    Tile * onLeave(Tile *destTile, Character *who) override;

};
class Rampe:public Tile{
public:
    Rampe(int,int);
    ~Rampe() override;
    Tile * onEnter(Tile *fromTile, Character *who) override;
    bool moveTo(Tile *destTile, Character *who) override;
    Tile * onLeave(Tile *destTile, Character *who) override;

};

#endif //PG2_DUNGEONCRAWLER_PIT_RAMPE_H
