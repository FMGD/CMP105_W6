#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Ball :	public GameObject
{
private:
	float scale_;
	sf::RenderWindow* window_;
	sf::Vector2f gravity_;
	sf::Vector2f step_velocity_;
	sf::Vector2f jump_vector_;
	bool is_jumping_;

public:
	// Constructor
	Ball();

	// Destructor
	~Ball();

	// Functions
	void setWindow(sf::RenderWindow* hwnd);
	void update(float dt) override;
	void handleInput(float dt) override;
	void applyGravityForce(float dt);
	void checkGroundCollision();

};

