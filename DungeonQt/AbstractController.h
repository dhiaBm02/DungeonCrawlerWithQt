//
// Created by louss on 11/30/2022.
//

#ifndef PG2_DUNGEONCRAWLER_ABSTRACTCONTROLLER_H
#define PG2_DUNGEONCRAWLER_ABSTRACTCONTROLLER_H

#include "Level.h"
#include "Tile.h"
#include <string>

using namespace std;
class AbstractController {
public:
    AbstractController();
    virtual ~AbstractController();
    virtual int move() = 0;
    Tile* start =nullptr;
protected:
    string movPath;
    int index;
    Level* level=nullptr;
};

class GuardController : public AbstractController {
public:
    explicit GuardController(string s);
    ~GuardController() override;
    int move() override;
private:

};

#endif //PG2_DUNGEONCRAWLER_ABSTRACTCONTROLLER_H
