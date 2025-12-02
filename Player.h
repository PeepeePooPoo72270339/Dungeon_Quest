#pragma once
#include "GameCharacter.h"
class Player :
    public GameCharacter
{
 public:

      void MoveUp();

      void MoveDown();

      void MoveLeft();
 
      void MoveRight();
      
      void Setlocation();

      void StartLocation();

      Tile* PlayerTile[10][10];

      void GetPlayerTile();

};

