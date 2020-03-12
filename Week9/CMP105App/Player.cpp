#include "Player.h"

Player::Player()
{
	setPosition(sf::Vector2f(200, 400));
	setSize(sf::Vector2f(100, 100));
	texture.loadFromFile("gfx/MarioSheetT.png");
	setTexture(&texture);
}

Player::~Player()
{
}

void Player::handleUpdate(float dt)
{
}
