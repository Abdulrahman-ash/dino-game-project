#pragma once
#ifndef MainMenu_H
#define MainMenu_H
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <chrono>
#include <ctime> 
#include <thread>



//int selectedOption_;



class MainMenu
{
private:
	sf::RenderWindow window_;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Font font;
	sf::Text title;
	sf::Text PlayText;
	sf::Text AboutText;
	sf::Text ExitText;
	sf::Text CreditsText;
	int selectedOption;
public:
	MainMenu();
	MainMenu(sf::RenderWindow& window);
	void run();
};
#endif



//Game();
//Game(float width, float height);
//void drawmenu(RenderWindow& window);
//void processEvents();
//void Background(RenderWindow& window);
//SoundBuffer Background_sound();
//void Render(RenderWindow& window);
//void update(RenderWindow& window);


//
////std::tm localtime(std::chrono::system_clock::time_point time) {
////    std::time_t currentTime = std::chrono::system_clock::to_time_t(time);
////    std::tm localTime;
////    localtime_s(&localTime, &currentTime);
////    return localTime;
////};
//
//class MainMenu {
//private:
//    sf::RenderWindow window;
//    sf::Texture backgroundTexture;
//    sf::Sprite backgroundSprite;
//    sf::Font font;
//    sf::Text PlayText;
//    sf::Text AboutText;
//    sf::Text ExitText;
//    sf::Text CreditsText;
//    sf::Texture keyboardIcon1Texture;
//    sf::Texture keyboardIcon2Texture;
//    sf::Sprite keyboardIcon1Sprite;
//    sf::Sprite keyboardIcon2Sprite;
//
//
//public:
//    MainMenu() {
//        // Create the window
//        window.create(sf::VideoMode(800, 600), "Main Menu");
//        window.setFramerateLimit(60);
//
//        // Load the background
//        if (!backgroundTexture.loadFromFile("C:/Users/Yara/Desktop/SMFLandProject/ConsoleApplication1/ConsoleApplication1/backgrounds/Image2.jpg")) {
//            // Handle the error if background cannot be loaded
//            std::cerr << "Error loading background file." << std::endl;
//            return;
//        }
//        backgroundSprite.setTexture(backgroundTexture);
//
//        // Load the font
//        if (!font.loadFromFile("Fonts/CHILLER.ttf")) {
//            // Handle the error if font cannot be loaded
//            std::cerr << "Error loading font file." << std::endl;
//            return;
//        }
//
//        // Load the keyboard icons textures
//        if (!keyboardIcon1Texture.loadFromFile("C:/Users/Yara/Desktop/SMFLandProject/ConsoleApplication1/ConsoleApplication1/icons/controls.png")) {
//            // Handle the error if the texture cannot be loaded
//            std::cerr << "Error loading keyboard icon control file." << std::endl;
//            return;
//        }
//        if (!keyboardIcon2Texture.loadFromFile("C:/Users/Yara/Desktop/SMFLandProject/ConsoleApplication1/ConsoleApplication1/icons/enter.png")) {
//            // Handle the error if the texture cannot be loaded
//            std::cerr << "Error loading keyboard icon enter file." << std::endl;
//            return;
//        }
//
//        // Set up the keyboard icons sprites
//        keyboardIcon1Sprite.setTexture(keyboardIcon1Texture);
//        keyboardIcon1Sprite.setPosition(sf::Vector2f(400.f, 200.f));
//        keyboardIcon2Sprite.setTexture(keyboardIcon2Texture);
//        keyboardIcon2Sprite.setPosition(sf::Vector2f(400.f, 300.f));
//
//        // Set up the text objects for the menu options
//        PlayText.setString("Play");
//        PlayText.setFont(font);
//        PlayText.setCharacterSize(50);
//        PlayText.setPosition(sf::Vector2f(300.f, 200.f));
//
//        AboutText.setString("About");
//        AboutText.setFont(font);
//        AboutText.setCharacterSize(50);
//        AboutText.setPosition(sf::Vector2f(300.f, 300.f));
//
//        CreditsText.setString("Credits");
//        CreditsText.setFont(font);
//        CreditsText.setCharacterSize(50);
//        CreditsText.setPosition(sf::Vector2f(300.f, 400.f));
//
//        ExitText.setString("Exit");
//        ExitText.setFont(font);
//        ExitText.setCharacterSize(50);
//        ExitText.setPosition(sf::Vector2f(300.f, 500.f));
//    }
//
//    void run(sf::Text t) {
//        while (window.isOpen()) {
//            sf::Event event;
//            while (window.pollEvent(event)) {
//                if (event.type == sf::Event::Closed) {
//                    window.close();
//                }
//            }
//
//            window.clear();
//            window.draw(backgroundSprite);
//            window.draw(PlayText);
//            window.draw(AboutText);
//            window.draw(CreditsText);
//            window.draw(ExitText);
//            window.draw(keyboardIcon1Sprite);
//            window.draw(keyboardIcon2Sprite);
//            window.draw(t);
//            window.display();
//
//        }
//    }
//  
//    //void calct() {
//    //    // Get the current time in the user's local time zone
//    // 
//
//    //    tm currentTimeLocal = localtime(std::chrono::system_clock::now());
//
//    //    // Format the time string
//    //    char timeStr[9];
//    //    std::strftime(timeStr, sizeof timeStr, "%T", &currentTimeLocal);
//
//    //    // Set the time string in the SFML text
//    //    timeText.setString(timeStr);
//
//
//    //    // Wait for one second before updating the time again
//    //    std::this_thread::sleep_for(std::chrono::seconds(1));
//
//    //};
//
//};