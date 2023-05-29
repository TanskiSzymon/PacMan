#include "PacMan.h"

PacMan::PacMan() {
	size = 40.f;
	body.setRadius((size/2));
	body.setFillColor(sf::Color::Yellow);
	dead = false;
	velocityX = 0;
	velocityY = 0;
	position.x = 380.f;
	position.y = 690.f;
	score = 0;
	R.loadFromFile("Resources\\R.png");
	L.loadFromFile("Resources\\L.png");
	D.loadFromFile("Resources\\D.png");
	U.loadFromFile("Resources\\U.png");
	skinR.loadFromImage(R);
	skinL.loadFromImage(L);
	skinU.loadFromImage(U);
	skinD.loadFromImage(D);
	body.setTexture(&skinL);
}
PacMan::~PacMan() {

}
bool PacMan::isDead() {
	if (dead) {
		return true;
	}
	else
		return false;
}
void PacMan::reset() {
	dead = false;
	velocityX = 0;
	velocityY = 0;
	position.x = 380.f;
	position.y = 690.f;
	score = 0;
}
void PacMan::setMap(Map* map) {
	if (map == nullptr)
		throw 3;
	myMap = map;
}
void PacMan::setGhost(Ghost* _Ghost,int n) {
	if ((_Ghost == nullptr)||(n<0)||(n>3))
		throw 4;
	ghost[n] = _Ghost;
}
void PacMan::setDead(bool _dead) {
	dead = _dead;
}
void PacMan::setPosition(float x, float y) {
		position.x = x;
		position.y = y;
		body.setPosition(position);
}
void PacMan::draw(sf::RenderWindow* window) {
	update();
	window->draw(body);
}
float PacMan::getVelocityX() {
	return velocityX;
}
int PacMan::getScore() {
	return score;
}
float PacMan::getVelocityY() {
	return velocityY;
}
float PacMan::getSize() {
	return size;
}
void PacMan::setVelocity(float _velocityX, float _velocityY) {
	velocityX=_velocityX;
	velocityY = _velocityY;
}
sf::Vector2f PacMan::getPosition() {
	return position;
}
void PacMan::move() {
	int temp;
	//if(myMap==nullptr)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		temp = 0;
		for (int n = 0; n < myMap->wallSize(); n++) {
			if ((getPosition().x < ((myMap->getPosition(n).x) + 40.f))
				&& (getPosition().x > ((myMap->getPosition(n).x) - 43.f))
				&& (getPosition().y < ((myMap->getPosition(n).y) + 40.f))
				&& (getPosition().y > ((myMap->getPosition(n).y) - 40.f)))
			{
				temp++;
			}
		}
		if (temp == 0) {
			body.setTexture(&skinR);
			velocityX = 2.f;
			velocityY = 0.f;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		temp = 0;
		for (int n = 0; n < myMap->wallSize(); n++) {
			if ((getPosition().x < ((myMap->getPosition(n).x) + 43.f))
				&& (getPosition().x > ((myMap->getPosition(n).x) - 40.f))
				&& (getPosition().y < ((myMap->getPosition(n).y) + 40.f))
				&& (getPosition().y > ((myMap->getPosition(n).y) - 40.f)))
			{
				temp++;
			}
		}

		if (temp == 0) {
			body.setTexture(&skinL);
			velocityX = -2.f;
			velocityY = 0.f;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		temp = 0;
		for (int n = 0; n < myMap->wallSize(); n++) {
			if ((getPosition().x < ((myMap->getPosition(n).x) + 40.f))
				&& (getPosition().x > ((myMap->getPosition(n).x) - 40.f))
				&& (getPosition().y < ((myMap->getPosition(n).y) + 43.f))
				&& (getPosition().y > ((myMap->getPosition(n).y) - 40.f)))
			{
				temp++;
			}
		}

			if (temp == 0) {
				body.setTexture(&skinU);
				velocityX = 0.f;
				velocityY = -2.f;
			}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		
		temp = 0;
		for (int n = 0; n < myMap->wallSize(); n++) {
			if ((getPosition().x < ((myMap->getPosition(n).x) + 40.f))
				&& (getPosition().x > ((myMap->getPosition(n).x) - 40.f))
				&& (getPosition().y < ((myMap->getPosition(n).y) + 40.f))
				&& (getPosition().y > ((myMap->getPosition(n).y) - 43.f)))
			{
				temp++;
			}
		}
			if (temp == 0) {
				body.setTexture(&skinD);
				velocityX = 0.f;
				velocityY = 2.f;
			}
	}
}
void PacMan::colisions() {
	//if(ghost[0]==nullptr)...
	int temp = 0;
	if (getPosition().x > (790.f)) {
		position.x = 10.f;
	}
	if (getPosition().x < (10.f)) {
		position.x = 790.f;
	}
	for (int n = 0; n < myMap->wallSize(); n++) {
		if ((getPosition().x < ((myMap->getPosition(n).x) + 40.f))
			&& (getPosition().x > ((myMap->getPosition(n).x) - 40.f))
			&& (getPosition().y < ((myMap->getPosition(n).y) + 40.f))
			&& (getPosition().y > ((myMap->getPosition(n).y) - 40.f)))
		{
			if (getVelocityX() < 0) {
				position.x = position.x + abs(getVelocityX());
				velocityX = 0.f;
			}
			if (getVelocityX() > 0) {
				position.x = position.x - abs(getVelocityX());
				velocityX = 0.f;
			}
			if (getVelocityY() < 0) {
				position.y = position.y + abs(getVelocityY());
				velocityY = 0.f;
			}
			if (getVelocityY() > 0) {
				position.y = position.y - abs(getVelocityY());
				velocityY = 0.f;
			}
		}
	}
	for (int n = 0; n < myMap->pointSize(); n++) {
		if ((getPosition().x < ((myMap->getPositionPoint(n).x) + 20.f))
			&& (getPosition().x > ((myMap->getPositionPoint(n).x) - 20.f))
			&& (getPosition().y < ((myMap->getPositionPoint(n).y) + 20.f))
			&& (getPosition().y > ((myMap->getPositionPoint(n).y) - 20.f)))
		{
			myMap->collectPoint(n);
			score++;
		}
	}
	sf::Vector2f temp2;
	for (int i = 0; i < 3; i++) {
		temp2.x = ghost[i]->getPosition().x;
		temp2.y = ghost[i]->getPosition().y;
		if ((getPosition().x < ((temp2.x + 40.f))
			&& (getPosition().x > (temp2.x - 40.f))
			&& (getPosition().y < (temp2.y + 40.f))
			&& (getPosition().y > (temp2.y - 40.f))))
		{
			setDead(true);
		}
	}
}
void PacMan::update() {
	move();
	colisions();
	position.x += velocityX;
	position.y += velocityY;
	body.setPosition(position);
}


