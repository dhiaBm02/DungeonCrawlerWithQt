#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <qpushbutton.h>


class mybutton:public QPushButton
{
    Q_OBJECT
signals:
    void onMyButtonClicked(int number);
    void startisbegan(int number);
    void savelevel(int number);
    void loadlevel();
public:
    mybutton(int number, QWidget* parent = nullptr);
private slots:
    void onClicked();
    void hidestart();
    void save();
    void load();
private:
    int number;
};

#endif // MYBUTTON_H
