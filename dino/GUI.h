#pragma once

#include <SFML/Graphics.hpp>
#include <queue>
#include "def.h"

enum class Mouse {
	NONE,
	PRESSED,
	CLICKED,
	RELEASED,
	HOVERED,
};

class Obsticle {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Obsticle(const std::string& path);
	~Obsticle() = default;
	void draw(sf::RenderWindow* window);
	void setPos(sf::Vector2f pos);
	sf::Vector2f getPos() const;
	sf::Sprite& getSprite();
};

class Player {
private:
	std::map<std::string, std::map<std::string, std::vector<sf::Sprite*>>> sprites;
	std::vector<sf::Texture*> textures;
	std::string state;
	std::string character;
	int step = 0;
	long long timestep;
	sf::Vector2f pos;
	int lives = 3;

public:
	Player();
	~Player();
	void setPos(sf::Vector2f pos);
	void setState(const std::string& state);
	sf::Vector2f getPos();
	void setCharacter(const std::string& character);
	void loadSprites(const std::string& path);
	void update(int tickInterval);
	void draw(sf::RenderWindow* window);
	void setLives(int lives);
	int getLives() const;
	bool checkCollision(Obsticle* sprite);
	sf::Sprite* getSprite();
};

class Button {
private:
	sf::RectangleShape rect;
	sf::Text text;
	Mouse state = Mouse::NONE;
	sf::Color fillStandard;
	sf::Color outlineStandard;
	bool deltaClick[2] = { 0, 0 };
	bool inside = false;
public:
	Button(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Font& font, const std::string& str, const sf::Color& fg = sf::Color::Black, const sf::Color& bg = sf::Color(128, 128, 128), const sf::Color& outlineColor = sf::Color::Black, float thickness = 2);
	~Button() = default;
	void draw(sf::RenderWindow* window);
	void update(sf::RenderWindow* window);
	Mouse getState() const;
	std::string getStr() const;
};

class GUI
{
private:
	sf::RenderWindow* window;
	State state = State::LANDING;
	std::queue<std::pair<std::string, Mouse>> mouse_events;
	std::vector<Button> buttons;
	sf::Font* font;
	Player* player;
public:
	explicit GUI(sf::RenderWindow* window, sf::Font* font, Player* player = nullptr);
	virtual ~GUI() = default;
	void draw();
	void handleEvents();
	void changeState(State state);
	bool getMouseEvent(std::pair<std::string, Mouse>& event);
};