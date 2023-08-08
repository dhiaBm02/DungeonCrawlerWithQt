//
// Created by louss on 11/30/2022.
//

#include "Aktive.h"
#include"Passive.h"

Aktive::Aktive() {

}

Aktive::~Aktive() {

}

void Aktive::attach(Passive *observer ) {
    if (findObserver(observer) == -1) {
        Passive_Container.push_back(observer);
    }

}

void Aktive::detach(Passive* observer) {
    if (int index = findObserver(observer) != -1) {
        Passive_Container.erase(Passive_Container.begin() + index);
    }
}
void Aktive::activate() {
    for (auto observer : Passive_Container) {
        observer->notify(this);
    }
}
int Aktive::findObserver(Passive* observer) {
    std::size_t size = Passive_Container.size();

    if (size == 0)
        return -1;

    for (int i = 0; i < size; i++) {
        if (Passive_Container.at(i) == observer) {
            return i;
        }
    }
    return -1;
}

/*

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
