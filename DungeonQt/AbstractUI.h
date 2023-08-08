#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H


#include "Level.h"

class AbstractUI
{
public:
    AbstractUI();
    virtual ~AbstractUI();
    virtual void newMap(Level *);
    virtual void setlevel(Level *)=0;
    virtual void draw(Level*) = 0;
    virtual void EndePopUp();
private:
    Level * lev;
};

#endif // ABSTRACTUI_H
