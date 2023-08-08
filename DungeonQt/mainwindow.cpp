#include "Portal.h"
#include "ui_mainwindow.h"
#include"mainwindow.h"
#include <QDebug>
#include <QResizeEvent>
#include <qdebug.h>
#include <qdebug.h>
#include "mybutton.h"
#include"Level.h"
#include"graphicalui.h"
#include "qmessagebox.h"


MainWindow::MainWindow(GraphicalUI *gui, QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow),
    gui(gui)
{
    ui->setupUi(this);
    fieldLabel.resize(Level::getMaxRow(), std::vector<QLabel*>(Level::getMaxCol(), nullptr));
    fieldLabel2.resize(Level::getMaxRow(), std::vector<QLabel*>(Level::getMaxCol(), nullptr));

    QStatusBar *status = new QStatusBar;
    status->showMessage("edededede");
    ui->statusbar->showMessage("erferferf");
    status=ui->statusbar;
    status->showMessage("789798798");
    int w=ui->label->width();
    int h=ui->label->height();
    ui->label->setPixmap(gui->bloody_frame.scaled(w,h,Qt::KeepAspectRatio));
    int k=0;
    auto * save =new mybutton(k,ui->centralwidget);
    ui->gridLayout->addWidget(save);
    connect(save, &mybutton::savelevel, this , &MainWindow::savelevel);
    QPixmap pixSave("../DungeonQt/save.jpeg");
    save->setIcon(pixSave);
    save->setIconSize(QSize(110,110));
    save->QPushButton::setStyleSheet("border:none");

    for(int r=2;r>-1;r--){
        for(int c=0;c<3;c++){
            k++;
            buttons.at(r).at(c)=new mybutton(k,ui->centralwidget);
            buttons.at(r).at(c)->setText(QString::number(k));
            buttons.at(r).at(c)->setIcon(gui->arrows[k-1]);
            buttons.at(r).at(c)->setIconSize(QSize(30,30));
            buttons.at(r).at(c)->QPushButton::setStyleSheet("border:none");
            ui->arrowsgrid->addWidget(buttons[r][c],r,c);
            connect(buttons.at(r).at(c), &mybutton::onMyButtonClicked, this , &MainWindow::onMyButtonClicked);
        }
    }

    for(int r=0;r<Level::getMaxRow();r++){
        for(int c=0;c<Level::getMaxCol();c++){
            auto* l = new QLabel(ui->centralwidget);
            auto* car = new QLabel(ui->centralwidget);
            char txt =gui->getgame()->getLevel()->getstandard()[10 * r + c];
            if(txt=='O') {
                auto * portal = dynamic_cast<Portal*>(gui->getgame()->getLevel()->getTile(c,r));
                if(portal->getPortalType()==1){
                l->setPixmap(gui->portalPix[0]) ;
                car->setPixmap(gui->portalPix[0]);
                }
                else {
                    l->setPixmap(gui->portalPix[1]);
                    car->setPixmap(gui->portalPix[1]);

                }
            }else if (txt=='#'){
                l->setPixmap(gui->wallpix);
                car->setPixmap(gui->wallpix);

            }else if(txt=='.'){
                int n=rand()%5;
                random_floor.push_back(n);
                car->setPixmap(gui->floorPix[n]);
                l->setPixmap(gui->floorPix[n]);
            }else if(txt=='X'){
                l->setPixmap(gui->DoorPix[0]);
                car->setPixmap(gui->DoorPix[0]);
            }else if(txt=='<'){
                l->setPixmap(gui->pit_rampPix[0]);
                car->setPixmap(gui->pit_rampPix[0]);
            }else if(txt=='_'){
                l->setPixmap(gui->pit_rampPix[1]);
                car->setPixmap(gui->pit_rampPix[1]);
            }else if(txt=='?'){
                l->setPixmap(gui->switchpix);
                car->setPixmap(gui->switchpix);
            }else if(txt=='L'){
                l->setPixmap(gui->exitPoint);
                car->setPixmap(gui->exitPoint);
            }else if(txt=='B'){
                l->setPixmap(gui->toolbox);
                car->setPixmap(gui->toolbox);
            }else if(txt=='Y'){
                l->setPixmap(gui->attacker);
                car->setPixmap(gui->attacker);
            }




            l->setScaledContents(true);
            l->setMinimumSize(40,40);
            l->setMaximumSize(40,40);
            car->setScaledContents(true);
            car->setMinimumSize(40,40);
            car->setMaximumSize(40,40);


            int carcol=gui->getgame()->getLevel()->getPlayer_col();
            int carrow=gui->getgame()->getLevel()->getPlayer_row();

            int zcol=gui->getgame()->getLevel()->getZombieCol();
            int zrow=gui->getgame()->getLevel()->getZombieRow();
            int zcol2=gui->getgame()->getLevel()->getZombieCol2();
            int zrow2=gui->getgame()->getLevel()->getZombieRow2();
            int zcol3=gui->getgame()->getLevel()->getZombieCol3();
            int zrow3=gui->getgame()->getLevel()->getZombieRow3();

            if((r==zcol3 && c==zrow3)){
                l->setPixmap(gui->attacker);
                std::cout<<"fvfvdfv"<<gui->getgame()->getLevel()->getMap()[r][c]->getTexture()<<std::endl;
                qDebug()<<QString::fromStdString("zombie  "+ gui->getgame()->getLevel()->getMap()[r][c]->getTexture());
            }
            if((r==zcol && c==zrow)||(r==zcol2 && c==zrow2)){
                l->setPixmap(gui->npcpix);
                std::cout<<"fvfvdfv"<<gui->getgame()->getLevel()->getMap()[r][c]->getTexture()<<std::endl;
                qDebug()<<QString::fromStdString("zombie  "+ gui->getgame()->getLevel()->getMap()[r][c]->getTexture());
            }

            if((carcol==c) && (carrow==r)){
                l->setPixmap(gui->playerPix[1]);
                qDebug()<<QString::fromStdString("player "+ gui->getgame()->getLevel()->getMap()[carrow][carcol]->getTexture());
     }


            fieldLabel.at(r).at(c) = l;
            fieldLabel2.at(r).at(c) = car;

            ui->fieldgrid->addWidget(car,r,c);
            ui->fieldgrid->addWidget(l,r,c);
            updateStatusBoard();


        }
    }
}
void MainWindow::savelevel(int i){
    this->gui->getgame()->savelevel();
}


