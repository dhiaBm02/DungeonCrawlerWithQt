#include "toolbox.h"

ToolBox::ToolBox(int row , int col):
    Tile("B",nullptr,row , col)
{

}
Tile * ToolBox::onEnter(Tile* fromTile, Character* who){

    return this;
}
