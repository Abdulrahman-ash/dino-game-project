#pragma once

#include "Background.h"
#include "GUI.h"

class Game
{
private:
	sf::RenderWindow window;
	GUI gui;
	Player player;
	Background background;
	sf::Font font;
	State state = State::LANDING;

public:
	Game(int winWidth, int winHeight, const std::string& winName);

	void processEvents();

	void update();

	void render();

	void run();
};
