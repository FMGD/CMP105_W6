#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ball_texture_.loadFromFile("gfx/Beach_Ball.png");
	ball_.setInput(in);
	ball_.setWindow(hwnd);
	ball_.setTexture(&ball_texture_);
	ball_.setSize(sf::Vector2f(32 * 4, 32 * 4));
	ball_.setPosition(300, 300);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ball_.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ball_.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball_);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}