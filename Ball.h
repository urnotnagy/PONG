#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Ball
{
private:

	Vector2f m_Position;
	RectangleShape m_Shape;
	float m_Speed = 300.0f;
	float m_DirectionX = .2f;
	float m_DirectionY = .2f;
public:

	Ball(float startX, float startY);
	void setColor(sf::Color color);
	FloatRect getPosition();
	RectangleShape getShape();
	float getXVelocity();
	void reboundSides();
	void reboundBatOrTop();
	void reboundBottom(int screenwidth, int screenheigh);
	void reboundBatMult(int screenwidth, int screenheight);

	void update(Time dt);

};