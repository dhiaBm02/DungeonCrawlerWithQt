/********************************************************************************
** Form generated from reading UI file 'myscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSCREEN_H
#define UI_MYSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myscreen
{
public:
    QLabel *background;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;

    void setupUi(QDialog *myscreen)
    {
        if (myscreen->objectName().isEmpty())
            myscreen->setObjectName(QString::fromUtf8("myscreen"));
        myscreen->resize(1313, 660);
        background = new QLabel(myscreen);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(-10, 0, 1311, 621));
        background->setMouseTracking(false);
        background->setTabletTracking(false);
        background->setAutoFillBackground(true);
        background->setScaledContents(true);
        gridLayoutWidget = new QWidget(myscreen);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(100, 430, 491, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_2 = new QWidget(myscreen);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(760, 430, 481, 101));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);

        retranslateUi(myscreen);

        QMetaObject::connectSlotsByName(myscreen);
    } // setupUi

    void retranslateUi(QDialog *myscreen)
    {
        myscreen->setWindowTitle(QCoreApplication::translate("myscreen", "Dialog", nullptr));
        background->setText(QCoreApplication::translate("myscreen", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myscreen: public Ui_myscreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSCREEN_H
