#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
class Bat
{
private:

	Vector2f Position;
	// A Rectangle Shape object is necessary to render the bat
	RectangleShape Shape;
	float Speed = 500.0f;
	bool MovingRight = false;
	bool MovingLeft = false;

public:

	Bat(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(Time dt);

};





// Pong Recipe
/* 
	Making pong with oop, we need to set the main outlines first before moving into graphics
	in header files we declare functions and define our variables, in a .cpp file we will define the functions
	and in main.cpp, we have our main function

	In the bat class, will need:
	1- postion vector, rectangular shape, speed float, and bools for right and left movement
	
	2- The constructor will take the starting values and set them to the position vector, accordingly
		it will set the size of the shape and its position according to the position vector

	3- 4 functions for boolean movement

	4- Update function! will update movement according to the booleans and make sure to use time dt
		Make sure to update the position of the bat to the new positions




*/