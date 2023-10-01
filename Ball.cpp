#include "Ball.h"

const float defaultSpeed = 400.0f;

Ball::Ball(float startx, float starty) {
	m_Position.x = startx;
	m_Position.y = starty;

	m_Speed = defaultSpeed;

	m_Shape.setSize(sf::Vector2f(10, 10));
	m_Shape.setPosition(m_Position);

	m_Shape.setFillColor(sf::Color::Black);
}

void Ball::setColor(sf::Color color) {
	m_Shape.setFillColor(color);
}

FloatRect Ball::getPosition()
{
	return m_Shape.getGlobalBounds();
}
RectangleShape Ball::getShape()
{
	return m_Shape;
}
float Ball::getXVelocity()
{
	return m_DirectionX;
}

// For bouncing physics, either sides or the bat
void Ball::reboundSides()
{
	m_DirectionX = -1 * m_DirectionX;
}
void Ball::reboundBatOrTop()
{
	m_DirectionY = -1 * m_DirectionY;
	if (m_Speed < 2000.0f) {
		m_Speed = m_Speed * 1.1f;
	}
}

// Resets the ball and inverts its direction ( for miss )
void Ball::reboundBottom(int screenwidth, int screenheight)
{
	m_Position.y = screenwidth * 0.1;
	m_Position.x = screenheight / 2;
	m_Speed = defaultSpeed;
}

void Ball::reboundBatMult(int screenwidth, int screenheight)
{
	m_Position.y = screenwidth / 2;
	m_Position.x = screenheight / 2;
	m_Speed = defaultSpeed;
	m_DirectionY = -m_DirectionY;
}

void Ball::update(Time dt)
{
	// Updating the position of the ball and moving it accordingly
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
	
	m_Shape.setPosition(m_Position);
}