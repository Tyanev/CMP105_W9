#pragma once
#include "Ball.h"
#include <vector>
#include <math.h>

class BeachBallManager
{
private:
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
public:
	BeachBallManager();
	~BeachBallManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
	int entityCount();
};

