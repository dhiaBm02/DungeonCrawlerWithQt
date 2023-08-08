#include "Level.h"
#include "Wall.h"
#include "Floor.h"
#include "Portal.h"
#include "Character.h"
#include "Pit_Rampe.h"
#include "Switch.h"
#include "Door.h"
#include "levelchanger.h"
#include"Dungeoncrawler.h"
#include "toolbox.h"
#include<iostream>

Level::Level(string mymap, DungeonCrawler* game,string path):
    levmap(mymap),game(game),pathfile(path)
{
    nbrOfLevels++;
    Tile* tempTile =nullptr;//neu geandert auch alle pointers so mit mullpoinutr habe ich gemacht
    int pCnt = 0, pRow1, pCol1, pRow2,
            pCol2 ;
    for(int c = 0; c < MAX_COL; c++) {
        for(int r = 0; r < MAX_ROW; r++) {
            switch (levmap.at(10 * c + r)) {
                case '#':
                    tempTile = new Wall(r,c);
                    break;
                case '.':
                    tempTile = new Floor(r,c);
                    myGraph->addNode(tempTile);
                    break;
                case 'O':
                    pCnt++;
                    if(pCnt ==1){
                        pRow1=r;pCol1=c;
                        tempTile = new Floor(r ,c);
                    }
                    else if(pCnt == 2) {
                        pRow2= r; pCol2=c;
                        tempTile = new Floor(r ,c);
                    }
                    else if(pCnt==3) {
                        addPairPortal(pRow1,pCol1 ,r ,c,1);                       
                    continue;
                    }
                    else if(pCnt==4) {
                        addPairPortal(pRow2,pCol2 ,r ,c,2);                        
                    continue;
                    }
                    break;
                case 'X':
                    tempTile = new Door(r,c);
                    myGraph->addNode(tempTile);
                    setdoor(tempTile);
                    break;
                case '?':
                    tempTile = new Switch(r,c);
                    this->myswitch=dynamic_cast<Switch*>(tempTile);
                    myGraph->addNode(tempTile);

                    break;
                case '_':
                    tempTile = new Pit(r,c);
                    myGraph->addNode(tempTile);

                    break;
                case '<':
                    tempTile = new Rampe(r,c);
                    myGraph->addNode(tempTile);

                    break;
                case 'L':
                std::cout<<"-------"<<nbrOfLevels<<"-------";
                    if(nbrOfLevels==1){
                    //tempTile= new Floor(r,c);
                    tempTile=new LevelChanger(r,c,map.at(r+1).at(c-3),this);
                    setPortalchanger(tempTile);
                    }
                    else{
                        std::cout<<std::endl<< "aaaa is  " <<map.at(0).at(0)->getTexture();

                        std::cout<<"--second---"<<nbrOfLevels<<"--refgw---";

                    addPairChanger(r,c,game->getMylevels().begin().getvalue());
                    continue;
                    }
                    break;
                case 'B':
                    tempTile = new ToolBox(r,c);
                    myGraph->addNode(tempTile);
                    break;
            }
            map.at(c).at(r) = tempTile;
        }
    }

    myGraph->makeConnections();

    NPCs.push_back(new NPC("M","846566",100,20));
    NPCs.push_back(new NPC("N","4464564",100,20));
    //AbstractController* controller=new AttackController(this);
    NPCs.push_back(new NPC("Y","4464564",100,20,new AttackController(this) ));
    if(nbrOfLevels==1){
    placeCharacter(NPCs.at(0), 2, 1);
    placeCharacter(NPCs.at(1), 3, 4);
    placeCharacter(NPCs.at(2), 3, 8);

    NPCs[2]->getController()->start=getNPC("Y")->getTile();

}
else{
    placeCharacter(NPCs.at(0), 1, 6);
    placeCharacter(NPCs.at(1), 1, 8);
    placeCharacter(NPCs.at(2), 4, 4);
    NPCs[2]->getController()->start=getNPC("Y")->getTile();

}
    setupSwitch(myswitch->getRow(),myswitch->getCol(),door->getRow(),door->getCol());

}
Graph* Level::createGraph() {

    int pCnt=0;
    Tile* tempTile1 ;
    Tile* tempTile2 ;
    Tile* tempTile ;
    Graph* newGraph=new Graph;
    for(int c = 0; c < MAX_COL; c++) {
        for(int r = 0; r < MAX_ROW; r++) {
            switch (levmap.at(10 * c + r)) {

                case '.':
                    newGraph->addNode(new Floor(r,c));
                    break;
                case 'O':
                pCnt++;
                if(pCnt==1){
                        tempTile1 = new Portal(r ,c,nullptr);
                        continue;
                    }
                    else if(pCnt == 2) {
                        tempTile2 = new Portal(r ,c,nullptr);
                        continue;
                    }
                    else if(pCnt==3) {
                    Tile* tempTile = new Portal(r ,c,tempTile1);
                    newGraph->addNode(tempTile);
                    dynamic_cast<Portal*>(tempTile1)->setDestination(dynamic_cast<Portal*>(tempTile));
                    newGraph->addNode(tempTile1);
                    continue;
                    }
                    else if(pCnt==4) {
                    Tile* tempTile = new Portal(r ,c,tempTile2);
                    newGraph->addNode(tempTile);
                    dynamic_cast<Portal*>(tempTile2)->setDestination(dynamic_cast<Portal*>(tempTile));
                   newGraph->addNode(tempTile2);
                    continue;
                    }
                    break;
                case 'X':
                    tempTile = new Door(r,c);
                    newGraph->addNode(tempTile);
                    setdoor(tempTile);
                    break;
                case '?':
                    tempTile = new Switch(r,c);
                    newGraph->addNode(tempTile);

                    break;
                case '_':
                    tempTile = new Pit(r,c);
                    newGraph->addNode(tempTile);

                    break;
                case '<':
                    tempTile = new Rampe(r,c);
                    newGraph->addNode(tempTile);

                    break;
                case 'B':
                    tempTile = new ToolBox(r,c);
                    newGraph->addNode(tempTile);
                    break;
            }
        }
}
    newGraph->makeConnections();
return newGraph;
}
string countSteps(int r1,int c1,int r2,int c2 ){
    string path="";

        if ((r1==r2) && (c2 < c1)){
            path=path+"8";
            return path;
        }
        if ((r1==r2) && (c2 > c1)){
            path=path+"2";
        return path;
        }
        if ((c1==c2) && (r1 > r2)){
            path=path+"4";
            return path;
        }
        if ((c1==c2) && (r2 > r1)){
            path=path+"6";
            return path;
        }
        if  ((r1<r2) && (c1 > c2)){
            path=path+"9";
            return path;
        }
        if ((r2<r1) && (c2 < c1)){
            path=path+"7";///
            return path;
        }
        if ((r1<r2) && (c1 < c2)){
            path=path+"3";
            return path;
        }
        if ((r2<r1) && (c2 > c1)){
            path=path+"1";
            return path;
        }

    return path;
}
string Level::getPath(Tile *from, Tile *to) {

     myGraph=createGraph();
     vector<Tile*> p =myGraph->Dijkastra_Algorithm(from,to);
     cout<<from->getTexture()<<"----- col ="<<from->getCol()<<"----- row ="<<from->getRow()<<endl;
     string path {};
     int r1,c1,r2,c2;

    cout<<"going to "<<to->getRow() <<"-"<<to->getCol();
     for (size_t i=1;i<p.size();i++)
     {

         r1=p[i-1]->getRow();c1=p[i-1]->getCol();
         r2=p[i]->getRow();c2=p[i]->getCol();
         if(getTile(r1,c1)->getTexture()=="O") {
             int r3=r1;
             r1=getTile(r1,c1)->onEnter(nullptr,nullptr)->getRow();
             c1=getTile(r3,c1)->onEnter(nullptr,nullptr)->getCol();
         }
         path+=countSteps(r1,c1,r2,c2);
     }
     cout<<"from atepa two : "<<path<<endl;
     return path;

}
Tile* Level::getNpcPos(){
    for (int c = 0; c < getMaxRow(); c++) {
        for (int r = 0; r < getMaxRow(); r++) {
            std::string s= getTile(r,c)->getTexture();
            if (s=="Y")
                return  getTile(r,c);
        }
        }
    return nullptr;
}

