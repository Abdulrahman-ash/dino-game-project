#include "GUI.h"

#include <chrono>
#include <format>

long long getTime() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

GUI::GUI(sf::RenderWindow* window, sf::Font* font, Player* player) :window(window), font(font), player(player) {}

std::string get_current_time_and_date()
{
	auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
	return std::format("{:%X}", time);
}

void GUI::draw()
{
	sf::Text text("", *font);
	sf::RectangleShape rect;

	if (state == State::LANDING) {
		text.setString("Press Enter key to continue");
		text.setCharacterSize(30);
		text.setStyle(sf::Text::Bold);
		text.setFillColor(sf::Color::Black);
		text.setPosition(window->getSize().x / 2 - text.getGlobalBounds().width / 2, window->getSize().y - 100);

		window->draw(text);

		text.setString("Dino Game");

		text.setCharacterSize(50);
		text.setFillColor(sf::Color(128, 255, 128));
		text.setPosition(window->getSize().x / 2 - text.getGlobalBounds().width / 2, 100);

		rect.setFillColor(sf::Color::Black);
		rect.setOutlineColor(sf::Color(128, 128, 0));
		rect.setOutlineThickness(2);
		rect.setPosition(text.getPosition().x, text.getPosition().y + 10);
		rect.setSize(sf::Vector2f(text.getGlobalBounds().width + 8, text.getGlobalBounds().height + 10));

		window->draw(rect);
		window->draw(text);
	} else if (state == State::MAIN) {
		text.setString("Main Menu");

		text.setCharacterSize(50);
		text.setFillColor(sf::Color(255, 128, 0));
		text.setPosition(window->getSize().x / 2 - text.getGlobalBounds().width / 2, 100);

		window->draw(text);
	} else if (state == State::GAME) {
		//text.setString("Score: " + std::to_string(score));
		text.setCharacterSize(30);
		text.setStyle(sf::Text::Bold);
		text.setFillColor(sf::Color::Red);
		text.setPosition(10, 10);

		window->draw(text);

		if (player) {
			text.setString("Lives: " + std::to_string(player->getLives()));
			text.setCharacterSize(30);
			text.setStyle(sf::Text::Bold);
			text.setFillColor(sf::Color::Red);
			text.setPosition(10, 10);

			window->draw(text);
		}
	}

	text.setString(get_current_time_and_date());
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Red);
	text.setPosition(window->getSize().x - 140, 10);

	window->draw(text);

	for (auto b : buttons)
		b.draw(window);
}

bool GUI::getMouseEvent(std::pair<std::string, Mouse>& event) {
	if (mouse_events.empty()) {
		return false;
	}
	event = mouse_events.front();
	mouse_events.pop();
	return true;
}

void GUI::handleEvents()
{
	for (Button& b : buttons) {
		b.update(window);

		if ((int)b.getState())
			mouse_events.emplace(b.getStr(), b.getState());
	}
}

void GUI::changeState(State state) {
	this->state = state;
	buttons.clear();
	switch (state) {
	case State::LANDING:
		break;
	case State::MAIN:
		buttons.push_back(Button(sf::Vector2f(window->getSize().x / 2 - 100, 200), sf::Vector2f(window->getSize().x / 4, 50), *font, "Character"));
		buttons.push_back(Button(sf::Vector2f(window->getSize().x / 2 - 100, 260), sf::Vector2f(window->getSize().x / 4, 50), *font, "About"));
		buttons.push_back(Button(sf::Vector2f(window->getSize().x / 2 - 100, 320), sf::Vector2f(window->getSize().x / 4, 50), *font, "Credits"));
		buttons.push_back(Button(sf::Vector2f(window->getSize().x / 2 - 100, 380), sf::Vector2f(window->getSize().x / 4, 50), *font, "Exit"));
		break;
	case State::CHARACTER:
		buttons.push_back(Button(sf::Vector2f(window->getSize().x / 2 - 100, 200), sf::Vector2f(window->getSize().x / 4, 50), *font, "Santa"));
		buttons.push_back(Button(sf::Vector2f(window->getSize().x / 2 - 100, 260), sf::Vector2f(window->getSize().x / 4, 50), *font, "Boy"));
		buttons.push_back(Button(sf::Vector2f(window->getSize().x / 2 - 100, 360), sf::Vector2f(window->getSize().x / 4, 50), *font, "Play"));
		break;
	}
}

void Player::setLives(int lives) {
	this->lives = lives;
}

int Player::getLives() const {
	return lives;
}

bool Player::checkCollision(Obsticle* ob)
{
	sf::FloatRect playerBounds = getSprite()->getLocalBounds();
	sf::FloatRect obsticleBounds = ob->getSprite().getLocalBounds();

	return playerBounds.intersects(obsticleBounds);
}

sf::Sprite* Player::getSprite()
{
	if (!sprites.contains(character) || !sprites[character].contains(state))return nullptr;
	return sprites[character][state][step];
}

void Player::setPos(sf::Vector2f pos)
{
	this->pos = pos;
}

Player::Player() : timestep(getTime())
{}

