#pragma once
#include "GameCharacter.h"
class Player :
    public GameCharacter
{

    virtual void MoveUp();

    virtual void MoveDown();

    virtual void MoveLeft();

    virtual void MoveRight();

};

