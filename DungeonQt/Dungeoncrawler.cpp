#include "Dungeoncrawler.h"
#include "TerminalUI.h"
#include "Character.h"
#include"graphicalui.h"
#include "levelchanger.h"
#include <QJsonObject>
#include<qjsonobject.h>
#include<QFile>
#include<QJsonArray>
#include<QJsonDocument>
#include "json.hpp"
#include<fstream>


DungeonCrawler::DungeonCrawler(bool usegui)
{
    ifstream file("../DungeonQt/standard.json");
    nlohmann::json lev1;
    file >> lev1;
    map1 =lev1["map"];
    currentLvl = new Level(map1,this,"../DungeonQt/fild.json") ;
    ifstream file2("../DungeonQt/standard2.json");
    nlohmann::json lev2;
    file2 >> lev2;
    map2 =lev2["map"];

    currentLvl->placeCharacter(player, 5, 7);
    mylevels->push_back(currentLvl);

    newlevel= new Level(map2,this,"../DungeonQt/file2.json");
    mylevels->push_back(newlevel);


    if(usegui) cmd =new GraphicalUI(this);
    else cmd =new TerminalUI(this);

    cmd->setlevel(currentLvl);
}
Level * DungeonCrawler:: getLevel()const{
    return currentLvl;
}
Character* DungeonCrawler::getCharacter()const{
    return player;
}

void DungeonCrawler::notify(Aktive *source)
{
    ischange=true;
    auto* changer=dynamic_cast<LevelChanger*>(source);
    auto* gui=dynamic_cast<GraphicalUI*>(cmd);
    currentLvl=changer->getToLevel();
    gui->setlevel(changer->getToLevel());
    gui->changeMap();
}

vector<Level *> DungeonCrawler::getLevels() const
{
    return levels;
}

void DungeonCrawler::newGame()
{
    player->setStamina(100);
    player->setlastmove(5);
    levels[0]->placeCharacter(player,8,7);
    for(int i=0;i<levels.size();i++){
    levels[i]->getNPC("M")->setStamina(100);
    levels[i]->getNPC("N")->setStamina(100);
    levels[i]->getNPC("M")->setlastmove(5);
    levels[i]->getNPC("N")->setlastmove(5);
    levels[i]->placeCharacter(levels[i]->getNPC("M"),2,1);
    levels[i]->placeCharacter(levels[i]->getNPC("N"),1,3);
    }
    currentLvl=levels[0];

}

myList<Level *> DungeonCrawler::getMylevels() const
{
    return *mylevels;
}

void DungeonCrawler::turn(int movingDir, Character *who) {
    if(who->getStamina()==0) {
        if(who->getTexture()=="C") cmd->EndePopUp();
        //cout<<who->getTexture()<<"is tod"<<endl;
        return;
    }
    Tile* fromTile = who->getTile();
    int tRow = fromTile->getRow();
    int tCol = fromTile->getCol();

    switch (movingDir) {
        case 8:
            tCol--;
            break;
        case 2:
            tCol++;
            break;
        case 6:
            tRow++;
            break;
        case 4:
            tRow--;
            break;
        case 9:
            tRow++;
            tCol--;
            break;
        case 7:
            tRow--;
            tCol--;
            break;
        case 3:
            tRow++;
            tCol++;
            break;
        case 1:
            tRow--;
            tCol++;
            break;
        default:
            break;
    }
    //if(movingDir==5) return;
    who->setlastmove(movingDir);
    //qDebug()<<"the last mov " <<who->getlastmov();
    Tile* destTile = currentLvl->getTile(tRow, tCol);
    fromTile->moveTo(destTile, who);
}

