#ifndef CHARACTER_H
#define CHARACTER_H


#include <string>
#include "AbstractController.h"
#include"attackcontroller.h"
class Tile;

class Character
{
public:
    explicit Character(std::string textur , int , int );
    const std::string &getTexture() const;
    void setTile(Tile *tile);
    int getlastmov()const;
    void setlastmove(int);
    int getMaxHP()const;
private:
    std::string texture;
    Tile* tile = nullptr;
    int lastmove =4;
     int stamina;
     int strength;

public:
     Tile *getTile() const;
     int getStrength() const;
     void setStamina(int newStamina);
     int getStamina() const;
     void setStrength(int newStrength);
};
class NPC:public Character{
public:
    NPC(string text , string mov,int,int);
    NPC(string text , string mov,int,int,AbstractController*);
    ~NPC();
    void setPos(Tile*);    void setPos2(Tile*);

    AbstractController* getController()const;
    AbstractController* Controller;
};
#endif // CHARACTER_H
