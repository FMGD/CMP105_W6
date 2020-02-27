#include "AngryBird.h"

// Constructor
AngryBird::AngryBird()
{
	speed_ = 0.0f;
	scale_ = 200.0f;
	distance_dragged_ = 0.0f;
	gravity_ = sf::Vector2f(0, 9.8f); // Gravity (down) in console is positive
	velocity = sf::Vector2f(0, 0);
	is_bouncing_ = false;
	launched_ = false;
}

// Destructor
AngryBird::~AngryBird()
{

}

// Functions
void AngryBird::update(float dt)
{
	
	if (launched_) 
	{
		move(dt);
		checkBouncing();
	}
}


// Funtions 
void AngryBird::handleInput(float dt)
{

	if (input->isMouseRDown() && !measuring_) //If the user has started to dragging
	{
		measuring_ = true;
		drag_start_point_ = sf::Vector2f(input->getMouseX() - (getSize().x / 2), input->getMouseY() - (getSize().y / 2));
	}
	else if (!input->isMouseRDown() && measuring_) //If the user has stopped of dragging
	{
		drag_end_point_ = sf::Vector2f(input->getMouseX() - (getSize().x / 2), input->getMouseY() - (getSize().y / 2));

		//Following pitagoras
		distance_dragged_ = sqrt(pow(drag_end_point_.x - drag_start_point_.x, 2) + pow(drag_end_point_.y - drag_start_point_.y, 2));

		if (distance_dragged_ > 0)
		{
			prepareToMove();
		}
		
		measuring_ = false;
	}
}

void AngryBird::setWindow(sf::RenderWindow* hwnd)
{
	window_ = hwnd;
}


void AngryBird::prepareToMove()
{
	// Calculate speed
	speed_ = distance_dragged_ / 4;

	// Calculate direction
	direction_ = drag_end_point_ - getPosition();
	direction_ = Vector::normalise(direction_);

	// Calculate Initial Velocity
	velocity = speed_ * direction_;

	// Now we can move the object
	launched_ = true;
}

// Move object
// With speed fixed and gravity
void AngryBird::move(float dt)
{
	// Calculate s
	sf::Vector2f displacement = velocity * dt + 0.5f * gravity_ * dt * dt; // s = ut + 1/2*a*t^2

	// Update velocity
	velocity += gravity_ * dt; // v = u + a*t

	//Move
	setPosition(getPosition() + displacement);
}

// Check for collision with window
// Having into account if the size of window change
void AngryBird::checkBouncing()
{
	//Limits right and bottom where the object can be visible
	sf::Vector2u game_limits(window_->getSize().x - this->getSize().x, window_->getSize().y - this->getSize().y);

	if (getPosition().x >= game_limits.x) // Collision right
	{
		setPosition(game_limits.x, getPosition().y);
		velocity.x = -velocity.x;
		std::cout << "Bouncing right\n";
	}
	else if(getPosition().x < 0) // Collision left
	{
		setPosition(0, getPosition().y);
		velocity.x = -velocity.x;
		std::cout << "Bouncing left\n";
	}

	if (getPosition().y >= game_limits.y) // Collision ground
	{
		setPosition(getPosition().x, game_limits.y);
		velocity.y = -velocity.y;
		std::cout << "Bouncing bottom\n";
	}
	else if (getPosition().y < 0) // Collision top
	{
		setPosition(getPosition().x, 0);
		velocity.y = -velocity.y;
		std::cout << "Bouncing top\n";
	}

}