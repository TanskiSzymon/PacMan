#include "Map.h"

Map::Map() {
	try {
		loadMap();
		convertMap();
	}
	catch (int error) {
		if (error == 1) {
			std::cout << "Blad otwarcia mapy.\n";
			exit(1);
		}
		if (error == 2) {
			std::cout << "Blad konversji mapy.\n";
			exit(1);
		}
	}
	sf::Vector2f size;
	size.x = 800.f;
	size.y = 800.f;
	background.setSize(size);
	background.setPosition(0.f, 0.f);
	bg.loadFromFile("Resources\\Backgrouund.png");
	texture.loadFromImage(bg);
}
Map::~Map() {
	wall.clear();
	loadedMap.clear();
	point.clear();
}
void Map::loadMap() {
	char ad[100];
	std::ifstream inMap("Resources\\mapv1.pgm");
	if (inMap.is_open())
	{
		for (int i = 0; i < 4; i++)
			inMap.getline(ad, 100);
		char temp;
		while (inMap >> temp) 
		{
			if (temp == 48)
				loadedMap.push_back(0);
			if (temp == 50)
				loadedMap.push_back(2);
			if (temp == 49)
				loadedMap.push_back(1);
		}
	}
	else{
			throw 1;
	}
}
void Map::convertMap() {
	float positionX = 0.f;
	float positionY = 10.f;
	sf::CircleShape  tempPoint;
	sf::RectangleShape temp;
	sf::Vector2f size;
	size.x = 39.f;
	size.y = 39.f;
	int n=0;
	temp.setSize(size);
	temp.setFillColor(sf::Color(192,192,192,255));
	temp.setPosition(positionX, positionY);

	tempPoint.setRadius(5.f);
	tempPoint.setFillColor(sf::Color(200, 200,150, 255));
	tempPoint.setPosition(positionX, positionY);

	if (loadedMap.size() >= 400) {
		for (int y = 0; y < 20; y++) {
			positionX = 0;
			for (int x = 0; x < 20; x++) {
				temp.setPosition((positionX-20.f), positionY);
				tempPoint.setPosition((positionX - 20.f+17.5f), positionY+17.5f);
				if(loadedMap[n]==0)
					wall.push_back(temp);
				if (loadedMap[n] == 1)
					point.push_back(tempPoint);
				n++;
				positionX = positionX + 40.f;
			}
			positionY = positionY + 40.f;
		}
		temp.setPosition((0.f), 330.f);
		wall.push_back(temp);
		temp.setPosition((0.f), 410.f);
		wall.push_back(temp);
		temp.setPosition((760.f), 330.f);
		wall.push_back(temp);
		temp.setPosition((760.f), 410.f);
		wall.push_back(temp);

	}
	else {
		throw 2;
	}
	nofPoints = point.size();
}
int Map::wallSize() {
	return wall.size();
}
int Map::pointSize() {
	return point.size();
}
sf::Vector2f Map::getPosition(int n) {
	sf::Vector2f temp;
	temp.x = wall[n].getPosition().x;
	temp.y = wall[n].getPosition().y;
	return temp;
}
sf::Vector2f Map::getPositionPoint(int n) {
	sf::Vector2f temp;
	temp.x = point[n].getPosition().x;
	temp.y = point[n].getPosition().y;
	return temp;
}
void Map::draw(sf::RenderWindow* window) {
	background.setTexture(&texture);
	window->draw(background);
	for (int i=0;i<point.size();i++)
		window->draw(point[i]);
}
void Map::collectPoint(int n) {
	sf::Vector2f temp2;
	temp2.x = 100.f;
	temp2.y = 780.f;
	point[n].setPosition(temp2);
}