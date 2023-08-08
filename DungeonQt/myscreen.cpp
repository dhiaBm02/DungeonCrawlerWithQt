#include "myscreen.h"
#include "ui_myscreen.h"
#include <qgridlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include"mybutton.h"
#include <QResizeEvent>
#include <qdebug.h>
myscreen::myscreen(GraphicalUI *gui,QWidget *parent) :
    QDialog(parent),ui(new Ui::myscreen),
    gui(gui)
{
    ui->setupUi(this);
    QPixmap pix("../DungeonQt/startscreen__.png");
    QPixmap pixLOAD("../DungeonQt/load.png");
    QPixmap pixstart("../DungeonQt/new.png");
    int w=ui->background->width();
    int h=ui->background->height();
    mybutton * click=new mybutton(1);
    click->setIcon(pixstart);
    click->setIconSize(QSize(200,100));
    mybutton * load=new mybutton(1);
    load->setIcon(pixLOAD);
    load->setIconSize(QSize(200,100));
    ui->gridLayout_2->addWidget(load,200,100);
    ui->gridLayout->addWidget(click,200,100);

    ui->background->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->background->setScaledContents(true);
    ui->background->setBackgroundRole(QPalette::Shadow);

    connect(click,&mybutton::startisbegan,this,&myscreen::switchnow);
    connect(load,&mybutton::startisbegan,this,&myscreen::loadlevel);

}
void myscreen::switchnow(){
    gui->switchscreen();
}
void myscreen::loadlevel(){
    gui->getgame()->loadlevel();
    switchnow();
}
myscreen::~myscreen()
{
    delete ui;
}