void DungeonCrawler::savelevel(){
    nlohmann::json bigj;
    cout<<"level is changed"<<endl;
    string map=currentLvl->getmap();
    //QFile file(currentLvl->getpath().c_str());
    ofstream myfile(currentLvl->getpath());
    nlohmann::json  door;
    nlohmann::json _switch;
    nlohmann::json spieler;
    nlohmann::json zombies;
    bool isOpen=true;
    int d_row=currentLvl->getdoor()->getRow();
    int d_col=currentLvl->getdoor()->getCol();
    if(currentLvl->getTile(d_row,d_col)->getTexture()=="X") isOpen=false;

    door["isOpen?"]=isOpen;
    door["Row"]=currentLvl->getdoor()->getRow();
    door["Col"]=currentLvl->getdoor()->getCol();
    _switch["doors"]=door;
    _switch["Row"]=currentLvl->getswitch()->getRow();
    _switch["Col"]=currentLvl->getswitch()->getCol();
    spieler["Row"]=currentLvl->getch()->getRow();
    spieler["Col"]=currentLvl->getch()->getCol();
    spieler["Strength"]=currentLvl->getch()->getCharacter()->getStrength();
    spieler["MaxHP"]=currentLvl->getch()->getCharacter()->getStamina();
    spieler["Stamina"]=currentLvl->getch()->getCharacter()->getMaxHP();
    nlohmann::json zibi1;
    nlohmann::json zibi2;
    nlohmann::json zibi3;
    zibi1["Row"]=currentLvl->getNPC("M")->getTile()->getRow();
    zibi1["Col"]=currentLvl->getNPC("M")->getTile()->getCol();
    zibi1["Strength"]=currentLvl->getNPC("M")->getStrength();
    zibi1["Stamina"]=currentLvl->getNPC("M")->getMaxHP();
    zibi1["MaxHP"]=currentLvl->getNPC("M")->getStamina();
    zibi2["Row"]=currentLvl->getNPC("N")->getTile()->getRow();
    zibi2["Col"]=currentLvl->getNPC("N")->getTile()->getCol();
    zibi2["Strength"]=currentLvl->getNPC("N")->getStrength();
    zibi2["Stamina"]=currentLvl->getNPC("N")->getMaxHP();
    zibi2["MaxHP"]=currentLvl->getNPC("N")->getStamina();
    zibi3["Row"]=currentLvl->getNPC("Y")->getTile()->getRow();
    zibi3["Col"]=currentLvl->getNPC("Y")->getTile()->getCol();
    zibi3["Strength"]=currentLvl->getNPC("Y")->getStrength();
    zibi3["Stamina"]=currentLvl->getNPC("Y")->getMaxHP();
    zibi3["MaxHP"]=currentLvl->getNPC("Y")->getStamina();
    zombies["NPC M"]=zibi1;
    zombies["NPC N"]=zibi2;
    zombies["Attacker"]=zibi3;

    bigj["map"]=map;
    bigj["door"]=door;
    bigj["switch"]=_switch;
    bigj["player"]=spieler;
    bigj["zombies"]=zombies;

    myfile << bigj.dump(4);


}
void DungeonCrawler::loadlevel(){
    ifstream file(currentLvl->getpath());
    nlohmann::json big;
    file >> big;
    int prow=big["player"]["Row"];
    int pcol=big["player"]["Col"];
    int hp=big["player"]["MaxHP"];
    manageCharachter(currentLvl->getch()->getCharacter(),prow,pcol,hp);
    prow=big["zombies"]["NPC M"]["Row"];
    pcol=big["zombies"]["NPC M"]["Col"];
    hp=big["zombies"]["NPC M"]["MaxHP"];
    manageCharachter(currentLvl->getNPC("M"),prow,pcol,hp);
    prow=big["zombies"]["NPC N"]["Row"];
    pcol=big["zombies"]["NPC N"]["Col"];
    hp=big["zombies"]["NPC N"]["MaxHP"];
    manageCharachter(currentLvl->getNPC("N"),prow,pcol,hp);
    prow=big["zombies"]["Attacker"]["Row"];
    pcol=big["zombies"]["Attacker"]["Col"];
    hp=big["zombies"]["Attacker"]["MaxHP"];
    manageCharachter(currentLvl->getNPC("Y"),prow,pcol,hp);
    bool isOpen=big["door"]["isOpen?"];
    prow=big["door"]["Row"];
    pcol=big["door"]["Col"];
    if(isOpen) currentLvl->getTile(prow,pcol)->setTextur("/");
    else currentLvl->getTile(prow,pcol)->setTextur("X");
    cmd->draw(currentLvl);
}
void DungeonCrawler::manageCharachter(Character* who,int row,int col,int hp){
    int r,c;
    if(who->getTexture()=="C") {
         r=currentLvl->getch()->getRow();
         c=currentLvl->getch()->getCol();
    }else{
        r=currentLvl->getNPC(who->getTexture())->getTile()->getRow();
        c=currentLvl->getNPC(who->getTexture())->getTile()->getCol();
    }
    currentLvl->getTile(r,c)->setCharacter(nullptr);
    who->setStamina(hp);
    if(hp==0) return ;
    currentLvl->placeCharacter(who,row,col);


}

