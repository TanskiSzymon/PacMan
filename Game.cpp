#include "Game.h"

Game::Game() {
	sizeWindowX = 800;
	sizeWindowY = 800;
	window = new sf::RenderWindow(sf::VideoMode(sizeWindowX, sizeWindowY), "PacMan 2.0", sf::Style::Close);
	//fps limit
	window->setFramerateLimit(60);
	font.loadFromFile("Resources\\font.ttf");
	try {
		tekst.setFont(font);
		pacman.setMap(&map);

		ghost[0] = new Red();
		ghost[0]->setMap(&map);
		ghost[0]->setPacMan(&pacman);
		pacman.setGhost(ghost[0], 0);

		ghost[1] = new Blue();
		ghost[1]->setMap(&map);
		ghost[1]->setPacMan(&pacman);
		pacman.setGhost(ghost[1], 1);

		ghost[2] = new Pink();
		ghost[2]->setMap(&map);
		ghost[2]->setPacMan(&pacman);
		pacman.setGhost(ghost[2], 2);
	}
	catch (int error) {
		if (error == 3) {
			std::cout << "Blad przypisania mapy - PacMan.\n";
			exit(1);
		}
		if (error == 4) {
			std::cout << "Blad przypisania duchow - PacMan.\n";
			exit(1);
		}
		if (error == 5) {
			std::cout << "Blad przypisania mapy - Ghost.\n";
			exit(1);
		}
		if (error == 6) {
			std::cout << "Blad przypisania pacmana - Ghost.\n";
			exit(1);
		}
	}
}
Game::~Game() {
	delete ghost[0];
	delete ghost[1];
	delete ghost[2];
	delete window;
}
void Game::start() {
	text();
	while (window->isOpen())
	{
		update();
		render();
	}
}
void Game::update() {
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window->close();
		} 
	}
}
void Game::render() {
	if (pacman.getScore() < 169) {
		map.draw(window);
		//try?
		pacman.draw(window);
		//try?
		ghost[0]->draw(window);
		//try?
		ghost[1]->draw(window);
		//try?
		ghost[2]->draw(window);
		textScore();
		window->display();
	}
	if (pacman.getScore()>= 169) {
		textWin();
		window->display();
		//Sleep(3000);
		window->close();
	}
	if (pacman.isDead()) {
		textLose();
		window->display();
		window->close();
	}
}
void Game::text() {
	window->clear(sf::Color(0, 0, 40, 255));
	update();
	tekst.setString("PacMan 2.0");
	tekst.setPosition((sizeWindowX / 2.f)-150.f, sizeWindowY / 4.f);
	window->draw(tekst);
	window->display();
	Sleep(1500);
}
void Game::textScore() {
	std::stringstream ss;
	ss << "Score:";
	ss << pacman.getScore();
	tekst.setString(ss.str());
	tekst.setPosition(120.f, 765.f);
	window->draw(tekst);
}
void Game::textWin() {
	window->clear(sf::Color(0, 0, 40, 255));
	tekst.setString("Wygrales!!");
	tekst.setPosition((sizeWindowX / 2.f) - 150.f, sizeWindowY / 4.f);
	window->draw(tekst);
	window->display();
	Sleep(3000);
}
void Game::textLose() {
	window->clear(sf::Color(0, 0, 40, 255));
	std::stringstream ss;
	ss << "Przegrales!!\n  Score:";
	ss << pacman.getScore();
	tekst.setString(ss.str());
	tekst.setPosition((sizeWindowX / 2.f) - 170.f, sizeWindowY / 4.f);
	window->draw(tekst);
	window->display();
	Sleep(3000);
}

