#include "qapplication.h"
#include <iostream>
#include"Dungeoncrawler.h"
#include <QJsonObject>
#include<qjsonobject.h>
#include<QFile>
#include<QJsonArray>

using namespace std;

int main(int argc,char**argv)
{

    bool useGui= true;

    QApplication a(argc, argv);

    DungeonCrawler game(useGui);


    return useGui ? a.exec() : 0 ;
}
