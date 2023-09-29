#include "Bat.h"
#include <sstream>
#include <SFML/Graphics.hpp>

int main()
{
	// Setting resolution manunally
	int resolution_x = 800;
	int resolution_y = 600;

	//VideoMode vm(resolution_x, resolution_y);
	
	// Create and open a new window for the game
	sf::RenderWindow window(sf::VideoMode(resolution_x, resolution_y), "Pong Game 0.1", sf::Style::Titlebar | sf::Style::Close);
	
	// Creating bat1 at the bottom center of the screen
	Bat bat1(resolution_x / 2, resolution_y * 0.95);

	//Adding text
	Text hud;

	Font font;
	font.loadFromFile("fonts/Enrique-BoldRound.ttf");
	hud.setFont(font);

	hud.setCharacterSize(40);

	hud.setFillColor(Color::Black);
	hud.setPosition(resolution_y * 0.05, resolution_y * 0.05);
	
	// The clock is important for updating the game
	Clock clock;

	int score = 0;
	int lives = 3;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			// Handles closing the game from titlebar
			if (event.type == Event::Closed)
				window.close();
		}

		// Quit button
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			window.close();

		// Handle the pressing and releasing of the arrow keys for first player
		if (Keyboard::isKeyPressed(Keyboard::Left))
			bat1.moveLeft();
		else
			bat1.stopLeft();

		if (Keyboard::isKeyPressed(Keyboard::Right))
			bat1.moveRight();
		else
			bat1.stopRight();


		// Creating delta time
		// This will get the time before last frame
		Time dt = clock.restart();
		bat1.update(dt);

		// Updating the text
		std::stringstream str;
		str << "Score: " << score << std::endl << "Lives: " << lives;
		hud.setString(str.str());

		// Updating the whole window
		// Clear old window and set its color to grey
		window.clear(sf::Color(220,220,220,255));
		//Draw the text and bat
		window.draw(hud);
		window.draw(bat1.getShape());
		//Display it to screen
		window.display();

	}
	return 0;
}