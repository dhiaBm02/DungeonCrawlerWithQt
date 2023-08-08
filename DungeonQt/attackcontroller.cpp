
#include "attackcontroller.h"
#include"Character.h"
AttackController::AttackController(Level * l):AbstractController()

{
 level=l;
}

int AttackController::move()
{
    if(level->getNPC("Y")->getStamina()==0)
       return 5;

    Tile* dest = level->getTile(level->getch()->getRow(),level->getch()->getCol());
    //Tile* from = level->getTile(level->getNpcPos()->getRow(),level->getNpcPos()->getCol());
    cout<<"start is from moove : "<<start->getRow()<<"--"<<start->getCol()<<"text"<<start->getTexture()<<endl;
    string mvpath=level->getPath(start,dest);
    cout<<"path is : "<<mvpath[0]<<endl;
    if (!mvpath.empty())
    {return (mvpath[0]-'0');}
    return 5 ;
}

