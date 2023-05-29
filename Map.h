#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>


class Map
{
protected:
	sf::Image bg;
	sf::Texture texture;
	sf::RectangleShape background;
	std::vector<sf::RectangleShape> wall;
	std::vector<sf::CircleShape> point;
	std::vector<int> loadedMap;
	int nofPoints;
public:
	int pointSize();
	void collectPoint(int);
	void draw(sf::RenderWindow*);
	Map();
	~Map();
	int wallSize();
	sf::Vector2f getPosition(int);
	sf::Vector2f getPositionPoint(int);
	void loadMap();
	void convertMap();
};
