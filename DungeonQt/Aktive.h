//
// Created by louss on 11/30/2022.
//

#ifndef PG2_DUNGEONCRAWLER_AKTIVE_H
#define PG2_DUNGEONCRAWLER_AKTIVE_H

#include <vector>
#include "Tile.h"
using namespace std;

class Passive;

class Aktive {
public:
    Aktive();
     ~Aktive();
    virtual void attach(Passive *) ;
    virtual void detach(Passive *);
    virtual void activate()=0;
protected:
    vector<Passive *> Passive_Container;
    virtual int findObserver(Passive*);
};

#endif //PG2_DUNGEONCRAWLER_AKTIVE_H



/*
 * #include "switch.h"

Switch::Switch(int row, int col) : Tile("?", nullptr, row, col), Active()
{

}

Tile* Switch::onEnter(Tile* fromTile, Character* who) {
    active();
    return this;
}
 *
 * #ifndef SWITCH_H
#define SWITCH_H
#include "floor.h"
#include "active.h"

class Switch : public Tile, public Active
{
public:
    explicit Switch(int row, int col);
    Tile* onEnter(Tile* fromTile, Character* who) override;
private:

};

#endif // SWITCH_H
 * #ifndef ACTIVE_H
#define ACTIVE_H


#include "passive.h"
#include <vector>

class Active {
public:
    Active();
    void attach(Passive*);
    void detach(Passive*);
    void active();
protected:
    std::vector<Passive*> observers;
    int findObserver(Passive*);
};

#endif // ACTIVE_H

#include "active.h"
#include "passive.h"
Active::Active()
{

}
void Active::attach(Passive* observer) {
    if (findObserver(observer) == -1) {
        observers.push_back(observer);
    }
}

void Active::detach(Passive* observer) {
    if (int index = findObserver(observer) != -1) {
        observers.erase(observers.begin() + index);
    }
}

void Active::active() {
    for (auto observer : observers) {
        observer->notify(this);
    }
}

int Active::findObserver(Passive* observer) {
    std::size_t size = observers.size();

    if (size == 0)
        return -1;

    for (int i = 0; i < size; i++) {
        if (observers.at(i) == observer) {
            return i;
        }
    }
    return -1;
}
*/





































