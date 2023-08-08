#include "graphicalui.h"
#include"AbstractUI.h"
#include"mainwindow.h"
#include"myscreen.h"
#include<QString>
#include<QDebug>
#include<string>
#include"Portal.h"
#include "qmessagebox.h"
GraphicalUI::GraphicalUI(DungeonCrawler* _game):AbstractUI(),game(_game)
{   
    playerPix.push_back(QPixmap ("..\\DungeonQt\\char\\back\\char_back_3.png"));
    playerPix.push_back(QPixmap ("..\\DungeonQt\\char\\front\\char_front_2.png"));
    playerPix.push_back(QPixmap("..\\DungeonQt\\char\\left\\char_left_3.png"));
    playerPix.push_back(QPixmap("..\\DungeonQt\\char\\right\\char_right_3.png"));

    floorPix.push_back(QPixmap ("..\\DungeonQt\\floor\\floor1.png"));
    floorPix.push_back(QPixmap ("..\\DungeonQt\\floor\\floor2.png"));
    floorPix.push_back(QPixmap ("..\\DungeonQt\\floor\\floor3.png"));
    floorPix.push_back(QPixmap ("..\\DungeonQt\\floor\\floor5.png"));
    floorPix.push_back(QPixmap ("..\\DungeonQt\\floor\\floor4.png"));

    portalPix.push_back(QPixmap ("../DungeonQt/portal/portal1.png"));
    portalPix.push_back(QPixmap ("..\\DungeonQt\\portal\\portal2.png"));

    DoorPix.push_back(QPixmap ("..\\DungeonQt\\doors\\door1.png"));
    DoorPix.push_back(QPixmap ("..\\DungeonQt\\doors\\door2.png"));

    pit_rampPix.push_back(QPixmap ("..\\DungeonQt\\ramp.png"));
    pit_rampPix.push_back(QPixmap ("..\\DungeonQt\\pit.png"));
    pit_rampPix.push_back(QPixmap ("..\\DungeonQt\\zombie\\copy.png"));

    arrows.push_back(QPixmap ("..\\DungeonQt\\arrows\\arrow_down_left.png"));
    arrows.push_back(QPixmap ("..\\DungeonQt\\arrows\\arrow_down.png"));
    arrows.push_back(QPixmap ("..\\DungeonQt\\arrows\\arrow_down_right.png"));
    arrows.push_back(QPixmap ("..\\DungeonQt\\arrows\\arrow_left.png"));
    arrows.push_back(QPixmap ("..\\DungeonQt\\arrows\\arrow_skip.png"));
    arrows.push_back(QPixmap ("..\\DungeonQt\\arrows\\arrow_right.png"));
    arrows.push_back(QPixmap ("..\\DungeonQt\\arrows\\arrow_up_left.png"));
    arrows.push_back(QPixmap ("..\\DungeonQt\\arrows\\arrow_up.png"));
    arrows.push_back(QPixmap ("..\\DungeonQt\\arrows\\arrow_up_right.png"));

    screen= new myscreen(this);
    window = new  MainWindow(this);
    screen->show();
}
void GraphicalUI::switchscreen(){
    screen->hide();
    window->show();
}
Level * GraphicalUI::getlevel()const{
    return mylevel;
}
void GraphicalUI::setlevel(Level * lev){
    mylevel=lev;
    std::string str = mylevel->getTile(0,0)->getTexture();
    qDebug() << QString::fromStdString(str);
}

void GraphicalUI::changeMap()
{
    window->newMap();
}

