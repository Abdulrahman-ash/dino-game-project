#include "Background.h"

void drawLandingScreen(sf::RenderWindow* window) {
	sf::RectangleShape rect;
	rect.setFillColor(sf::Color(128, 128, 128));
	rect.setPosition(window->getSize().x / 4 * 0, 0);
	rect.setSize(sf::Vector2f(window->getSize().x / 4, window->getSize().y));
	window->draw(rect);
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(window->getSize().x / 4 * 1, 0);
	window->draw(rect);
	rect.setFillColor(sf::Color::Blue);
	rect.setPosition(window->getSize().x / 4 * 2, 0);
	window->draw(rect);
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(window->getSize().x / 4 * 3, 0);
	window->draw(rect);
}

void drawMainMenuScreen(sf::RenderWindow* window) {
	//sf::Texture main_menu;
	//main_menu.loadFromFile("main-menu.jpg");
	//auto mmenu = sf::Sprite(main_menu);
	//mmenu.setScale(window->getSize().x / mmenu.getGlobalBounds().width, window->getSize().y / mmenu.getGlobalBounds().height);
	//window->draw(mmenu);

	sf::Texture key;
	key.loadFromFile("keys.png");
	auto mkey = sf::Sprite(key);
	mkey.setPosition(window->getSize().x - 230, window->getSize().y - 170);
	window->draw(mkey);
}

void Background::display(sf::RenderWindow* window, State state) {
	switch (state) {
	case State::LANDING:
		drawLandingScreen(window);
		break;
	case State::MAIN:
		drawMainMenuScreen(window);
		break;
	case State::GAME:
		break;
	}
}