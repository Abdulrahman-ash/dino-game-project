
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Constants for window dimensions
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Constants for object properties
const int OBJECT_SIZE = 50;
const int OBJECT_SPEED = 3;

// Enumeration for object types
enum class ObjectType { Treasure1, Treasure2, FlyingEnemy, StandingEnemy, Heart };

// Abstract base class for hittable objects
class HittableObject {
public:
    sf::RectangleShape shape;
    ObjectType type;
    bool isDestroyed;

    HittableObject(ObjectType objType, sf::Vector2f position)
        : type(objType), isDestroyed(false)
    {
        shape.setSize(sf::Vector2f(OBJECT_SIZE, OBJECT_SIZE));
        shape.setOrigin(sf::Vector2f(OBJECT_SIZE / 2, OBJECT_SIZE / 2));
        shape.setPosition(position);
    }

    virtual void update()
    {
        shape.move(0, OBJECT_SPEED);
    }

    virtual void onHit(int& score, int& lives) = 0;
};

// Concrete class for treasure objects
class Treasure : public HittableObject {
public:
    int treasureType;

    Treasure(int type, sf::Vector2f position)
        : HittableObject(ObjectType::Treasure1, position), treasureType(type)
    {
        type = (type == 1) ? ObjectType::Treasure1 : ObjectType::Treasure2;
    }

    void onHit(int& score, int& lives) override
    {
        score += treasureType;
    }
};

// Concrete class for enemy objects
class Enemy : public HittableObject {
public:
    Enemy(ObjectType type, sf::Vector2f position)
        : HittableObject(type, position) {}

    void onHit(int& score, int& lives) override
    {
        if (type == ObjectType::StandingEnemy || type == ObjectType::FlyingEnemy)
            lives--;
    }
};

// Concrete class for heart objects
class Heart : public HittableObject {
public:
    Heart(sf::Vector2f position)
        : HittableObject(ObjectType::Heart, position) {}

    void onHit(int& score, int& lives) override
    {
        lives++;
    }
};

int main()
{
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Create the game window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Hittable Objects");
    window.setFramerateLimit(60);

    // Vector to hold hittable objects
    std::vector<std::shared_ptr<HittableObject>> objects;

    // Game variables
    int score = 0;
    int lives = 3;

    // Score and lives display
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    sf::Text livesText;
    livesText.setFont(font);
    livesText.setCharacterSize(20);
    livesText.setFillColor(sf::Color::White);
    livesText.setPosition(10, 40);

    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::Black);

        // Randomly generate new objects
        if (std::rand() % 100 < 2)
        {
            int objectType = std::rand() % 5; // Five object types
            sf::Vector2f position(std::rand() % WINDOW_WIDTH, -OBJECT_SIZE);

            switch (objectType)
            {
            case 0:
            case 1:
                objects.push_back(std::make_shared<Treasure>(objectType + 1, position));
                break;
            case 2:
            case 3:
                objects.push_back(std::make_shared<Enemy>(static_cast<ObjectType>(objectType), position));
                break;
            case 4:
                objects.push_back(std::make_shared<Heart>(position));
                break;
            }
        }

        // Update and draw the objects
        for (auto& object : objects)
        {
            object->update();

            // Check if object is out of bounds or destroyed
            if (object->shape.getPosition().y > WINDOW_HEIGHT || object->isDestroyed)
                continue;

            // Draw the object
            switch (object->type)
            {
            case ObjectType::Treasure1:
                object->shape.setFillColor(sf::Color::Yellow);
                break;
            case ObjectType::Treasure2:
                object->shape.setFillColor(sf::Color::Green);
                break;
            case ObjectType::FlyingEnemy:
                object->shape.setFillColor(sf::Color::Red);
                break;
            case ObjectType::StandingEnemy:
                object->shape.setFillColor(sf::Color::Blue);
                break;
            case ObjectType::Heart:
                object->shape.setFillColor(sf::Color::Magenta);
                break;
            }

            window.draw(object->shape);

            // Handle collisions with player
            if (object->shape.getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                object->onHit(score, lives);
                object->isDestroyed = true;
            }
        }

        // Update score and lives display
        scoreText.setString("Score: " + std::to_string(score));
        livesText.setString("Lives: " + std::to_string(lives));

        // Draw score and lives display
        window.draw(scoreText);
        window.draw(livesText);

        // Display the window
        window.display();
    }

    return 0;
}
