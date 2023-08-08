#include "TerminalUI.h"
#include "Dungeoncrawler.h"

TerminalUI::TerminalUI(DungeonCrawler* game) {
    std::cout << "Game Display ON" << std::endl;
    this->game =game;
    this->mylevel=game->getLevel();
    NPC* npc1 = mylevel->getNPC("N");
    NPC* npc2 = mylevel->getNPC("M");
    int movingDir;
    do {
        draw(mylevel);
        int movingDir = getInput();
        int npc1dir = npc1->getController()->move();
        int npc2dir = npc2->getController()->move();

        if (movingDir != 0 and movingDir != 5) {
            game->turn(movingDir, game->getCharacter());
        }
        if (npc1dir != 0 and npc1dir != 5) {
            game->turn(npc1dir, npc1);
        }
        if (npc2dir != 0 and npc2dir != 5) {
            game->turn(npc2dir, npc2);
        }
    } while (movingDir != 0);
}
void TerminalUI::setlevel(Level *) {

}


void TerminalUI::draw(Level *level) {
    std::cout << "draw in TerminalUI..." << std::endl;

    for (int y = 0; y < Level::getMaxCol(); y++) {
        for (int x = 0; x < Level::getMaxRow() ; x++) {
            std::cout << level->getTile(x, y)->getTexture() << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << "7  8  9\n"
                 "4  5  6\n"
                 "1  2  3\n"
                 "0  ---> ";
    std::cin >> _input;
}

int TerminalUI::getInput() {
    return _input;
}


