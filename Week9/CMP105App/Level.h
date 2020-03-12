#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "BeachBallManager.h"
#include "FallingBallManager.h"
#include "Player.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	std::string count;

	sf::RenderWindow* window;
	Input* input;

	Player player;
	sf::Font font;
	sf::Text entityCount;
	BeachBallManager manager;
	FallingBallManager fallingManager;
};