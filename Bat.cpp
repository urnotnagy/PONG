#include "Bat.h"


// Bat constructor
Bat::Bat(float startX, float startY) : Position(startX, startY)
{
//	Position.x = startX;
//	Position.y = startY;
	Shape.setSize(sf::Vector2f(80, 5));
	Shape.setPosition(Position);
	Shape.setFillColor(sf::Color::Black);

	// To set the anchor to origin
	Shape.setOrigin(Shape.getSize() / (float)2);
}


// Basic functions that the bat will need

FloatRect Bat::getPosition()
{
	return Shape.getGlobalBounds();
}
RectangleShape Bat::getShape()
{
	return Shape;
}
void Bat::moveLeft()
{
	MovingLeft = true;
}
void Bat::moveRight()
{
	MovingRight = true;
}
void Bat::stopLeft()
{
	MovingLeft = false;
}
void Bat::stopRight()
{
	MovingRight = false;
}

void Bat::update(Time dt)
{

	if (MovingLeft) {
		Position.x -= Speed * dt.asSeconds();
	}
	if (MovingRight) {
		Position.x += Speed * dt.asSeconds();
	}
	Shape.setPosition(Position);
}