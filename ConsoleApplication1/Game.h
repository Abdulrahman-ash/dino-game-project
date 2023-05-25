#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;
#define items 4

class Game
{
private:
	Font font;
	Text text[items];
public:
	Game();
	Game(float width, float height);
	void drawmenu(RenderWindow& window);
	void processEvents();
	void Background(RenderWindow& window);
	SoundBuffer Background_sound();
	void Render(RenderWindow& window);
	void update(RenderWindow& window);
};





