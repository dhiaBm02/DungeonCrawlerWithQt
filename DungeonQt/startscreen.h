#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include<QDialog>
class QCheckBox;
 class QLabel;
 class QLineEdit;
  class QPushButton;

  namespace Ui{
  class StartScreen;
  }
class StartScreen:public QDialog
{
   Q_OBJECT
public slots:

public:
    explicit StartScreen(QWidget*parent = nullptr);
    ~StartScreen();
private:
    Ui::StartScreen * uis;

};

#endif // STARTSCREEN_H
