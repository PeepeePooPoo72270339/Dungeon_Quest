#include "Tile.h"
#include <SDL3/SDL.h>
#include <iostream>
bool Tile::CompareColors(SDL_Color& col1, SDL_Color& col2) //parse BMP file into col1 and set col2 to black/white when BMP is equal to black, set walkable to false
{
	col2.r = 0;
	col2.g = 0;  //All of these should equal to black
	col2.b = 0;
	//Fetch the Color of the tile to bmp file
	col1.r;
	col1.g;
	col1.b;
	return col1.r == col2.r && col1.g == col2.g && col1.b == col2.b;
}

void Tile::Configure(SDL_Color& color, float x, float y, float size, SDL_Texture* textures[])
{
	if (color.r == 255 && color.g ==255)
	{
		this->Walkable = true;

	}
	if (Walkable == true)
	{
		this->Texture = textures[1];

		this->Rect.w = size;
		this->Rect.h = size;
		this->Rect.x = x;
		this->Rect.y = y;

	
	
	/*if (CompareColors(color, color))
	{
		this->Texture = textures[1];    // test for color comparing (doesn't work)


	}
	else
	{
		this -> Texture = textures[1];
	}

	
*/
	}
	else 
	{
		this->Texture = textures[1];
		//std::cout << "Tile configured at position (" << x << "," << y << ") <<std::endl;"
		this->Rect.w = size;
		this->Rect.h = size;
		this->Rect.x = x;
		this->Rect.y = y;
		std::cout << "Tile configured at position (" << x << "," << y << ") <<std::endl";
	}

	
}
