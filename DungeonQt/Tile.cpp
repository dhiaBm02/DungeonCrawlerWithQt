#include "Tile.h"
#include "Character.h"

Tile::Tile(std::string texture, Character *character, const int row, const int column)
    : texture(texture), character(character), row(row), col(column)
{

}
bool Tile::moveTo(Tile* destTile, Character* who) {
    {
        Tile* fromTile = onLeave(destTile, who);

        if (fromTile == nullptr)
            return false;

        Tile* realDest = destTile->onEnter(fromTile, who);
        if (realDest == nullptr) {
            return false;
        }
        if(!destTile->hasCharacter()) {
            fromTile->setCharacter(nullptr);
            realDest->setCharacter(who);
            who->setTile(realDest);
            return true;
        }
        int whoStren=who->getStrength();
        int npcStren=destTile->getCharacter()->getStrength();
        int whoHealth=who->getStamina();
        int npcHealth=destTile->getCharacter()->getStamina();
        std::string npctext=destTile->getCharacter()->getTexture();
        std::string whotext=who->getTexture();
        if(whotext==npctext) {
            std::cout<<"npc == who "<<std::endl;
            std::cout<< "whotext is   "<<whotext<<std::endl;
            std::cout<< "npctext is   "<<npctext<<std::endl;
            return false;
        }
        std::cout<<"npcheath is   "<<npcHealth<<std::endl;
        npcHealth-=whoStren;
        std::cout<<"who strenfg is   "<<whoStren<<std::endl;
        std::cout<<"neeew npcheath is   "<<npcHealth<<std::endl;
        if(npcHealth<=0) {
            destTile->getCharacter()->setStamina(0);
            std::cout<<"Dagegen ist tod !!!!!!"<<std::endl;
            fromTile->setCharacter(nullptr);
            realDest->setCharacter(who);
            who->setTile(realDest);
            return true;
        }
        else {
            destTile->getCharacter()->setStamina(npcHealth);
            whoHealth-=npcStren;
            if( whoHealth<=0){
                who->setStamina(0);
                fromTile->setCharacter(nullptr);
                std::cout<<"Spieler ist tod !!!!!!"<<std::endl;
                return true;
            }
            else who->setStamina(whoHealth);
            std::cout<<"No one is dead all in place"<<std::endl;
            return false;
        }

    }
}
std::string Tile::getTexture() const
{
    if (character == nullptr)
        return texture;
    else return character->getTexture();
}

bool Tile::hasCharacter()
{
    if (character == nullptr)
        return false;
    else return true;
}

void Tile::setCharacter(Character *newCharacter)
{
    character = newCharacter;
}

Tile::~Tile() {
}
void Tile::setTextur(string name){
    texture=name;
}
const int Tile::getRow() const {
    return row;
}

const int Tile::getCol() const {
    return col;
}

Character *Tile::getCharacter() const {
    return character;
}
