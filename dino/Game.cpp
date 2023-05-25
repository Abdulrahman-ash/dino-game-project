#include "Game.h"
#include <iostream>

Game::Game(int winWidth, int winHeight, const std::string& winName) : window(sf::VideoMode(winWidth, winHeight), winName), gui(&window, &font, &player) {
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);
	font.loadFromFile("arial.ttf");
	player.setPos(sf::Vector2f(0, window.getSize().y - 200));
	player.loadSprites("AAA");
}

void Game::run()
{
	while (window.isOpen()) {
		update();
		processEvents();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::BackSpace && state != State::GAME) {
				dec(state);
				gui.changeState(state);
			} else if (event.key.code == sf::Keyboard::Enter) {
				if (state == State::LANDING) {
					inc(state);
					gui.changeState(state);
				}
			}
		}
		if (event.MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
			}
		}
	}

	std::pair<std::string, Mouse> mevent;
	while (gui.getMouseEvent(mevent)) {
		if (mevent.second == Mouse::PRESSED) {
			if (mevent.first == "Exit")
				exit(0);
			else if (mevent.first == "Character") {
				state = State::CHARACTER;
				gui.changeState(state);
			}
			if (mevent.first == "Play") {
				state = State::GAME;
				gui.changeState(state);
				player.setState("Run");
			} else if (state == State::CHARACTER) {
				player.setCharacter(mevent.first);
				player.setState("Idle");
			}
		}

		if (mevent.second == Mouse::HOVERED) {
		}
	}
}

void Game::update() {
	gui.handleEvents();
}
void Game::render() {
	window.clear();
	background.display(&window, state);

	if (state == State::GAME || state == State::CHARACTER) {
		player.update(32);
		player.draw(&window);
	}
	gui.draw();
	Obsticle obsticle("sprites/Zewail-City.png");
	obsticle.setPos(sf::Vector2f(sf::Mouse::getPosition(window).x - 50, sf::Mouse::getPosition(window).y - 50));
	std::cout << "blaj" << std::endl;
	obsticle.draw(&window);
	window.display();
}