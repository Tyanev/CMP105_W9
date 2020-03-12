#pragma once

#include "Framework/GameObject.h"

class Player:
	public GameObject
{
private:
	sf::Vector2f speed;
	sf::Texture texture;
public:
	Player();
	~Player();

	void handleUpdate(float dt);

};

