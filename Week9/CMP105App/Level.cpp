#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	count = "Entity count = " + std::to_string(manager.entityCount() + fallingManager.entityCount());
	entityCount.setFont(font);
	entityCount.setFillColor(sf::Color::Green);
	entityCount.setCharacterSize(24);
	entityCount.setPosition(10, 10);
	entityCount.setString(count);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::LBracket))
	{
		input->setKeyUp(sf::Keyboard::LBracket);
		manager.spawn();
	}
	if (input->isKeyDown(sf::Keyboard::RBracket))
	{
		input->setKeyUp(sf::Keyboard::RBracket);
		fallingManager.spawn();
	}
}

// Update game objects
void Level::update(float dt)
{
	manager.update(dt);
	fallingManager.update(dt);
	count = "Entity count = " + std::to_string(manager.entityCount() + fallingManager.entityCount());
	entityCount.setString(count);
}

// Render level
void Level::render()
{
	beginDraw();

	manager.render(window);
	fallingManager.render(window);
	window->draw(entityCount);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(sf::Color::Black));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}