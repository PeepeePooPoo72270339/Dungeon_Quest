#pragma once
#include "GameCharacter.h"
class Minotaur :
    public GameCharacter
{
public:
    Tile* BossTile;
    void PathfindMoveX();
    int PlayerLocation[10][10];
};