void GraphicalUI::EndePopUp()
{
  window->popup();
}
void GraphicalUI::startisbegan(){

    screen->lower();
    window->raise();
}
void GraphicalUI::draw(Level* level){

    for(int r=0;r<Level::getMaxRow();r++){
        for(int c=0;c<Level::getMaxCol();c++){
            std::string txt =level->getTile(c,r)->getTexture();
            std::string pittxt =mylevel->getstandard();
            int lastmov;
            if(txt=="C"){
                lastmov=mylevel->getTile(c,r)->getCharacter()->getlastmov();
                if (lastmov==8||lastmov==9||lastmov==7){
                    window->getfieldlabel().at(r).at(c)->setPixmap(playerPix[0]);

                    char m =pittxt[10 * r + c];
                    if(m=='_'){
                        window->getfieldlabel().at(r).at(c)->lower();
                    }
                    else {
                        window->getfieldlabel().at(r).at(c)->raise();
                    }
                }
                else if (lastmov==1||lastmov==2||lastmov==3||lastmov==5){
                    window->getfieldlabel().at(r).at(c)->setPixmap(playerPix[1]);
                    std::string pittxt =mylevel->getstandard();
                    char m =pittxt[10 * r + c];
                    if(m=='_'){
                        window->getfieldlabel().at(r).at(c)->lower();
                    }else {
                        window->getfieldlabel().at(r).at(c)->raise();
                    }
                }
                else if (lastmov==4){
                    window->getfieldlabel().at(r).at(c)->setPixmap(playerPix[2]);
                    std::string pittxt =mylevel->getstandard();
                    char m =pittxt[10 * r + c];
                    if(m=='_'){
                        window->getfieldlabel().at(r).at(c)->lower();
                    }else {
                        window->getfieldlabel().at(r).at(c)->raise();
                    }
                }
                else if (lastmov==6){
                    window->getfieldlabel().at(r).at(c)->setPixmap(playerPix[3]);
                    std::string pittxt =mylevel->getstandard();
                    char m =pittxt[10 * r + c];
                    if(m=='_'){
                        window->getfieldlabel().at(r).at(c)->lower();
                    }else {
                        window->getfieldlabel().at(r).at(c)->raise();
                    }
                }
            }else if(txt=="M" || txt=="N"){
                window->getfieldlabel().at(r).at(c)->setPixmap(npcpix);
                window->getfieldlabel().at(r).at(c)->raise();
                char m =pittxt[10 * r + c];
                if(m=='_'){
                    window->getfieldlabel().at(r).at(c)->lower();
                }else {
                    window->getfieldlabel().at(r).at(c)->raise();
                }
            }
            else if(txt=="#") {
                window->getfieldlabel().at(r).at(c)->setPixmap(wallpix);
                window->getfieldlabel().at(r).at(c)->raise();
            }
            else if(txt=="O"){
                auto * portal = dynamic_cast<Portal*>(getgame()->getLevel()->getTile(c,r));
                if(portal->getPortalType()==1)window->getfieldlabel().at(r).at(c)->setPixmap(portalPix[0]);
                else window->getfieldlabel().at(r).at(c)->setPixmap(portalPix[1]);
                window->getfieldlabel().at(r).at(c)->raise();
            }
            else if(txt=="<"){
                window->getfieldlabel().at(r).at(c)->setPixmap(pit_rampPix[0]);
                window->getfieldlabel().at(r).at(c)->raise();
            }
            else if(txt=="_"){
                window->getfieldlabel().at(r).at(c)->setPixmap(pit_rampPix[1]);
                window->getfieldlabel().at(r).at(c)->raise();
            }
            else if(txt=="X"){
                window->getfieldlabel().at(r).at(c)->setPixmap(DoorPix[0]);
                window->getfieldlabel().at(r).at(c)->raise();
            }
            else if(txt=="?"){
                window->getfieldlabel().at(r).at(c)->setPixmap(switchpix);
                window->getfieldlabel().at(r).at(c)->raise();
            }
            else if(txt=="/"){
                window->getfieldlabel().at(r).at(c)->setPixmap(DoorPix[1]);
                window->getfieldlabel().at(r).at(c)->raise();
            }

            else if(txt=="."){

                window->getfieldlabel2().at(r).at(c)->raise();
            }
            else if(txt=="L"){
                window->getfieldlabel().at(r).at(c)->setPixmap(exitPoint);
                window->getfieldlabel().at(r).at(c)->raise();
            }
            else if(txt=="B"){
                window->getfieldlabel().at(r).at(c)->setPixmap(toolbox);
                window->getfieldlabel().at(r).at(c)->raise();
            }
            else if(txt=="Y"){
                window->getfieldlabel().at(r).at(c)->setPixmap(attacker);
                window->getfieldlabel().at(r).at(c)->raise();
            }
    }
}
    window->updateStatusBoard();

    win();
    lose();
}
DungeonCrawler * GraphicalUI::getgame()const {
    return game;
}

void GraphicalUI::win(){
    int c=game->getCharacter()->getTile()->getCol();
    int r=game->getCharacter()->getTile()->getRow();
    char txt=this->mylevel->getstandard()[10 * c + r];
    if (txt=='B'){
        QMessageBox msgBox;
        msgBox.setText(QString("Viel Glueck  ! sie haben gewonnen   "));
        msgBox.exec();
        window->close();
    }
}
void GraphicalUI::lose(){
    if (game->getCharacter()->getStamina()==0)
        window->popup() ;
}































