#ifndef TILE_H
#define TILE_H

#include <iostream>


class Character;

class Tile
{
public:
    explicit Tile(std::string texture, Character* character,  int row, int column);
    virtual std::string getTexture() const;
    bool hasCharacter();
    virtual bool moveTo(Tile* destTile, Character* who) ;
    virtual Tile* onEnter(Tile* fromTile, Character* who) = 0;
    virtual Tile* onLeave(Tile* destTile, Character* who) {return this;};
    void setCharacter(Character*);
    const int getRow() const;
    void setTextur(std::string);
    Character *getCharacter() const;

    const int getCol() const;
    virtual ~Tile();
protected:
    std::string texture;
    Character* character = nullptr;
    const int row;
    const int col;
};

#endif // TILE_H
