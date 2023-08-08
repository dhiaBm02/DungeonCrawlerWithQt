//
// Created by louss on 11/30/2022.
//

#ifndef PG2_DUNGEONCRAWLER_PASSIVE_H
#define PG2_DUNGEONCRAWLER_PASSIVE_H

#include "Tile.h"
#include <iostream>
#include"Aktive.h"
class Aktive;
class Passive {
public:
 Passive();
 ~Passive() ;
 virtual void notify(Aktive* source)=0;
private:

};

#endif //PG2_DUNGEONCRAWLER_PASSIVE_H
