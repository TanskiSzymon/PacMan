#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "PacMan.h"
#include "Ghost.h"
#include <iostream>
#include <windows.h>
#include "Map.h"
#include <sstream>
#include <string>

class Game
{
private:
	Map map;
	PacMan pacman;
	Ghost* ghost[3];
	sf::RenderWindow* window;
	sf::Event event;
	sf::RectangleShape wall;
	int sizeWindowX;
	int sizeWindowY;
	sf::Font font;
	sf::Text tekst;
public:
	Game();
	~Game();
	void start();
	void textWin();
	void textLose();
	void textScore();
	void text();
	void update();
	void render();
};
