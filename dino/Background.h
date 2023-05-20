#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
enum Screen
{
	LANDING,
	MAIN,
	GAME
};

class Background
{
private:
	Screen current_screen = Screen::LANDING;

public:
	void changeScreen(Screen S);
	void display(sf::RenderWindow* window, sf::Font*);
	int getCurrentScreen();
};