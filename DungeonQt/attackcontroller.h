#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H

#include "Level.h"
#include <AbstractController.h>

class AttackController:public AbstractController{
 public:
      AttackController(Level*);
      int move()override;
};

#endif // ATTACKCONTROLLER_H
