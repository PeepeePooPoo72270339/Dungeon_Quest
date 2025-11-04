#include "Player.h"

void Player::MoveUp(float tileSize)
{
	Rect.y -= tileSize;
	//give the player a rectangle
	//give the player a sprite
}

void Player::MoveDown(float tileSize)
{
	Rect.y += tileSize;


}

void Player::MoveLeft(float tileSize)
{
	Rect.x -= tileSize;

}

void Player::MoveRight(float tileSize)
{
	Rect.x += tileSize;



}

//Maybe add some player customization for the player
