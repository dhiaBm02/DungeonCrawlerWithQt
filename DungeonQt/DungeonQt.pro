
QT += core gui
greaterThan ( QT_MAJOR_VERSION , 4) : QT += widgets
CONFIG += c ++11 console


SOURCES += \
        AbstractController.cpp \
        AbstractUI.cpp \
        Aktive.cpp \
        Character.cpp \
        Door.cpp \
        Dungeoncrawler.cpp \
        Floor.cpp \
    Graph.cpp \
        Level.cpp \
        Passive.cpp \
        Pit_Rampe.cpp \
        Portal.cpp \
        Switch.cpp \
        TerminalUI.cpp \
        Tile.cpp \
        Wall.cpp \
    astern.cpp \
    attackcontroller.cpp \
        graphicalui.cpp \
    intlist.cpp \
    levelchanger.cpp \
        main.cpp \
        mainwindow.cpp \
        mybutton.cpp \
        myclass.cpp \
        myscreen.cpp \
        newclass.cpp \
        startscreen.cpp\
    theList.cpp \
    toolbox.cpp \
    www.cpp

HEADERS += \
    AbstractController.h \
    AbstractUI.h \
    Aktive.h \
    Character.h \
    Door.h \
    Dungeoncrawler.h \
    Floor.h \
    Graph.h \
    Level.h \
    Passive.h \
    Pit_Rampe.h \
    Portal.h \
    Switch.h \
    TerminalUI.h \
    Tile.h \
    Wall.h \
    attackcontroller.h \
    graphicalui.h \
    intlist.h \
    levelchanger.h \
    mainwindow.h \
    mybutton.h \
    myclass.h \
    myscreen.h \
    newclass.h \
    startscreen.h\
    theList.h \
    toolbox.h \
    json.hpp
FORMS += \
    mainwindow.ui\
    myscreen.ui

DISTFILES += \
    arrow_left.png \
    nlohmann.hpp.txt

# Default rules for deployment.
 qnx: target.path = /tmp/$${TARGET}/bin
 else: unix:!android: target.path = /opt/$${TARGET}/bin
 !isEmpty(target.path): INSTALLS += target

