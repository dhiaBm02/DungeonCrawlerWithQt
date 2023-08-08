#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H

//#include "C:\\Users\\louss\\OneDrive\\Bureau\\pg_prak2_updated\\AbstractUI.h"
//#include "C:\\Users\\louss\\OneDrive\\Bureau\\pg_prak2_updated\\AbstractUI.h"
#include "Dungeoncrawler.h"
#include "qpixmap.h"
#include<iostream>
#include<vector>
#include"AbstractUI.h"
#include"Level.h"

class MainWindow;
class myscreen;
class GraphicalUI:public AbstractUI
{
public:
    GraphicalUI(DungeonCrawler *);
    void draw(Level*)override;
    DungeonCrawler * getgame()const;
    Level* getlevel()const;
    void setlevel(Level *);
    vector<QPixmap> playerPix;
    vector<QPixmap> DoorPix;
    vector<QPixmap> floorPix;
    vector<QPixmap> portalPix;
    vector<QPixmap> pit_rampPix;
    QPixmap switchpix=QPixmap("..\\DungeonQt\\switch.png");
    QPixmap npcpix=QPixmap("..\\DungeonQt\\zombie\\zombie_left.png");
    QPixmap wallpix=QPixmap("..\\DungeonQt\\wall\\wall1.png");
    vector<QPixmap> arrows;
    QPixmap bloody_frame = QPixmap("..\\DungeonQt\\bloody_frame.png");
    void changeMap();
    void EndePopUp() override;
    void win();
    void lose();
    QPixmap exitPoint =QPixmap("..\\DungeonQt\\exit");
    QPixmap toolbox =QPixmap("..\\DungeonQt\\tool.jpg");
    QPixmap attacker=QPixmap("..\\DungeonQt\\attacker");
public slots:
    void startisbegan();
    void switchscreen();

private:
    MainWindow * window;
    myscreen* screen;
    std::vector<QPixmap> pixmapsArrows;
    DungeonCrawler* game=nullptr;
    Level * mylevel;

};

#endif // GRAPHICALUI_H
