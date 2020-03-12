#pragma once
#include "Ball.h"
#include <vector>
#include <math.h>

class FallingBallManager
{
private:
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
public:
	FallingBallManager();
	~FallingBallManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
	int entityCount();
};