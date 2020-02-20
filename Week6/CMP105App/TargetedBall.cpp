#include "TargetedBall.h"

// Constructor
TargetedBall::TargetedBall()
{
	speed_ = 50.0f;
	acceleration_ = 50.0f;
	//target_ = sf::Vector2f(600, 300);
}

// Destructor
TargetedBall::~TargetedBall()
{

}

// Functions
void TargetedBall::update(float dt)
{
	target_ = sf::Vector2f(window_->getSize().x - this->getSize().x, window_->getSize().y - this->getSize().y); // Set target end right of window

	//Calculate direction and move
	direction_ = target_ - getPosition();
	direction_ = Vector::normalise(direction_);

	//velocity = (direction_ * speed_); // fixed speed
	velocity += (direction_ * acceleration_) * dt; // acceleterated towards the point
	setPosition(getPosition() + (velocity * dt));

	// If object is close enough to target
	if (Vector::magnitude(target_ - getPosition()) < 10.0f)
	{
		setPosition(target_);
	}

}


// Funtions 
void TargetedBall::handleInput(float dt)
{

}

void TargetedBall::setWindow(sf::RenderWindow* hwnd)
{
	window_ = hwnd;
}