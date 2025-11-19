#pragma once  
#include "GameCharacter.h"  
#include "Tile.h"  
#include "DungeonGame.h"  
#include <SDL3/SDL_rect.h> // Include SDL_Rect  
#include <SDL3/SDL_render.h> // Include SDL_Texture  

class Player  
{  
public:  
	SDL_FRect Rect;
	SDL_Texture* Texture;
  void MoveUp(float tileSize);  
  void MoveDown(float tileSize);  
  void MoveLeft(float tileSize);  
  void MoveRight(float tileSize);  
};
