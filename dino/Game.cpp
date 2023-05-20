#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Dino") {
	window.setFramerateLimit(60);
	//font.loadFromFile("JetBrainsMono.ttf");
	font.loadFromFile("arial.ttf");
}

void Game::run()
{
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.KeyPressed) {
				if (event.key.code == sf::Keyboard::BackSpace) {
					if (background.getCurrentScreen() > 0)
						background.changeScreen((Screen)(background.getCurrentScreen() - 1));
				} else if (event.key.code == sf::Keyboard::Enter) {
					if (background.getCurrentScreen() == Screen::LANDING)
						background.changeScreen((Screen)(Screen::MAIN));
				}
			}
		}

		window.clear();
		background.display(&window, &font);
		window.display();
	}
}