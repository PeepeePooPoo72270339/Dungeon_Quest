#pragma once
#include "GameCharacter.h"
class Player :
    public GameCharacter
{
 public:

      void MoveUp(float tileSize);

      void MoveDown(float tileSize);

      void MoveLeft();
 
      void MoveRight();

};