QLabel* MainWindow::makelabel(int row,int col){
   auto* l = new QLabel(ui->centralwidget);
   ui->fieldgrid->addWidget(l,row,col);
   l->lower();
   return l;
}

void MainWindow::onMyButtonClicked(int number)
{
 qDebug()<<"hey it is on my button clicked here from nbr "<<number;

   Character * player=gui->getgame()->getCharacter();
   gui->getgame()->turn(number,player);
   if(!gui->getgame()->ischange){
   NPC* npc1= gui->getgame()->getLevel()->getNPC("M");
   NPC* npc2= gui->getgame()->getLevel()->getNPC("N");
   NPC* npc3= gui->getgame()->getLevel()->getNPC("Y");  
   npc3->setPos2(this->gui->getlevel()->getNPC("Y")->getTile());
   int mov1= npc1->getController()->move();
   int mov2= npc2->getController()->move();
   int mov3= npc3->getController()->move();
   cout<<"move is = " <<mov3<<endl;
   //npc3->setPos(this->gui->getlevel()->getNpcPos());

   gui->getgame()->turn(mov2,npc2);
   gui->getgame()->turn(mov1,npc1);
   gui->getgame()->turn(mov3,npc3);
   }else{
       gui->getgame()->ischange=false;
   }
   gui->draw(gui->getgame()->getLevel());
}
MainWindow::~MainWindow()
{
    delete ui;
}
std::vector<std::vector<QLabel*>> MainWindow:: getfieldlabel()const{
    return fieldLabel;
}
std::vector<std::vector<QLabel*>> MainWindow:: getfieldlabel2()const{
    return fieldLabel2;
}
void MainWindow::updateStatusBoard()
{

   string health=std::to_string(gui->getgame()->getCharacter()->getStamina());
   string attack=std::to_string(gui->getgame()->getCharacter()->getStrength());
   string msg="     Player'Health = " + health +" #####    Player'Strenght = " + attack ;
   ui->statusbar->showMessage(QString::fromStdString(msg));

}

