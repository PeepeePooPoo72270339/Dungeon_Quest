#include "DungeonGame.h"
#include <SDL3/SDL.h>
DungeonGame::DungeonGame(float tileSizeX, float tileSizeY, int gridSizeX, int gridSizeY, SDL_Renderer* renderer)
{
	this->tileSizeX = tileSizeX;
	this->tileSizeY = tileSizeY;
	this->renderer = renderer;
	this->gridSizeX = gridSizeX;
	this->gridSizeY = gridSizeY;

	LoadTextures();
	const char* room = "Data/Rooms/Room01.bmp";
	const int numRoomsX = 4;
	const int numRoomsY = 4;
	int DunegonLayout[numRoomsX][numRoomsY];
	const char* roomFiles[] =
	{
		"Data/Rooms/Room01.bmp",
		"Data/Rooms/Room02.bmp",
		"Data/Rooms/Room3.bmp"

	};
	LoadRoom(room);

}


DungeonGame::~DungeonGame()
{
	delete this->Hero;


}

void DungeonGame::Update(float DeltaTime)
{
    Hero->SetLocation(tileSizeX);
    Boss->SetLocation(tileSizeX);
	//Game->Boss->PlayerLocation;
	//std::cout << "monster register player position" << Game->Boss->PlayerLocation << std::endl;

    //Setup for pathfinding monster and the variable related to it
	int PathfindMonsterX;
	int PathfindMonsterY;
	PathfindMonsterX = Boss->CoordinateX;
	PathfindMonsterY = Boss->CoordinateY;
	std:: cout << "Monster at position" << PathfindMonsterX << "," << PathfindMonsterY << std::endl;

	//Draw the tiles here
	for (int x = 0; x < gridSizeX; x++)
	{
		for (int y = 0; y < gridSizeY; y++)
		{
			SDL_RenderTexture(renderer, Tiles[x][y].Texture, NULL, &Tiles[x][y].Rect);
		}
	}
	SDL_RenderTexture(renderer, Hero->Texture, NULL, &Hero->Rect);
	SDL_RenderTexture(renderer, Boss->Texture, NULL, &Boss->Rect);
	// should fetch every single game object and render them depending on sprite

}



void DungeonGame::LoadTextures()
{
	SDL_ScaleMode scaleMode = SDL_SCALEMODE_NEAREST;
	this->Boss = new Minotaur;
	this->Hero = new Player;
	//Load all textures
	this->Boss->Texture = IMG_LoadTexture(renderer, path_Minotaur.c_str());
	SDL_SetTextureScaleMode(this->Boss->Texture, scaleMode);
	this->Hero->Texture = IMG_LoadTexture(renderer, path_Hero.c_str());
	SDL_SetTextureScaleMode(this->Hero->Texture, scaleMode);
	this->Boss->Rect.w = tileSizeX;
	this->Boss->Rect.h = tileSizeY;

	this->Hero->Rect.w = tileSizeX;
	this->Hero->Rect.h = tileSizeY;

	for (int i = 0; i <2; i++) 
	{

		this->CarpetTextures[i] = IMG_LoadTexture(renderer, path_Tiles[i].c_str()); //there is some kind of problem here that needs to be fixed

		SDL_SetTextureScaleMode(this->CarpetTextures[i], scaleMode);


	}

}

void DungeonGame::LoadRoom(const char* file)// parse the BMP file into here - successful
{
	SDL_Surface* surface = SDL_LoadBMP(file);
	const SDL_PixelFormatDetails* pixelDetails = SDL_GetPixelFormatDetails(surface->format);
	const Uint8 bpp = SDL_BYTESPERPIXEL(surface->format);
	SDL_Color col;
	SDL_Color Wall = { 0,0,0,255 }; // Unwalkable tile
	this->Hero->StartLocation();


	for (int y = 0; y <RoomSize && y < surface->h; y++) 
	{
		for (int x = 0; x <RoomSize && x < surface->w; x++)
		{
			Uint8* pixel = static_cast<Uint8*>(surface->pixels) + y * surface->pitch + x * bpp; //Get color of pixels
			SDL_GetRGB(*reinterpret_cast<Uint32*>(pixel), pixelDetails, NULL, &col.r, &col.g, &col.b); // gets RGB value of pixels to be interpreted by game
			// parse the color data into the tiles
			this->Tiles[x][y].CompareColors(col,Wall); //Managed to fetch color, Just need fix up col2
			//convert the string into a texture file
			this->Tiles[x][y].Configure(col, x, y, tileSizeX, this->CarpetTextures);
			this->Tiles[x][y].SetCoordinate(x, y);
			//this->Tiles[x][y].
			//Get the neighbouring tiles here
			
		};
	


	}

	


	//for (int y = 0; y < RoomSize && y < surface->h; y++)


}

void DungeonGame::LoadRoom(int x, int y)
{

	//int index = DungeonLayout[x][y];
	//const char* roomPath = RoomPaths[index].c_str();



}





//void Load_Textures()
//{
  //  SDL_Surface* surf = IMG_Load(heroPath);
   // heroTexture = SDL_CreateTextureFromSurface(renderer, surf);
 //   SDL_SetTextureScaleMode(heroTexture, SDL_SCALEMODE_NEAREST);

//}