#include "BeachBallManager.h"

BeachBallManager::BeachBallManager()
{
	spawnPoint = sf::Vector2f(350, 250);
	texture.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 20; i++) 
	{ 
	balls.push_back(Ball());
	balls[i].setAlive(false); 
	balls[i].setTexture(&texture);
	balls[i].setSize(sf::Vector2f(100, 100));
	}
}

BeachBallManager::~BeachBallManager()
{
}

void BeachBallManager::spawn()
{
	int i = 0;
	for (i = 0; i < balls.size(); i++)
	{ 
		if (!balls[i].isAlive())
		{ 
			balls[i].setAlive(true);
			balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[i].setPosition(spawnPoint);
			return;
		}
	}
	balls.push_back(Ball());
	balls[i].setAlive(true);
	balls[i].setTexture(&texture);
	balls[i].setSize(sf::Vector2f(100, 100));
	balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
	balls[i].setPosition(spawnPoint);
}

void BeachBallManager::update(float dt)
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

void BeachBallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++) 
	{ 
		if (balls[i].isAlive()) 
		{ 
			if (balls[i].getPosition().x < -100) 
			{
				balls[i].setAlive(false); 
			}
			if (balls[i].getPosition().x > 675) 
			{ 
				balls[i].setAlive(false); 
			}
			if (balls[i].getPosition().y < -100) 
			{ 
				balls[i].setAlive(false); 
			}
			if (balls[i].getPosition().y > 650) 
			{ 
				balls[i].setAlive(false); 
			} 
		} 
	}
}

void BeachBallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++) 
	{
		if (balls[i].isAlive()) 
		{ 
			window->draw(balls[i]); 
		}
	}
}

int BeachBallManager::entityCount()
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
