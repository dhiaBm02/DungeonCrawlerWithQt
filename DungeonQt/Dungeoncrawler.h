#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H

#include "AbstractUI.h"
#include "Level.h"
#include "Character.h"
#include "Passive.h"
#include<vector>
#include"theList.h"

using namespace std;
class DungeonCrawler:public Passive
{
public:
    DungeonCrawler(bool);
    void turn(int movingDir,Character* who);
    Level * getLevel()const;
    Character* getCharacter()const;
    void notify(Aktive *source) override;
    vector<Level *> getLevels() const;
    bool  ischange=false;
    void newGame();
    myList<Level *> getMylevels() const;
    void savelevel();
    void loadlevel();
    void manageCharachter(Character* who,int row,int col,int);
private:
    myList<Level*> * mylevels=new myList<Level*>;
    Level* currentLvl=nullptr;
    Level* newlevel=nullptr;

    vector<Level *> levels;
    Character* player = new Character("C",500,30);
    AbstractUI* cmd;
     string map1;
     string map2;

};

#endif // DUNGEONCRAWLER_H