string Level::getmap()const{
    return levmap;
}
string Level:: getpath()const{
    return pathfile;
}
void Level::setdoor(Tile* d){
    door=dynamic_cast<Door*>(d);
}
Door* Level::getdoor()const{
    return door;
}
void Level::addPairPortal(int pRow, int pCol, int dRow, int dCol,const int type)
{
    map.at(dCol).at(dRow) = new Portal(dRow, dCol, map.at(pCol).at(pRow));
    auto * _portal = dynamic_cast<Portal*> (map.at(dCol).at(dRow));
    _portal->setPortalType(type);
    //delete map.at(pCol).at(pRow);
    //map.at(pCol).at(pRow) = nullptr;
    map.at(pCol).at(pRow) = new Portal(pRow, pCol, map.at(dCol).at(dRow));
    auto * _portal2 = dynamic_cast<Portal*> (map.at(pCol).at(pRow));
    _portal2->setPortalType(type);
    _portal->setDestination(_portal2);
    _portal2->setDestination(_portal);
    myGraph->addNode(_portal);
    myGraph->addNode(_portal2);


}
void Level::addPairChanger(int row, int col, Level * nextlev)
{
    map.at(col).at(row)=new LevelChanger(row,col,nextlev->getPortalchanger(),nextlev);
    setPortalchanger(map.at(col).at(row));

    auto* levPortal=dynamic_cast<LevelChanger*>(getPortalchanger());
    levPortal->setToLevel(nextlev);
    levPortal->attach(this->game);
    std::cout<<std::endl<< "aaaa is  " <<map.at(0).at(0)->getTexture();
    std::cout<<std::endl<< "cccc is  " <<nextlev->getMap().at(0).at(0)->getTexture();

     std::cout<<std::endl<< "next is   "<< game->getLevels().size();
    int r=nextlev->getPortalchanger()->getRow();
    int c=nextlev->getPortalchanger()->getCol();
    delete nextlev->getMap().at(c).at(r);
    nextlev->getMap().at(c).at(r)=nullptr;
    nextlev->getMap().at(c).at(r)=new LevelChanger(r,c,map.at(col).at(row),this);
    auto* levPortal2=dynamic_cast<LevelChanger*>(nextlev->getMap().at(c).at(r));
    levPortal2->attach(this->game);

}

