#ifndef TOOLBOX_H
#define TOOLBOX_H
#include"Tile.h"


class ToolBox : public Tile
{
public:
   explicit ToolBox(int ,int);

   Tile* onEnter(Tile* fromTile, Character* who) ;

private:

};

#endif // TOOLBOX_H
