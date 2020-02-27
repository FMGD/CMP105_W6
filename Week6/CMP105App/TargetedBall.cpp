#include "TargetedBall.h"

// Constructor
TargetedBall::TargetedBall()
{
	speed_ = 50.0f;
	acceleration_ = 50.0f;
	scale_ = 200.0f;
	target_ = sf::Vector2f(600, 300);

	velocity = sf::Vector2f(0, 0);

	// For initial velocity != 0
	//direction_ = target_ - getPosition();
	//direction_ = Vector::normalise(direction_);
	//velocity = (direction_ * speed_);
}

// Destructor
TargetedBall::~TargetedBall()
{

}

// Functions
void TargetedBall::update(float dt)
{
	//target_ = sf::Vector2f(window_->getSize().x - this->getSize().x, window_->getSize().y - this->getSize().y); // Set target to end right of window
	target_ = sf::Vector2f(input->getMouseX() - (getSize().x / 2), input->getMouseY() - (getSize().y / 2));  // Set target to position of cursor (center of object)
	moveToTarget(dt);
}


// Funtions 
void TargetedBall::handleInput(float dt)
{

}

void TargetedBall::setWindow(sf::RenderWindow* hwnd)
{
	window_ = hwnd;
}


void TargetedBall::moveToTarget(float dt)
{
	//Calculate direction
	direction_ = target_ - getPosition();
	direction_ = Vector::normalise(direction_);

	// Object with not acceleration
	//velocity = (direction_ * speed_); // v = u  (fixed speed)
	//sf::Vector2f pos = velocity * dt; // s = v*t

	// Object with acceleration
	velocity += (direction_ * acceleration_ ) * dt; // v = u + a*t (accelerate towards the point)
	sf::Vector2f pos = velocity * dt + 0.5f * (direction_ * acceleration_ ) * dt * dt; // s = ut + 1/2*a*t^2

	//std::cout << "Velocity x: " << velocity.x << " Velocity y: " << velocity.y  << "\n";
	
	//Move
	setPosition(getPosition() + pos);

	// If object is close enough to target
	if (Vector::magnitude(target_ - getPosition()) < 10.0f)
	{
		setPosition(target_);
		velocity = sf::Vector2f(0, 0);
	}

}