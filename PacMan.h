#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Map.h"
#include "Ghost.h"

class Ghost;

class PacMan
{
protected:
	sf::CircleShape body;
	float size;
	bool dead;
	Ghost* ghost[3];
	Map* myMap;
	int score;
	sf::Vector2f position;
	float velocityX, velocityY;
	sf::Image R,L,D,U;
	sf::Texture skinR, skinL, skinD, skinU;
public:
	int getScore();
	void move();
	void colisions();
	float getVelocityX();
	float getVelocityY();
	float getSize();
	void setVelocity(float, float);
	void update();
	PacMan();
	~PacMan();
	bool isDead();
	sf::Vector2f getPosition();
	void setMap(Map*);
	void setGhost(Ghost*,int);
	void reset();
	void draw(sf::RenderWindow*);
	void setDead(bool _dead);
	void setPosition(float x, float y);
};