Player::~Player() {
	while (!textures.empty()) {
		auto t = textures.back();
		textures.pop_back();
		delete t;
	}

	for (auto& character : sprites)
		for (auto& states : character.second)
			for (auto& state : states.second)
				delete state;
}

void Player::setState(const std::string& state)
{
	step = 0;
	this->state = state;
}

void Player::setCharacter(const std::string& character) {
	this->character = character;
}

sf::Vector2f Player::getPos()
{
	return pos;
}

void Player::loadSprites(const std::string& path)
{
	std::string cha = "Boy";
	std::string st = "Idle";
	int size = 10;
	for (int i = 1; i <= size; i++) {
		auto texturep = new sf::Texture();
		auto sprite = new sf::Sprite();
		texturep->loadFromFile("sprites/" + cha + "/" + st + " (" + std::to_string(i) + ").png");
		sprite->setTexture(*texturep);
		sprite->setScale(0.25, 0.25);
		sprites[cha][st].push_back(sprite);
		textures.push_back(texturep);
	}

	cha = "Boy";
	st = "Run";
	size = 8;
	for (int i = 1; i <= size; i++) {
		auto texturep = new sf::Texture();
		auto sprite = new sf::Sprite();
		texturep->loadFromFile("sprites/" + cha + "/" + st + " (" + std::to_string(i) + ").png");
		sprite->setTexture(*texturep);
		sprite->setScale(0.25, 0.25);
		sprites[cha][st].push_back(sprite);
	}

	cha = "Santa";
	st = "Idle";
	size = 16;
	for (int i = 1; i <= size; i++) {
		auto texturep = new sf::Texture();
		auto sprite = new sf::Sprite();
		texturep->loadFromFile("sprites/" + cha + "/" + st + " (" + std::to_string(i) + ").png");
		sprite->setTexture(*texturep);
		sprite->setScale(0.25, 0.25);
		sprites[cha][st].push_back(sprite);
	}

	cha = "Santa";
	st = "Run";
	size = 11;
	for (int i = 1; i <= size; i++) {
		auto texturep = new sf::Texture();
		auto sprite = new sf::Sprite();
		texturep->loadFromFile("sprites/" + cha + "/" + st + " (" + std::to_string(i) + ").png");
		sprite->setTexture(*texturep);
		sprite->setScale(0.25, 0.25);
		sprites[cha][st].push_back(sprite);
	}
}

void Player::update(int timeInterval)
{
	if (!sprites.contains(character) || !sprites[character].contains(state))return;

	if (getTime() - timestep > timeInterval) {
		step++;
		step %= sprites[character][state].size();
		timestep = getTime();
	}
}

void Player::draw(sf::RenderWindow* window)
{
	if (sprites.contains(character) && sprites[character].contains(state)) {
		sprites[character][state][step]->setPosition(pos);
		window->draw(*sprites[character][state][step]);
	}
}

Obsticle::Obsticle(const std::string& path) {
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5);
}
void Obsticle::draw(sf::RenderWindow* window) {
	window->draw(sprite);
}
void Obsticle::setPos(sf::Vector2f pos) {
	sprite.setPosition(pos);
}
sf::Vector2f Obsticle::getPos() const {
	return sprite.getPosition();
}

sf::Sprite& Obsticle::getSprite()
{
	return sprite;
}

Button::Button(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Font& font, const std::string& str, const sf::Color& fg, const sf::Color& bg, const sf::Color& outlineColor, float thickness) : fillStandard(bg), outlineStandard(outlineColor)
{
	rect.setPosition(pos);
	rect.setSize(size);
	rect.setFillColor(bg);
	rect.setOutlineColor(outlineColor);
	rect.setOutlineThickness(thickness);

	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(40);
	text.setFillColor(fg);
	text.setPosition(pos.x + size.x / 2 - text.getGlobalBounds().width / 2, pos.y);
}

void Button::draw(sf::RenderWindow* window)
{
	window->draw(rect);
	window->draw(text);
}

void Button::update(sf::RenderWindow* window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	inside = rect.getGlobalBounds().contains(mousePosF);

	deltaClick[0] = deltaClick[1];

	if (inside && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		rect.setFillColor(sf::Color::Cyan);
		rect.setOutlineColor(sf::Color::Red);
		deltaClick[1] = true;
	} else if (inside) {
		rect.setFillColor(fillStandard);
		rect.setOutlineColor(sf::Color::Red);
		deltaClick[1] = false;
	} else {
		rect.setFillColor(fillStandard);
		rect.setOutlineColor(outlineStandard);
		deltaClick[1] = false;
	}
}

Mouse Button::getState() const
{
	if (deltaClick[0] && deltaClick[1])
		return Mouse::PRESSED;
	else if (deltaClick[0] && !deltaClick[1])
		return Mouse::RELEASED;
	else if (!deltaClick[0] && deltaClick[1])
		return Mouse::CLICKED;
	else if (inside)
		return Mouse::HOVERED;
	else
		return Mouse::NONE;
}

std::string Button::getStr() const
{
	return text.getString();
}