#pragma once
#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "GameCharacter.h"
#include "Player.h"
#include "Tile.h"
#include "Minotaur.h"


const static std::string path_Hero = "Textures/Hero_sword.png";
const static std::string path_Minotaur = "Textures/Minotaur.png";
const static std::string path_Tiles[] = {"Textures/Tile_carpet_base.bmp", "Textures/Tile_carpet_blood_1.bmp", "Textures/Tile_carpet_bones.bmp"};
enum Direction{North, East, South, West};
const static int RoomSize = 10;
class DungeonGame
{
	//load string into texture array and parse that into texture

public:
	DungeonGame(float tileSizeX, float tileSizeY, int gridSizeX, int gridSizeY, SDL_Renderer* renderer);
	~DungeonGame();
	void Update(float DeltaTime);
	void LoadTextures();
	Player* Hero;
	Minotaur* Boss;
	void LoadRoom(const char* file = "Data/Rooms/Room01.bmp");
	void LoadRoom(int x, int y);
	void HandleInput(Direction dir);


	Tile Tiles[RoomSize][RoomSize];
	SDL_Texture* CarpetTextures[2];
	
private:
	float tileSizeX;
	float tileSizeY;
	SDL_Renderer* renderer;
	int gridSizeX;
	int gridSizeY;
};

