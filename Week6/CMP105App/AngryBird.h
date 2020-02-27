#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include <iostream>
class AngryBird :	public GameObject
{
	private:
		sf::RenderWindow* window_;
		float speed_;
		sf::Vector2f gravity_;
		sf::Vector2f direction_;
		float scale_;
		bool is_bouncing_;
		bool launched_;


		//Dragging
		sf::Vector2f drag_start_point_;
		sf::Vector2f drag_end_point_;
		bool measuring_ = false;
		float distance_dragged_ = 0;

	public:
		// Constructor
		AngryBird();

		// Destructor
		~AngryBird();

		// Functions
		void setWindow(sf::RenderWindow* hwnd);
		void update(float dt) override;
		void handleInput(float dt) override;
		void move(float dt);
		void prepareToMove();
		void checkBouncing();
};

