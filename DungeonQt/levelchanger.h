#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H

#include "Aktive.h"
#include "Level.h"
#include "Portal.h"

class LevelChanger: public Portal,public Aktive
{
public:
   explicit LevelChanger(int row, int column, Tile* destination,Level*);
   bool moveTo(Tile *destTile, Character *who) override;
   void activate() override;
   Level *getToLevel() const;
   Tile* onEnter(Tile *fromTile, Character *who)override;
   void setToLevel(Level *newToLevel);

private:
   Level* toLevel;
};

#endif // LEVELCHANGER_H
