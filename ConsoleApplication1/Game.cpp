#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;
Game::Game()
{
}
Game::Game(float width, float Height)
{

	if (!font.loadFromFile("Fonts/AnandaBlackPersonalUseRegular-rg9Rx.ttf"))
		throw("COULD NOT LOAD FONT");
	text[0].setFont(font);
	text[0].setFillColor(Color::Red);
	text[0].setString("Difficulty Selection Menu");
	text[0].setPosition(Vector2f(width / 3, Height / (items + 1) * 1));

	text[1].setFont(font);
	text[1].setFillColor(Color::White);
	text[1].setString("Scenery Selection Menu");
	text[1].setPosition(Vector2f(width / 3, Height / (items + 1) * 2));

	text[2].setFont(font);
	text[2].setFillColor(Color::Cyan);
	text[2].setString("Character Selection Menu");
	text[2].setPosition(Vector2f(width / 3, Height / (items + 1) * 3));

	text[3].setFont(font);
	text[3].setFillColor(Color::Blue);
	text[3].setString("How to play");
	text[3].setPosition(Vector2f(width / 3, Height / (items + 1) * 4));
}
void Game::drawmenu(RenderWindow& window)
{
	Game(window.getSize().x, window.getSize().y);
	for (int j = 0; j < items; j++)
	{
		window.draw(text[j]);
	}
}
void Game::Background(RenderWindow& window)
{

	Font font;
	if (!font.loadFromFile("Fonts/AnandaBlackPersonalUseRegular-rg9Rx.ttf"))
		throw("COULD NOT LOAD FONT");
	Text text;
	text.setFont(font);
	text.setCharacterSize(100);
	text.setFillColor(Color::White);
	text.setStyle(Text::Regular);
	text.setString(" Dino ");
	text.setPosition(Vector2f(450.f, 100.f));
	Vector2f rec1pos = Vector2f(0.f, 0.f);
	RectangleShape rec1(Vector2f(480.f, 800.f));
	rec1.setFillColor(Color::Green);
	rec1.setPosition(rec1pos);
	Vector2f rec2pos = Vector2f(480.f, 0.f);
	RectangleShape rec2(Vector2f(120.f, 800.f));
	rec2.setFillColor(Color::Red);
	rec2.setPosition(rec2pos);
	Vector2f rec3pos = Vector2f(600.f, 0.f);
	RectangleShape rec3(Vector2f(120.f, 800.f));
	rec3.setFillColor(Color::Yellow);
	rec3.setPosition(rec3pos);
	Vector2f rec4pos = Vector2f(720.f, 0.f);
	RectangleShape rec4(Vector2f(480.f, 800.f));
	rec4.setFillColor(Color::Blue);
	rec4.setPosition(rec4pos);
	window.draw(rec1);
	window.draw(rec2);
	window.draw(rec3);
	window.draw(rec4);
	window.draw(text);
}

SoundBuffer Game::Background_sound()
{
	SoundBuffer soundBuffer;
	if (!soundBuffer.loadFromFile("Audio/Track 1.wav"))
	{
		throw("COULD NOT LOAD Audio");
	}
	return soundBuffer;
}





void Game::Render(RenderWindow& window)
{
	window.clear();
	Background(window);
	window.display();
}

void Game::update(RenderWindow& window)
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				break;
			}
		}


		while (window.isOpen())
		{

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
					break;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::K))
			{
				window.clear();
				drawmenu(window);
				window.display();
			}
		}
	}
}
