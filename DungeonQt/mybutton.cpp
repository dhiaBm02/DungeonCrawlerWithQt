#include "mybutton.h"

mybutton::mybutton(int number, QWidget *parent): QPushButton(parent), number(number)
{
    connect(this, &mybutton::clicked, this, &mybutton::onClicked);
    connect(this, &mybutton::clicked, this, &mybutton::hidestart);
    connect(this, &mybutton::clicked, this, &mybutton::save);
    connect(this, &mybutton::clicked, this, &mybutton::load);

}

void mybutton::onClicked()
{
    emit onMyButtonClicked(number);
}

void mybutton::hidestart(){
    emit startisbegan(number);
}
void mybutton::save(){
    emit savelevel(number);
}
void mybutton::load(){
    emit loadlevel();
}
