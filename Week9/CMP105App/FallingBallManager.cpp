#include "FallingBallManager.h"

FallingBallManager::FallingBallManager()
{
	spawnPoint = sf::Vector2f(rand() % 676, -100);
	texture.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 40; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

FallingBallManager::~FallingBallManager()
{
}

void FallingBallManager::spawn()
{
	spawnPoint = sf::Vector2f(rand() % 1200, -100);
	int i = 0;
	for (i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(0, rand() % 200 - 100);
			balls[i].setPosition(spawnPoint);
			return;
		}
	}
	balls.push_back(Ball());
	balls[i].setAlive(true);
	balls[i].setTexture(&texture);
	balls[i].setSize(sf::Vector2f(100, 100));
	balls[i].setVelocity(0, rand() % 200 - 100);
	balls[i].setPosition(spawnPoint);
}

void FallingBallManager::update(float dt)
{
	// call update on all ALIVE balls
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}
	}
	deathCheck();
}

void FallingBallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().y > 775)
			{
				balls[i].setAlive(false);
			}
		}
	}
}

void FallingBallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
}

int FallingBallManager::entityCount()
{
	int q = 0;
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			q++;
		}
	}
	return q;
}
