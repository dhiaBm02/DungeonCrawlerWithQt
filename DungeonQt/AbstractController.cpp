//
// Created by louss on 11/30/2022.
//

#include "AbstractController.h"

AbstractController::AbstractController() {
}

AbstractController::~AbstractController() {
}


GuardController::GuardController(std::string _movPath) : AbstractController()
{
    movPath=_movPath;
    index = 0;
}

int GuardController::move() {
    if(index >= movPath.size()) {
        index = 0;
    }
    return movPath.at(index++) - '0';
}


GuardController::~GuardController() = default;

