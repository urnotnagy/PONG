#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

class Game
{
private:
	void initVariables();
	void iniWindow();


public:
	//Constructors & Destructors
	Game();
	virtual ~Game();

	// Functions
	void update();
	void render();

};

