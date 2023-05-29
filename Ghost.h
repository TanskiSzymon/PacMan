#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Map.h"
#include "PacMan.h"
#include <stdlib.h> 
#include <time.h>   
#include <iostream>
#include <windows.h>

class PacMan;

class Ghost
{
protected:
	sf::CircleShape body;
	float size;
	PacMan* myPacMan;
	Map* myMap;
	sf::Vector2f position;
	float velocityX, velocityY;
	sf::Image R, B, P;
	sf::Texture skinR, skinB, skinP;
public:
	virtual void move()=0;
	float getVelocityX();
	float getVelocityY();
	void colisions();
	void setVelocity(float, float);
	void update();
	sf::Vector2f getPosition();
	void setMap(Map*);
	void setPacMan(PacMan*);
	void draw(sf::RenderWindow*);
	void setPosition(float x, float y);
};

class Red : public Ghost {
public:
	Red();
	~Red();
	void move();
};

class Blue : public Ghost {
public:
	Blue();
	~Blue();
	void move();
};

class Pink : public Ghost {
public:
	Pink();
	~Pink();
	void move();
};

