#include "Ball.h"

// Constructor
Ball::Ball()
{
	// Initialise gravity value (gravity 9.8, 200 scale, 200 px/s this will need to be uniform)
	scale_ = 200.0f;
	gravity_ = sf::Vector2f(0, 9.8f) * scale_;
	step_velocity_ = sf::Vector2f(0, 0); //TODO - Step velocity is Velocity of GameObject??
	jump_vector_ = sf::Vector2f(0, -4.0f) * scale_;
	is_jumping_ = false;
}

// Destructor
Ball::~Ball()
{

}

// Functions
void Ball::update(float dt)
{

	applyGravityForce(dt);

	checkGroundCollision();

}


// Funtions 
void Ball::handleInput(float dt)
{
	//Jump, check if already jumping
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!is_jumping_)
		{
			step_velocity_ = jump_vector_;
			is_jumping_ = true;
		}
	}

	// Set this object center where the cursor is it
	if (input->isMouseLDown()) 
	{
		setPosition(input->getMouseX() - (getSize().x/2), input->getMouseY() - (getSize().y/2));
	}

}

// Apply gravity force: increasing velocity
// Move shape by new velocity
void Ball::applyGravityForce(float dt)
{
	sf::Vector2f pos = step_velocity_ * dt + 0.5f * gravity_ * dt * dt; // s = ut + 1/2*a*t^2
	step_velocity_ += gravity_ * dt;  // v = u + at
	setPosition(getPosition() + pos);
}

// Check for collision with bottom of window/ground
// Having into account if the size of window change
void Ball::checkGroundCollision()
{
	sf::Vector2u game_limits(window_->getSize().x - this->getSize().x, window_->getSize().y - this->getSize().y);
	if (getPosition().y >= game_limits.y) // game_limits.y = ground
	{
		is_jumping_ = false;
		setPosition(getPosition().x, game_limits.y);
		step_velocity_ = (-step_velocity_) / 1.2f; // bouncing
		//step_velocity_ = sf::Vector2f(0,0); // Not bouncing
	}
}


void Ball::setWindow(sf::RenderWindow* hwnd)
{
	window_ = hwnd;
}