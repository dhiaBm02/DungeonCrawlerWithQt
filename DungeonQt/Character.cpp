#include "Character.h"
#include "Tile.h"
using std::string;
Character::Character(std::string texture , int _stamina , int _strength)
    : texture(texture),stamina(_stamina),strength(_strength) {

}
int Character::getMaxHP()const{
    return 20+stamina*5;
}

void Character::setStrength(int newStrength)
{
    strength = newStrength;
}

int Character::getStamina() const
{
    return stamina;
}

void Character::setStamina(int newStamina)
{
    stamina = newStamina;
}

int Character::getStrength() const
{
    return strength;
}
const std::string &Character::getTexture() const {
    return texture;
}

void Character::setTile(Tile* tile) {
    this->tile = tile;
}

Tile * Character::getTile() const  {
    return tile;
}
int Character::getlastmov()const{
    return lastmove;
}
void Character::setlastmove(int mov){
    lastmove=mov;
}
//////////////////////////////////////////////
NPC::NPC(string s , string mov, int _stamina , int _strength) : Character(s,_stamina,_strength)  {
    Controller = new GuardController(mov);
}
NPC::NPC(string s , string mov, int _stamina , int _strength,AbstractController* con) :
    Character(s,_stamina,_strength) ,Controller(con)
{

}
AbstractController* NPC::getController() const {
    return Controller;
}
NPC::~NPC() = default;
void NPC::setPos(Tile *a){
   Controller->start=a;
}
void NPC::setPos2(Tile *a){
   Controller->start=a;
}
