#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <array>
#include <vector>
#include "Door.h"
#include "Switch.h"
#include "Tile.h"
#include <string>
#include"Graph.h"

class NPC;
class DungeonCrawler;
using namespace std;
class Level {
public:
    Level(string map,DungeonCrawler*,string );
    void addPairPortal(int pRow, int pCol, int dRow, int dCol,const int type);
    Tile *getTile(int row, int col) const;
    void placeCharacter(Character *c, int row, int col);
    static int getMaxRow();
    static int getMaxCol();
    virtual ~Level();
    void setupSwitch(int sRow, int sCol, int dRow, int dCol);
    NPC* getNPC(string s)const;
    std::string getstandard()const;
    int getPlayer_col() const;
    int getPlayer_row() const;
    void addPairChanger(int pRow, int pCol, Level*);
    static int nbrOfLevels;
    Tile *getPortalchanger() const;
    void setPortalchanger(Tile *newPortalchanger);
    int getZombieRow();
    int getZombieCol();
    int getZombieRow2();
    int getZombieCol2();
    int getZombieRow3();
    int getZombieCol3();
    std::array<std::array<Tile *, 10>, 10> getMap() const;
    string getmap()const;
    void setdoor(Tile*);
    Door* getdoor()const;
    string getpath()const;
    string getPath(Tile *from, Tile* to);
    Tile* getch();
    Tile*  getNpcPos();
    Graph* createGraph();
    Switch* getswitch()const;
    std::vector<NPC *> getNPCs()const;

private:
    Switch * myswitch;
    Door* door;
    Graph* myGraph =new Graph;
    static const int MAX_ROW = 10;
    static const int MAX_COL = 10;
    int player_col;
    int player_row;
    std::array<std::array<Tile *, MAX_COL>, MAX_ROW> map{};
    std::vector<Character *> Players;
    std::vector<NPC *> NPCs;
    std::string levmap ;
    DungeonCrawler* game;
    Tile* Portalchanger;
    string pathfile;
};
string countSteps(int r1,int c1,int r2,int c2);
#endif // LEVEL_H
