#pragma once

#include "Background.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::Font font;
	Background background;

public:
	Game();

	void processEvents();

	void update();

	void render();

	void run();
};
