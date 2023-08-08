#ifndef MYSCREEN_H
#define MYSCREEN_H
#include <QDialog>
#include"graphicalui.h"
namespace Ui {
class myscreen;
}

class myscreen : public QDialog
{
    Q_OBJECT

public:
    explicit myscreen(GraphicalUI *gui,QWidget *parent = nullptr);
    ~myscreen();
public slots:
    void switchnow();
    void loadlevel();
private:
    Ui::myscreen *ui;
    GraphicalUI  * gui;
};

#endif // MYSCREEN_H
