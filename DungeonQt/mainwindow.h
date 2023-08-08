#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qgridlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <QMainWindow>
#include "Level.h"
#include"mybutton.h"
#include"startscreen.h"
class GraphicalUI;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(GraphicalUI* gui, QWidget *parent = nullptr);
    ~MainWindow();
    void draw();
    std::vector<std::vector<QLabel*>> getfieldlabel()const;
    std::vector<std::vector<QLabel*>> getfieldlabel2()const;
    std::vector<int> random_floor;
    QLabel * makelabel(int,int);
    void updateStatusBoard();
    void newMap()  ;
    void popup();
    void loadlevel();

public slots:
    void onMyButtonClicked(int number);
    void savelevel(int );
private:
    Ui::MainWindow *ui;
    QGridLayout* gridlayout;
    std::vector<std::vector<QLabel*>> fieldLabel;
    std::vector<std::vector<QLabel*>> fieldLabel2;
    std::array<std::array<mybutton*,3>, 3> buttons{};
    //StartScreen * startscreen;
    //void resizeEvent(QResizeEvent* event) override;
   GraphicalUI * gui=nullptr;
};

#endif // MAINWINDOW_H
