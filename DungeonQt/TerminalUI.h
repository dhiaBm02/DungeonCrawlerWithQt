#ifndef PG2_DUNGEONCRAWLER_TERMINALUI_H
#define PG2_DUNGEONCRAWLER_TERMINALUI_H

#include "AbstractUI.h"
#include "Level.h"

class DungeonCrawler ;

class TerminalUI : public AbstractUI{
public:
    TerminalUI(DungeonCrawler *);
    void draw(Level* level) override;
    void setlevel(Level *) override;
    int getInput();
private:
    int _input;
    DungeonCrawler * game;
    Level* mylevel;
};


#endif //PG2_DUNGEONCRAWLER_TERMINALUI_H
