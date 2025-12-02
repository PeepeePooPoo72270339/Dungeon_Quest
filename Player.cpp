#include "Player.h"
#include <iostream>

void Player::MoveUp()
{
	//tile at position (Player position y -1) 
	//move if walkable
	//Game->Tile[][] return walkable. if true, then walk
	CoordinateY -= 1;
	//this->tile[1][1];


	//first, check the bool on the tile above then only fire off if the tile is walkable

	//std::cout << "Player at position (" << CoordinateX << "," << CoordinateY << ") <<std::endl";
}

void Player::MoveDown()
{
	CoordinateY += 1;
	//std::cout << "Player at position (" << CoordinateX << "," << CoordinateY << ") <<std::endl";

}

void Player::MoveLeft()
{

	CoordinateX -= 1;
}

void Player::MoveRight()
{
	CoordinateX += 1;



}

void Player::Setlocation()
{

	Rect.y = CoordinateY * 100;
	Rect.x = CoordinateX * 100;

}

void Player::StartLocation()
{
	CoordinateX = 5;
	CoordinateY = 5;

}

void Player::GetPlayerTile()
{
   //this->PlayerTile[][] = CoordinateX and Coordinate y;

}



//Maybe add some player customization for the player
