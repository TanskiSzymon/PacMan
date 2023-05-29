#include "Ghost.h"

void Ghost::setMap(Map* map) {
	if (map == nullptr)
		throw 5;
	myMap = map;
}
void Ghost::setPacMan(PacMan* pacman) {
	if (pacman == nullptr)
		throw 6;
	myPacMan = pacman;
}
void Ghost::setPosition(float x, float y) {
	position.x = x;
	position.y = y;
	body.setPosition(position);
}
void Ghost::draw(sf::RenderWindow* window) {
	update();
	window->draw(body);
} 
float Ghost::getVelocityX() {
	return velocityX;
}
float Ghost::getVelocityY() {
	return velocityY;
}
void Ghost::setVelocity(float _velocityX, float _velocityY) {
	velocityX = _velocityX;
	velocityY = _velocityY;
}
sf::Vector2f Ghost::getPosition() {
	return position;
}
void Ghost::colisions() {
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
}
void Ghost::update() {
	move();
	colisions();
	position.x += velocityX;
	position.y += velocityY;
	body.setPosition(position);
}
Red::Red() {
	size = 40.f;
	body.setRadius((size / 2));
	velocityX = 0;
	velocityY = 0;
	position.x = 380.f;
	position.y = 370.f;
	R.loadFromFile("Resources\\Red.png");
	skinR.loadFromImage(R);
	body.setTexture(&skinR);
}
Red::~Red() {
}
void Red::move() {
	int temp=0;
	int site;
	site = rand() % 4 + 1;
	for (int n = 0; n < myMap->wallSize(); n++) {
		if ((getPosition().x < ((myMap->getPosition(n).x) + 40.f))
			&& (getPosition().x > ((myMap->getPosition(n).x) - 40.f))
			&& (getPosition().y < ((myMap->getPosition(n).y) + 40.f))
			&& (getPosition().y > ((myMap->getPosition(n).y) - 40.f)))
		{
			temp++;
		}
	}
	if (temp == 0) {
		if ((getVelocityX() < 0) && (site == 1)) {
			site = 0;
		}
		if ((getVelocityX() > 0) && (site == 2)) {
			site = 0;
		}
		if ((getVelocityY() < 0) && (site == 4)) {
			site = 0;
		}
		if ((getVelocityY() > 0) && (site == 3)) {
			site = 0;
		}
	}
	if (temp != 0) {
		if ((getVelocityX() < 0)) {
			temp = 0;
			for (int n = 0; n < myMap->wallSize(); n++) {
				if ((getPosition().x < ((myMap->getPosition(n).x) + 40.f))
					&& (getPosition().x > ((myMap->getPosition(n).x) - 40.f))
					&& (getPosition().y < ((myMap->getPosition(n).y) + 41.f))
					&& (getPosition().y > ((myMap->getPosition(n).y) - 41.f)))
				{
					temp++;
				}
			}
			if (temp < 5) {
				site = rand() % 2 + 2;
			}
			else
				site = 1;
		}

		if ((getVelocityX() > 0)) {
			temp = 0;
			for (int n = 0; n < myMap->wallSize(); n++) {
				if ((getPosition().x < ((myMap->getPosition(n).x) + 40.f))
					&& (getPosition().x > ((myMap->getPosition(n).x) - 40.f))
					&& (getPosition().y < ((myMap->getPosition(n).y) + 41.f))
					&& (getPosition().y > ((myMap->getPosition(n).y) - 41.f)))
				{
					temp++;
				}
			}
			if (temp < 5) {
				site = rand() % 2 + 2;
			}
			else
				site = 2;
		}
		if ((getVelocityY() < 0)){
			temp = 0;
			for (int n = 0; n < myMap->wallSize(); n++) {
				if ((getPosition().x < ((myMap->getPosition(n).x) + 41.f))
					&& (getPosition().x > ((myMap->getPosition(n).x) - 41.f))
					&& (getPosition().y < ((myMap->getPosition(n).y) + 40.f))
					&& (getPosition().y > ((myMap->getPosition(n).y) - 40.f)))
				{
					temp++;
				}
			}
			if (temp < 5) {
				site = rand() % 2;
			}
			else
				site = 4;
		}
		if ((getVelocityY() > 0)) {
			temp = 0;
			for (int n = 0; n < myMap->wallSize(); n++) {
				if ((getPosition().x < ((myMap->getPosition(n).x) + 41.f))
					&& (getPosition().x > ((myMap->getPosition(n).x) - 41.f))
					&& (getPosition().y < ((myMap->getPosition(n).y) + 40.f))
					&& (getPosition().y > ((myMap->getPosition(n).y) - 40.f)))
				{
					temp++;
				}
			}
			if (temp < 5) {
				site = rand() % 2;
			}
			else
				site = 3;
		}
	}
	if (site==1) {

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
			velocityX = 2.f;
			velocityY = 0.f;
		}
	}
	if (site==2) {
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
			velocityX = -2.f;
			velocityY = 0.f;
		}
	}
	if (site==3) {
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
			velocityX = 0.f;
			velocityY = -2.f;
		}
	}
	if (site==4) {

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
			velocityX = 0.f;
			velocityY = 2.f;
		}
	}
}
Blue::Blue() {
	size = 40.f;
	body.setRadius((size / 2));
	velocityX = 0;
	velocityY = 0;
	position.x = 340.f;
	position.y = 370.f;
	B.loadFromFile("Resources\\Blue.png");
	skinB.loadFromImage(B);
	body.setTexture(&skinB);
}
Blue::~Blue() {
}
void Blue::move() {
	int temp = 0;
	int site;
	site = rand() % 4 + 1;
	for (int n = 0; n < myMap->wallSize(); n++) {
		if ((getPosition().x < ((myMap->getPosition(n).x) + 40.f))
			&& (getPosition().x > ((myMap->getPosition(n).x) - 40.f))
			&& (getPosition().y < ((myMap->getPosition(n).y) + 40.f))
			&& (getPosition().y > ((myMap->getPosition(n).y) - 40.f)))
		{
			temp++;
		}
	}
	if (temp == 0) {
		if ((getVelocityX() < 0) && (site == 1)) {
			site = 0;
		}
		if ((getVelocityX() > 0) && (site == 2)) {
			site = 0;
		}
		if ((getVelocityY() < 0) && (site == 4)) {
			site = 0;
		}
		if ((getVelocityY() > 0) && (site == 3)) {
			site = 0;
		}
	}
	if (temp != 0) {
		if ((getVelocityX() < 0)) {
			temp = 0;
			for (int n = 0; n < myMap->wallSize(); n++) {
				if ((getPosition().x < ((myMap->getPosition(n).x) + 40.f))
					&& (getPosition().x > ((myMap->getPosition(n).x) - 40.f))
					&& (getPosition().y < ((myMap->getPosition(n).y) + 41.f))
					&& (getPosition().y > ((myMap->getPosition(n).y) - 41.f)))
				{
					temp++;
				}
			}
			//std::cout << "Ilosc kolizji L : " << temp << "\n";
			if (temp < 5) {
				site = rand() % 2 + 2;
			}
			else
				site = 1;
		}

		if ((getVelocityX() > 0)) {
			temp = 0;
			for (int n = 0; n < myMap->wallSize(); n++) {
				if ((getPosition().x < ((myMap->getPosition(n).x) + 40.f))
					&& (getPosition().x > ((myMap->getPosition(n).x) - 40.f))
					&& (getPosition().y < ((myMap->getPosition(n).y) + 41.f))
					&& (getPosition().y > ((myMap->getPosition(n).y) - 41.f)))
				{
					temp++;
				}
			}
			//std::cout << "Ilosc kolizji R : " << temp << "\n";
			if (temp < 5) {
				site = rand() % 2 + 2;
			}
			else
				site = 2;
		}
		if ((getVelocityY() < 0)) {
			temp = 0;
			for (int n = 0; n < myMap->wallSize(); n++) {
				if ((getPosition().x < ((myMap->getPosition(n).x) + 41.f))
					&& (getPosition().x > ((myMap->getPosition(n).x) - 41.f))
					&& (getPosition().y < ((myMap->getPosition(n).y) + 40.f))
					&& (getPosition().y > ((myMap->getPosition(n).y) - 40.f)))
				{
					temp++;
				}
			}
			//std::cout << "Ilosc kolizji D : " << temp << "\n";
			if (temp < 5) {
				site = rand() % 2;
			}
			else
				site = 4;
		}
		if ((getVelocityY() > 0)) {
			temp = 0;
			for (int n = 0; n < myMap->wallSize(); n++) {
				if ((getPosition().x < ((myMap->getPosition(n).x) + 41.f))
					&& (getPosition().x > ((myMap->getPosition(n).x) - 41.f))
					&& (getPosition().y < ((myMap->getPosition(n).y) + 40.f))
					&& (getPosition().y > ((myMap->getPosition(n).y) - 40.f)))
				{
					temp++;
				}
			}
			//std::cout << "Ilosc kolizji U : " << temp << "\n";
			if (temp < 5) {
				site = rand() % 2;
			}
			else
				site = 3;
		}
	}

	if (site == 1) {

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
			velocityX = 2.f;
			velocityY = 0.f;
		}
	}
	if (site == 2) {
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
			velocityX = -2.f;
			velocityY = 0.f;
		}
	}
	if (site == 3) {
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
			velocityX = 0.f;
			velocityY = -2.f;
		}
	}
	if (site == 4) {

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
			velocityX = 0.f;
			velocityY = 2.f;
		}
	}
}
Pink::Pink() {
	size = 40.f;
	body.setRadius((size / 2));
	velocityX = 0;
	velocityY = 0;
	position.x = 380.f;
	position.y = 370.f;
	//position.x = 60.f;
	//position.y = 50.f;
	P.loadFromFile("Resources\\Pink.png");
	skinP.loadFromImage(P);
	body.setTexture(&skinP);
}
Pink::~Pink() {
}
void Pink::move() {
	/*
	1.Sprawdza kolizje
	a.Z 3 stron
	b.Z 2 stron
	c.Z 1 strony
	2a.Idzi w strone przeciwna do obecnej
	2b.Wyznacz strony z kolizja
	Oblicz w ktora strone odlegosc GP bedzie mniejsza, idz w te strone
	2c.Wyznacz strony z kolizja
	Oblicz w ktora strone odlegosc GP bedzie mniejsza, idz w te strone

	Jak wyznaczyc strony z kolizja?
	-Sprawdz po koeli kolizje dla wszyskich blokow o + 2 lub 40 dla kazdej strony
	*/
	int colisionsSum;
	int kL = 0;
	int kR = 0;
	int kD = 0;
	int kU = 0;
	int temp = 0;
	int site=2;
	{
		//Down
		temp = 0;
		for (int n = 0; n < myMap->wallSize(); n++) {
			if ((getPosition().x < ((myMap->getPosition(n).x) + 40.f))
				&& (getPosition().x > ((myMap->getPosition(n).x) - 40.f))
				&& (getPosition().y < ((myMap->getPosition(n).y) + 40.f))
				&& (getPosition().y > ((myMap->getPosition(n).y) - 42.f)))
			{
				temp++;
			}
		}
		//std::cout << "Ilosc kolizji D : " << temp << "\n";
		if (temp > 0) {
			kD = 1;
		}

		//Up		
		temp = 0;
		for (int n = 0; n < myMap->wallSize(); n++) {
			if ((getPosition().x < ((myMap->getPosition(n).x) + 40.f))
				&& (getPosition().x > ((myMap->getPosition(n).x) - 40.f))
				&& (getPosition().y < ((myMap->getPosition(n).y) + 42.f))
				&& (getPosition().y > ((myMap->getPosition(n).y) - 40.f)))
			{
				temp++;
			}
		}
		//std::cout << "Ilosc kolizji U : " << temp << "\n";
		if (temp > 0) {
			kU = 1;
		}


		//Left		
		temp = 0;
		for (int n = 0; n < myMap->wallSize(); n++) {
			if ((getPosition().x < ((myMap->getPosition(n).x) + 42.f))
				&& (getPosition().x > ((myMap->getPosition(n).x) - 40.f))
				&& (getPosition().y < ((myMap->getPosition(n).y) + 40.f))
				&& (getPosition().y > ((myMap->getPosition(n).y) - 40.f)))
			{
				temp++;
			}
		}
		//std::cout << "Ilosc kolizji L: " << temp << "\n";
		if (temp > 0) {
			kL = 1;
		}

		//Right	
		temp = 0;
		for (int n = 0; n < myMap->wallSize(); n++) {
			if ((getPosition().x < ((myMap->getPosition(n).x) + 40.f))
				&& (getPosition().x > ((myMap->getPosition(n).x) - 42.f))
				&& (getPosition().y < ((myMap->getPosition(n).y) + 40.f))
				&& (getPosition().y > ((myMap->getPosition(n).y) - 40.f)))
			{
				temp++;
			}
		}
		//std::cout << "Ilosc kolizji R: " << temp << "\n";
		if (temp > 0) {
			kR = 1;
		}
		colisionsSum = kL + kR + kD + kU;
		//std::cout << "\n\nSuma kolizji: " << colisionsSum << "\n\n";
		//Sleep(10);
	}

	float Rdx = sqrt(pow((getPosition().x + 20.f) - myPacMan->getPosition().x, 2));
	float Rdy = sqrt(pow(getPosition().y - myPacMan->getPosition().y, 2));
	float Ldx = sqrt(pow((getPosition().x - 20.f) - myPacMan->getPosition().x, 2));
	float Ldy = sqrt(pow(getPosition().y - myPacMan->getPosition().y, 2));


	float Rd = (sqrt(pow((getPosition().x + 20.f) - myPacMan->getPosition().x, 2) +
		pow(getPosition().y - myPacMan->getPosition().y, 2)));
	float Ld = (sqrt(pow((getPosition().x - 20.f) - myPacMan->getPosition().x, 2) +
		pow(getPosition().y - myPacMan->getPosition().y, 2)));
	float Ud = (sqrt(pow((getPosition().x) - myPacMan->getPosition().x, 2) +
		pow(getPosition().y - 20.f - myPacMan->getPosition().y, 2)));
	float Dd = (sqrt(pow((getPosition().x + 2.f) - myPacMan->getPosition().x, 2) +
		pow(getPosition().y + 20.f - myPacMan->getPosition().y, 2)));
		if (colisionsSum == 3) {
			if (kR == 0) {
				site = 1;
				//velocityX = 2.f;
				//velocityY = 0.f;
			}
			if (kL == 0) {
				site = 2;
				//velocityX = -2.f;
				//velocityY = 0.f;
			}
			if (kD == 0) {
				site = 4;
				//velocityX = 0.f;
				//velocityY = 2.f;
			}
			if (kU == 0) {
				site = 3;
				//velocityX = 0.f;
				//velocityY = -2.f;
			}
		}
		if (colisionsSum == 2) {
			if ((kR == 0) && (kL == 0)) {
				if (Rd == Ld)
				{
					//std::cout << "\nRd == Ld\n";
					Rd += 22.f;
					//velocityX = -2.f;
					//velocityY = 0.f;
				}
				if (Rd<Ld)
				{
					//std::cout << "\nRd<Ld";
					//std::cout << "\nsite = 1;\n";
					site = 1;
					//velocityX = -2.f;
					//velocityY = 0.f;
				}
				if (Rd > Ld) {
					//std::cout << "\nRd > Ld";
					//std::cout << "\nsite = 2;\n";
					site = 2;
					//velocityX = 2.f;
					//velocityY = 0.f;
				}
			}
			if ((kL == 0) && (kU == 0)) {
				if (Ld == Ud)
				{
					//std::cout << "\nLd == Ud\n";
					Ld += 22.f;
				}
				if (Ld<Ud)//mozliwe ze y sa odwrotnie
				{
					//std::cout << "\nLd<Ud\n";
					site = 2;
					//velocityX = -2.f;
					//velocityY = 0.f;
				}
				if (Ld > Ud) {
					//std::cout << "\nLd > Ud\n";
					site = 3;
					//velocityX = 0.f;
					//velocityY = -2.f;//-||-
				}
			}
			if ((kL == 0) && (kD == 0)) {
				if (Ld == Dd)
				{
					//std::cout << "\nLd == Dd\n";
					Ld += 22.f;
				}
				if (Ld<Dd)
				{
					//std::cout << "\nLd<Dd\n";
					site = 2;
					//velocityX = -2.f;
					//velocityY = 0.f;
				}
				if (Ld > Dd) {
					//std::cout << "\nLd > Dd\n";
					site = 4;
					//velocityX = 0.f;
					//velocityY = 2.f;
				}
			}
			if ((kR == 0) && (kU == 0)) {
				if (Rd == Ud)
				{
					//std::cout << "\nRd == Ud\n";
					Rd += 22.f;
				}
				if (Rd<Ud)
				{
					//std::cout << "\nRd<Ud\n";
					site = 1;
					//velocityX = 2.f;
					//velocityY = 0.f;
				}
				if (Rd > Ud) {
					//std::cout << "\nRd > Ud\n";
					site = 3;
					//velocityX = 0.f;
					//velocityY = -2.f;
				}
			}
			if ((kR == 0) && (kD == 0)) {
				if (Rd == Dd)
				{
					//std::cout << "\nRd == Dd\n";
					Rd += 22.f;
				}
				if (Rd<Dd)
				{
					//std::cout << "\nRd<Dd\n";
					site = 1;
					//velocityX = 2.f;
					//velocityY = 0.f;
				}
				if (Rd > Dd) {
					//std::cout << "\nRd > Dd\n";
					site = 4;
					//velocityX = 0.f;
					//velocityY = 2.f;
				}
			}if ((kU == 0) && (kD == 0)) {
				if (Ud == Dd)
				{
					//std::cout << "\nUd == Dd\n";
					Ud += 22.f;
				}
				if (Ud<Dd)
				{
					//std::cout << "\nUd<Dd\n";
					site = 3;
					//velocityX = 0.f;
					//velocityY = -2.f;
				}
				if (Ud > Dd) {
					//std::cout << "\nUd > Dd\n";
					site = 4;
					//velocityX = 0.f;
					//velocityY = 2.f;
				}
			}
		}
		if (colisionsSum == 1) {
			if (kL == 1) {
				if (Ud<=Dd)
				{
					if (Ud<=Rd)
					{
						site = 3;
						//velocityX = 0.f;
						//velocityY = -2.f;
					}
					else
					{
						site = 1;
						//velocityX = 2.f;
						//velocityY = 0.f;
					}
				}
				else {
					if (Dd<=Rd)
					{
						site = 4;
						//velocityX = 0.f;
						//velocityY = 2.f;
					}
					else
					{
						site = 1;
						//velocityX = 2.f;
						//velocityY = 0.f;
					}
				}
			}
			if (kU == 1) {
				if (Ld<=Rd)
				{
					if (Ld<=Dd)
					{
						site = 2;
						//velocityX = -2.f;
						//velocityY = 0.f;
					}
					else
					{
						site = 4;
						//velocityX = 0.f;
						//velocityY = 2.f;
					}
				}
				else {
					if (Rd<=Dd)
					{
						site = 1;
						//velocityX = 2.f;
						//velocityY = 0.f;
					}
					else
					{
						site = 4;
						//velocityX = 0.f;
						//velocityY = 2.f;
					}
				}
			}
			if (kR == 1) {
				if (Ud<=Dd)
				{
					if (Ud <= Ld)
					{
						site = 3;
						//velocityX = -2.f;
						//velocityY = 0.f;
					}
					else
					{
						site = 2;
						//velocityX = 0.f;
						//velocityY = 2.f;
					}
				}
				else {
					if (Dd <=Ld)
					{
						site = 4;
						//velocityX = 0.f;
						//velocityY = -2.f;
					}
					else
					{
						site = 2;
						//velocityX = 0.f;
						//velocityY = 2.f;
					}
				}
			}
			if (kD == 1) {
				if (Ld <= Rd)
				{
					if (Ld <= Ud)
					{
						site = 2;
						//velocityX = -2.f;
						//velocityY = 0.f;
					}
					else
					{
						site = 3;
						//velocityX = 2.f;
						//velocityY = 0.f;
					}
				}
				else {
					if (Rd <= Ud)
					{
						site = 1;
						//velocityX = 2.f;
						//velocityY = 0.f;
					}
					else
					{
						site = 3;
						//velocityX = 0.f;
						//velocityY = -2.f;
					}
				}
			}
		}
		if (colisionsSum == 0) {
			if (Rd <= Ld)
			{
				if (Ud <= Dd)
				{
					if (Rd <= Ud)
					{
						site = 1;
					}
					else
						site = 3;
				}
				else
				{
					if (Rd <= Dd)
					{
						site = 1;
					}
					else
						site = 4;
				}
			}
			else
			{
				if (Ud <= Dd)
				{
					if (Ld <= Dd)
					{
						site = 2;
					}
					else
						site = 4;
				}
				else
				{
					if (Ld <= Dd)
					{
						site = 2;
					}
					else
						site = 4;
				}
			}
		}

		if (((getPosition().x == 380.f) && (getPosition().x == 380.f)) && ((getPosition().y >290.f) && (getPosition().y < 375.f))) {
			site = 3;
			//std::cout << "Site 3\n";
		}
		if (((getPosition().x >= 330.f) && (getPosition().x < 380.f)) &&
			((getPosition().y > 375.f) && (getPosition().y < 385.f))) {
			site = 1;
			//std::cout << "Site 1\n";
		}
		if (((getPosition().x > 380.f) && (getPosition().x <= 430.f)) &&
			((getPosition().y > 375.f) && (getPosition().y < 385.f))) {
			site = 2;
			//std::cout << "Site 2\n";
		}
		if (((getPosition().x >= 380.f) && (getPosition().x < 500.f)) && ((getPosition().y <= 290.f) && (getPosition().y > 250.f))) {
			site = 1;
			///std::cout << "Site 1\n";
		}
		if ((site == 1)&&(kR==0)) {
			velocityX = 2.f;
			velocityY = 0.f;
		}
		if ((site == 2) && (kL == 0)) {
			velocityX = -2.f;
			velocityY = 0.f;
		}
		if ((site == 3) && (kU == 0)) {
			velocityX = 0.f;
			velocityY = -2.f;
		}
		if ((site == 4) && (kD == 0))  {
			velocityX = 0.f;
			velocityY = 2.f;
		}
}
