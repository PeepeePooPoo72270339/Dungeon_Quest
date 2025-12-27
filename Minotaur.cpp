#include "Minotaur.h"
#include <iostream>

void Minotaur::PathfindMoveUp()
{


}

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

void Minotaur::FindPath()
{
	//get the closest tile with the lowest f value
	CharacterTile;
}




