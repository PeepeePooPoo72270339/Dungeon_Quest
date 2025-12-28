#pragma once
#include "GameCharacter.h"
class Minotaur :
    public GameCharacter
{
public:
    Tile* BossTile;
    void PathfindMoveUp();
    int PlayerX;
    int PlayerY;
    void FindPlayer(int PlayerX, int PlayerY);
    void FindPath(int MovePos);
    void SetStartPosition();
    int MoveDirection;
    //Stores both the minotaur and the Player's locations hich can then later be used for pathfinding
    int PlayerLocation[2] = {10,10};
    int MinotaurLocation[2] = {CoordinateX,CoordinateY};

};

