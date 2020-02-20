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

	targeted_ball_.setInput(in);
	targeted_ball_.setWindow(hwnd);
	targeted_ball_.setTexture(&ball_texture_);
	targeted_ball_.setSize(sf::Vector2f(32 * 4, 32 * 4));
	targeted_ball_.setPosition(0, 0); // Target - Position A

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ball_.handleInput(dt);
	targeted_ball_.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ball_.update(dt);
	targeted_ball_.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball_);
	window->draw(targeted_ball_);
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