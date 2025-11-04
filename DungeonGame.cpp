#include "DungeonGame.h"

DungeonGame::DungeonGame(float tileSizeX, float tileSizeY)
{



}

DungeonGame::~DungeonGame()
{



}

void DungeonGame::LoadTextures(SDL_Renderer* renderer)
{




}

void DungeonGame::LoadRoom(const char* file)
{
	SDL_Surface* surface = SDL_LoadBMP(file);
	const SDL_PixelFormatDetails* pixelDetails = SDL_GetPixelFormatDetails(surface->format);
	const Uint8 bpp = SDL_BYTESPERPIXEL(surface->format);
	SDL_Color col;

	for (int y = 0; y < surface->h; y++) 
	{
		for (int x = 0; x < surface->w; x++) 
		{
			Uint8* pixel = static_cast<Uint8*>(surface ->pixels) + y * surface ->pitch + x * bpp;
			SDL_GetRGB(*reinterpret_cast<Uint32*>(pixel), pixelDetails, NULL, &col.r, &col.g, &col.b); // gets RGB value of pixels to be interpreted by game
			//if Rgb value = black, create tile player can't walk on, if white, create one they can walk on
		
		
		}
	


	}


}





//void Load_Textures()
//{
  //  SDL_Surface* surf = IMG_Load(heroPath);
   // heroTexture = SDL_CreateTextureFromSurface(renderer, surf);
 //   SDL_SetTextureScaleMode(heroTexture, SDL_SCALEMODE_NEAREST);

//}