Tile *Level::getTile(int row, int col) const {

    return  map.at(col).at(row);
}
void Level::placeCharacter(Character *c, int row, int col) {
    map.at(col).at(row)->setCharacter(c);
    c->setTile(getTile(row, col));
    player_col=row;
    player_row=col;
}

int Level::getMaxRow() {
    return MAX_ROW;
}
int Level::getMaxCol() {
    return MAX_COL;
}

NPC *Level::getNPC( std::string texture) const {

    for (auto npc : NPCs) {
        if (npc->getTexture() == texture)
            return npc;
    }
    return nullptr;
}

Level::~Level() {
    for(size_t j = 0; j < map.size(); j++) {
        for(size_t i = 0; i < map.at(j).size(); i++) {
            delete map.at(i).at(j);
            map.at(i).at(j) = nullptr;
        }
    }
}

void Level::setupSwitch(int sRow, int sCol, int dRow, int dCol) {
    delete map.at(sCol).at(sRow);
    map.at(sCol).at(sRow) = nullptr;
    delete map.at(dCol).at(dRow);
    map.at(dCol).at(dRow) = nullptr;
    map.at(sCol).at(sRow) = new Switch(sRow, sCol);
    map.at(dCol).at(dRow) = new Door(dRow, dCol);
    Door* _Door = dynamic_cast<Door*> (map.at(dCol).at(dRow));
    Switch* _Switch = dynamic_cast<Switch*> (map.at(sCol).at(sRow));
    _Switch->attach(_Door);
    _Switch->attach(myGraph);
    myswitch=_Switch;
    setdoor(_Door);
}
std::string Level::getstandard()const{
    return levmap;
}

int Level::getPlayer_col() const
{
    return player_col;
}

int Level::getPlayer_row() const
{
    return player_row;
}
Tile *Level::getPortalchanger() const
{
    return Portalchanger;
}

void Level::setPortalchanger(Tile *newPortalchanger)
{
    Portalchanger = newPortalchanger;
}

int Level::getZombieRow()
{
 return NPCs[0]->getTile()->getRow();
}
int Level::getZombieRow2()
{
 return NPCs[1]->getTile()->getRow();
}
int Level::getZombieRow3()
{
 return NPCs[2]->getTile()->getRow();
}
int Level::getZombieCol()
{
 return NPCs[0]->getTile()->getCol();
}
int Level::getZombieCol3()
{
 return NPCs[2]->getTile()->getCol();
}
int Level::getZombieCol2()
{
 return NPCs[1]->getTile()->getCol();
}
std::array<std::array<Tile *, 10>, 10> Level::getMap() const
{
    return map;
}

int Level::nbrOfLevels=0;
Tile* Level::getch()
{
    for (int c = 0; c < getMaxRow(); c++) {
        for (int r = 0; r < getMaxRow(); r++) {
            std::string s= getTile(r,c)->getTexture();
            if (s=="C")
                return  getTile(r,c);
        }
        }
    return nullptr;
}
std::vector<NPC *> Level::getNPCs()const{
    return NPCs;
}

Switch* Level::getswitch()const{
    return myswitch;
}
