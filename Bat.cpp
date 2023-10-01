#include "Bat.h"

// Bat constructor
Bat::Bat(float startX, float startY) : Position(startX, startY)
{

	Shape.setSize(sf::Vector2f(80, 5));
	Shape.setPosition(Position);
	Shape.setFillColor(sf::Color::Black);

	// To set the anchor to origin
	Shape.setOrigin(Shape.getSize() / (float)2);
}

void Bat::setColor(sf::Color color) {
	Shape.setFillColor(color);
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

void Bat::setPosition(int x, int y)
{
	Shape.setPosition(x, y);
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