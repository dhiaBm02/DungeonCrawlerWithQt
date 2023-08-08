//
// Created by louss on 11/30/2022.
//

#ifndef PG2_DUNGEONCRAWLER_SWITCH_H
#define PG2_DUNGEONCRAWLER_SWITCH_H
#include "Tile.h"
#include "Aktive.h"



class Switch : public Tile , public Aktive{
public:
    Switch( int row, int column);
    //void attach(Passive*) ;
    //void detach(Passive*) ;
    void activate() override;
    //bool moveTo(Tile *destTile, Character *who) override;
    Tile * onEnter(Tile *fromTile, Character *who) override;
    //int findObserver(Passive* observer) ;

};

#endif //PG2_DUNGEONCRAWLER_SWITCH_H
