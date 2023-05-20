#include "Background.h"

#include <chrono>
#include <format>

std::string get_current_time_and_date()
{
	auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
	return std::format("{:%X}", time);
}

void Background::changeScreen(Screen S) {
	current_screen = S;
}
void Background::display(sf::RenderWindow* window, sf::Font* font) {
	if (current_screen == Screen::LANDING) {
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

		sf::Text text_start("Press Enter key to continue", *font);

		text_start.setCharacterSize(30);
		text_start.setStyle(sf::Text::Bold);
		text_start.setFillColor(sf::Color::Black);
		text_start.setPosition(window->getSize().x / 2 - text_start.getGlobalBounds().width / 2, window->getSize().y - 100);

		window->draw(text_start);

		sf::Text text_name("Dino Game", *font);

		text_name.setCharacterSize(50);
		text_name.setFillColor(sf::Color(128, 255, 128));
		text_name.setPosition(window->getSize().x / 2 - text_name.getGlobalBounds().width / 2, 100);

		sf::RectangleShape text_start_rect;
		text_start_rect.setFillColor(sf::Color::Black);
		text_start_rect.setOutlineColor(sf::Color(128, 128, 0));
		text_start_rect.setOutlineThickness(2);
		text_start_rect.setPosition(text_name.getPosition().x, text_name.getPosition().y + 10);
		text_start_rect.setSize(sf::Vector2f(text_name.getGlobalBounds().width + 8, text_name.getGlobalBounds().height + 10));

		window->draw(text_start_rect);
		window->draw(text_name);
	} else if (current_screen == Screen::MAIN) {
		sf::Texture main_menu;
		main_menu.loadFromFile("main-menu.jpg");
		auto mmenu = sf::Sprite(main_menu);
		mmenu.setScale(window->getSize().x / mmenu.getGlobalBounds().width, window->getSize().y / mmenu.getGlobalBounds().height);
		window->draw(mmenu);

		sf::Text text_name("Main Menu", *font);

		text_name.setCharacterSize(50);
		text_name.setFillColor(sf::Color(255, 128, 0));
		text_name.setPosition(window->getSize().x / 2 - text_name.getGlobalBounds().width / 2, 100);

		window->draw(text_name);

		sf::RectangleShape rect;
		rect.setFillColor(sf::Color(128, 128, 128));
		rect.setOutlineThickness(2);
		rect.setOutlineColor(sf::Color::Black);
		rect.setPosition(window->getSize().x / 2 - 100, 200);
		rect.setSize(sf::Vector2f(window->getSize().x / 4, 50));
		window->draw(rect);
		text_name.setCharacterSize(40);
		text_name.setString("Play");
		text_name.setFillColor(sf::Color(0, 0, 0));
		text_name.setPosition(rect.getPosition().x + 65, rect.getPosition().y);
		window->draw(text_name);
		rect.setPosition(window->getSize().x / 2 - 100, 260);
		window->draw(rect);
		text_name.setString("Credits");
		text_name.setPosition(rect.getPosition().x + 35, text_name.getPosition().y + 60);
		window->draw(text_name);
		rect.setPosition(window->getSize().x / 2 - 100, 320);
		window->draw(rect);
		text_name.setString("About");
		text_name.setPosition(rect.getPosition().x + 50, text_name.getPosition().y + 60);
		window->draw(text_name);
		rect.setPosition(window->getSize().x / 2 - 100, 380);
		window->draw(rect);
		text_name.setString("Exit");
		text_name.setPosition(rect.getPosition().x + 65, text_name.getPosition().y + 60);
		window->draw(text_name);

		text_name.setString(get_current_time_and_date());
		text_name.setCharacterSize(30);
		text_name.setPosition(sf::Vector2f(window->getSize().x - text_name.getGlobalBounds().width - 10, 10));
		window->draw(text_name);

		sf::Texture key;
		key.loadFromFile("keys.png");
		auto mkey = sf::Sprite(key);
		//mkey.setScale(window->getSize().x / mkey.getGlobalBounds().width, window->getSize().y / mkey.getGlobalBounds().height);
		mkey.setPosition(window->getSize().x - 230, window->getSize().y - 170);
		window->draw(mkey);
	} else if (current_screen == Screen::GAME) {}
}

int Background::getCurrentScreen()
{
	return current_screen;
}