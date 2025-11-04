#include "Tile.h"

bool Tile::CompareColors(SDL_Color& col1, SDL_Color& col2) //parse BMP file into col2 and Parse
{
	return col1.r == col2.r && col1.g == col2.g && col1.b == col2.b;
}

void Tile::Configure(SDL_Color& color, float x, float y, float size, SDL_Texture* textures[])
{





}
