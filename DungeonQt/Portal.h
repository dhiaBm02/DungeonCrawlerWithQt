#ifndef PORTAL_H
#define PORTAL_H

#include "Tile.h"

class Portal : public Tile
{
public:
    explicit Portal(int row, int column, Tile* destination);
    virtual Tile* onEnter(Tile* fromTile, Character* who) override;
    virtual bool moveTo(Tile* destTile, Character* who) override;
    void setPortalType(int );
    int getPortalType()const;
    virtual void setDestination(Portal*);

protected:
    Tile* destination;
    int portalType;
};

#endif // PORTAL_H
