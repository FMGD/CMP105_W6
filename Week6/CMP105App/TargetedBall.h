#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class TargetedBall :	public GameObject
{
private:
	sf::RenderWindow* window_;
	float speed_;
	float acceleration_;
	sf::Vector2f direction_;
	//sf::Vector2f velocity_;
	sf::Vector2f target_;

public:
	// Constructor
	TargetedBall();

	// Destructor
	~TargetedBall();

	// Functions
	void setWindow(sf::RenderWindow* hwnd);
	void update(float dt) override;
	void handleInput(float dt) override;

};

