#include "Bat.h"
#include "Ball.h"
#include "Score.h"
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
	// Setting resolution manunally
	int resolution_x = 800;
	int resolution_y = 600;

	
	// Create and open a new window for the game
	sf::RenderWindow window(sf::VideoMode(resolution_x, resolution_y), "Pong Game 0.2", sf::Style::Titlebar | sf::Style::Close);
	
	// Creating bat1 at the bottom center of the screen
	Bat bat1(resolution_x / 2, resolution_y * 0.95);
	Bat bat2(resolution_x / 2, resolution_y * 0.05);

	// Creating Ball at center of screen
	Ball ball(resolution_x / 2, resolution_y / 2);

	// My color pallet
//	sf::Color colorDark(200, 200, 200, 255);
//	sf::Color bgColor(50, 50, 50, 255);

	sf::Color colorDark(248, 228, 132, 255);
	sf::Color bgColor(116, 28, 19, 255);




	bat1.setColor(colorDark);
	bat2.setColor(colorDark);
	ball.setColor(colorDark);

	// Managing scores
	int highestPlayer1, highestPlayer2;
	try {
		Score::loadScores(highestPlayer1, highestPlayer2);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception occurred: " << e.what() << std::endl;
		highestPlayer1 = 0, highestPlayer2 = 0;
	}

	//Adding text
	Text hud1, hud2;
	Text lastScore1, lastScore2;
	Text dashes;

	Font font;
	font.loadFromFile("fonts/Enrique-Round.ttf");
	hud1.setFont(font);
	hud2.setFont(font);
	lastScore1.setFont(font);
	lastScore2.setFont(font);

	lastScore2.setCharacterSize(20);
	dashes.setCharacterSize(60);

	hud1.setCharacterSize(40);
	hud1.setFillColor(colorDark);
	hud1.setPosition(resolution_x * 0.9, resolution_y * 0.6);

	lastScore1.setCharacterSize(20);
	lastScore1.setFillColor(colorDark);
	lastScore1.setPosition(resolution_x * 0.9, resolution_y * 0.6 + 45);

	hud2.setCharacterSize(40);
	hud2.setFillColor(colorDark);
	hud2.setPosition(resolution_x * 0.04, resolution_y * 0.34);

	lastScore2.setCharacterSize(20);
	lastScore2.setFillColor(colorDark);
	lastScore2.setPosition(resolution_x * 0.04, resolution_y * 0.34 - 20);
	
	dashes.setFont(font);
	dashes.setStyle(sf::Text::Bold);
	dashes.setFillColor(colorDark);
	dashes.setPosition(0, window.getSize().y / 2 - 30);
	
	// The clock is important for updating the game, it must exist before any updates
	Clock clock;

	int score1 = 0, score2 = 0;


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			// Handles closing the game from titlebar
			if (event.type == Event::Closed)
			{

				try {
					Score::saveScores(score1, score2);
				}
				catch (const std::exception& e) {
					std::cerr << "Exception occurred: " << e.what() << std::endl;
				}
				window.close();
			}
		}

		// Handle the pressing and releasing of the arrow keys for players
		if (Keyboard::isKeyPressed(Keyboard::Left))
			bat1.moveLeft();
		else
			bat1.stopLeft();

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			bat1.moveRight();
		}
		else {
			bat1.stopRight();
		}

		if (Keyboard::isKeyPressed(Keyboard::A))
			bat2.moveLeft();
		else
			bat2.stopLeft();

		if (Keyboard::isKeyPressed(Keyboard::D)) {
			bat2.moveRight();
		}
		else {
			bat2.stopRight();
		}


		// Handle ball hitting the bottom of screen
		if (ball.getPosition().top > window.getSize().y)
		{
			// Invert the direction of ball and centers it for new turn
			ball.reboundBatMult(window.getSize().x, window.getSize().y);
			score2++;
		}

		// Handle ball hitting top of the screen
		if (ball.getPosition().top < 0)
		{
			// Invert the direction of ball and centers it for new turn
			ball.reboundBatMult(window.getSize().x, window.getSize().y);
			score1++;

		}

		// Handle ball hitting sides ( to check hitting right side, we add the cordinates of the left to the size of width )
		if ((ball.getPosition().left < 0) || ((ball.getPosition().left + ball.getPosition().width ) > window.getSize().x))
		{
			ball.reboundSides();
		}

		// Has the ball hit the bat?
		if (ball.getPosition().intersects(bat1.getPosition()) || ball.getPosition().intersects(bat2.getPosition()))
		{
			// Hit detected so reverse the ball
			ball.reboundBatOrTop();
		}

		// Creating delta time
		// This will get the time of the last frame
		Time dt = clock.restart();
		ball.update(dt);
		bat1.update(dt);
		bat2.update(dt);

		// Updating the text
		std::stringstream str1, str2, strScore1, strScore2, strDashes;


		str1 << " " << score1;
		hud1.setString(str1.str());

		strScore1 << "HI " << Score::currentScore1;
		lastScore1.setString(strScore1.str());

		str2 << " " << score2;
		hud2.setString(str2.str());

		strScore2 << "HI " << Score::currentScore2;
		lastScore2.setString(strScore2.str());

		strDashes << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -";
		dashes.setString(strDashes.str());
		

		// Updating the whole window
		// Clear old window and set its color our color
		window.clear(bgColor);
		//Draw all of our objects
		window.draw(hud1);
		window.draw(hud2);
		window.draw(lastScore1);
		window.draw(lastScore2);
		window.draw(dashes);
		window.draw(bat1.getShape());
		window.draw(bat2.getShape());
		window.draw(ball.getShape());
		//Display it to screen
		window.display();

	}
	return 0;
}