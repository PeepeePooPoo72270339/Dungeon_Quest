#include "Minotaur.h"
#include <iostream>

void Minotaur::FindPlayer(int playerX, int playerY)
{
	//the location of the player stored onto a local array
	PlayerLocation[0] = playerX;
	PlayerLocation[1] = playerY;
	//prints the array for the player location
	/*int n = sizeof(PlayerLocation) / sizeof(PlayerLocation[1]);

	for (int i = 0; i < n; i++) {
		std::cout << PlayerLocation[i] << " ";
	}
	std::cout << std::endl;*/
	//prints the Array for it's own location
	/*int n = sizeof(MinotaurLocation) / sizeof(MinotaurLocation[1]);

	for (int i = 0; i < n; i++) {
		std::cout << MinotaurLocation[i] << " ";
	}
	std::cout << std::endl;*/

}
void Minotaur::FindPath(int MovePos)
{
	MoveDirection = MovePos;
	std::cout << MoveDirection << std::endl;

}

void Minotaur::SetStartPosition()
{
	CoordinateX = 8;
	CoordinateY = 4;
}

void Minotaur::PathfindMoveUp()
{
	std::cout << "Minotaur position" << CoordinateX << "," << CoordinateY << std::endl;
	//North = 1 East = 2 South = 3 West = 4
	if (MoveDirection == 1) 
	{
		CoordinateY -= 1;
	}
	if (MoveDirection == 2)
	{
		CoordinateX += 1;
	}
	if (MoveDirection == 3)
	{
		CoordinateY += 1;
	}
	if (MoveDirection == 4)
	{
		CoordinateX -= 1;
	}

}