void MainWindow::newMap()
{
    for(int r=0;r<Level::getMaxRow();r++){
        for(int c=0;c<Level::getMaxCol();c++){
            char txt =gui->getlevel()->getstandard()[10 * r + c];
            if(txt=='O') {
                auto * portal = dynamic_cast<Portal*>(gui->getgame()->getLevel()->getTile(c,r));
                if(portal->getPortalType()==1){
                fieldLabel[r][c]->setPixmap(gui->portalPix[0]) ;
                fieldLabel2[r][c]->setPixmap(gui->portalPix[0]);
                }
                else {
                    fieldLabel[r][c]->setPixmap(gui->portalPix[1]);
                    fieldLabel2[r][c]->setPixmap(gui->portalPix[1]);
                }
            }else if (txt=='#'){
                fieldLabel[r][c]->setPixmap(gui->wallpix);
                fieldLabel2[r][c]->setPixmap(gui->wallpix);

            }else if(txt=='.'){
                int n=rand()%5;
                random_floor.push_back(n);
                fieldLabel[r][c]->setPixmap(gui->floorPix[n]);
                fieldLabel2[r][c]->setPixmap(gui->floorPix[n]);
            }else if(txt=='X'){
                fieldLabel[r][c]->setPixmap(gui->DoorPix[0]);
                fieldLabel2[r][c]->setPixmap(gui->DoorPix[0]);
            }else if(txt=='<'){
               fieldLabel[r][c]->setPixmap(gui->pit_rampPix[0]);
                fieldLabel2[r][c]->setPixmap(gui->pit_rampPix[0]);
            }else if(txt=='_'){
               fieldLabel[r][c]->setPixmap(gui->pit_rampPix[1]);
                fieldLabel2[r][c]->setPixmap(gui->pit_rampPix[1]);
            }else if(txt=='?'){
                fieldLabel[r][c]->setPixmap(gui->switchpix);
                fieldLabel2[r][c]->setPixmap(gui->switchpix);
            }else if(txt=='L'){
               fieldLabel[r][c]->setPixmap(gui->exitPoint);
                fieldLabel2[r][c]->setPixmap(gui->exitPoint);
            }else if(txt=='Y'){
                fieldLabel[r][c]->setPixmap(gui->attacker);
                 fieldLabel2[r][c]->setPixmap(gui->attacker);
             }

            fieldLabel[r][c]->setScaledContents(true);
            fieldLabel[r][c]->setMinimumSize(40,40);
            fieldLabel[r][c]->setMaximumSize(40,40);
            fieldLabel2[r][c]->setScaledContents(true);
            fieldLabel2[r][c]->setMinimumSize(40,40);
            fieldLabel2[r][c]->setMaximumSize(40,40);

            int carcol=gui->getlevel()->getPlayer_col();
            int carrow=gui->getlevel()->getPlayer_row();

            int zcol=gui->getlevel()->getZombieCol();
            int zrow=gui->getlevel()->getZombieRow();
            int zcol2=gui->getlevel()->getZombieCol2();
            int zrow2=gui->getlevel()->getZombieRow2();

            /*if((r==zcol && c==zrow)||(r==zcol2 && c==zrow2)){
                fieldLabel[r][c]->setPixmap(gui->npcpix);
                std::cout<<"fvfvdfv"<<gui->getlevel()->getMap()[r][c]->getTexture()<<std::endl;
                qDebug()<<QString::fromStdString("zombie  "+ gui->getlevel()->getMap()[r][c]->getTexture());
            }
                if((carcol==c) && (carrow==r)){
                fieldLabel[r][c]->setPixmap(gui->playerPix[1]);
                qDebug()<<QString::fromStdString("player "+ gui->getlevel()->getMap()[r][c]->getTexture());
                }
                */
                fieldLabel[r][c]->raise();
            fieldLabel2[r][c]->lower();
            updateStatusBoard();

        }
    }

}

void MainWindow::popup()
{
  auto* mes=new QMessageBox();
  mes->setText("Spieler ist tod");
  mes->exec();
  close();
}

