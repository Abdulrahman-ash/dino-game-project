#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include "MainMenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;

/// main function 
int main()
{
	RenderWindow window(VideoMode(1200, 800), "Dino Runner!", Style::Close | Style::Titlebar);
	Game game(1200, 800);
	SoundBuffer soundBuffer = game.Background_sound();
	Sound sound;
	sound.setBuffer(soundBuffer);
	sound.play();
	while (window.isOpen())
	{

		game.Render(window);
		game.update(window);
	}
}

//
//int main() {
//
//}
////
////// Function to convert UTC time to local time
////std::tm localtime(std::chrono::system_clock::time_point time) {
////std::time_t currentTime = std::chrono::system_clock::to_time_t(time);
////std::tm localTime;
////localtime_s(&localTime, &currentTime);
////return localTime;
////        };
////
//////std::tm localtime(std::chrono::system_clock::time_point time) {
//////std::time_t currentTime = std::chrono::system_clock::to_time_t(time);
//////std::tm localTime;
//////localtime_s(&localTime, &currentTime);
//////return localTime;
//////        };
//////// Function to convert UTC time to local time
//////std::tm localtime(std::chrono::system_clock::time_point time)
//////{
//////    std::time_t currentTime = std::chrono::system_clock::to_time_t(time);
//////    std::tm localTime;
//////#ifdef _WIN32
//////    localtime_s(&localTime, &currentTime);
//////#else
//////    localtime_r(&currentTime, &localTime);
//////#endif
//////    return localTime;
//////}
////
////int main()
////{
//////    // Create the window
//////    sf::RenderWindow window(sf::VideoMode(800, 600), "Main Menu");
//////    window.setFramerateLimit(60);
////    //sf::Texture backgroundTexture;
////    //if (!backgroundTexture.loadFromFile("C:/Users/Yara/Desktop/SMFLandProject/ConsoleApplication1/ConsoleApplication1/backgrounds/Image2.jpg"))
////    //{
////    //    // Handle the error if background cannot be loaded
////    //    std::cerr << "Error loading background file." << std::endl;
////    //    return 1;
////    //}
////    //sf::Sprite backgroundSprite;
////    //backgroundSprite.setTexture(backgroundTexture);
////    //// Create the font for the text
////    //sf::Font font;
////    //if (!font.loadFromFile("Fonts/CHILLER.ttf"))
////    //{
////    //    // Handle the error if font cannot be loaded
////    //    std::cerr << "Error loading font file." << std::endl;
////    //    return 1;
////    //}
////
////    //// Create the textures for the keyboard icons
////    //sf::Texture keyboardIcon1Texture;
////    //if (!keyboardIcon1Texture.loadFromFile("C:/Users/Yara/Desktop/SMFLandProject/ConsoleApplication1/ConsoleApplication1/icons/controls.png"))
////    //{
////    //    // Handle the error if the texture cannot be loaded
////    //    std::cerr << "Error loading keyboard icon control file." << std::endl;
////    //    return 1;
////    //}
////    //sf::Texture keyboardIcon2Texture;
////    //if (!keyboardIcon2Texture.loadFromFile("C:/Users/Yara/Desktop/SMFLandProject/ConsoleApplication1/ConsoleApplication1/icons/enter.png"))
////    //{
////    //    // Handle the error if the texture cannot be loaded
////    //    std::cerr << "Error loading keyboard icon enter file." << std::endl;
////    //    return 1;
////    //}
////
////    //// Create the sprites for the keyboard icons
////    //sf::Sprite keyboardIcon1Sprite(keyboardIcon1Texture);
////    //keyboardIcon1Sprite.setPosition(sf::Vector2f(400.f, 200.f));
////    //sf::Sprite keyboardIcon2Sprite(keyboardIcon2Texture);
////    //keyboardIcon2Sprite.setPosition(sf::Vector2f(400.f, 300.f));
////
////
////    // Create the text objects for the menu options
////    //sf::Text PlayText("Play", font, 50);
////    //PlayText.setPosition(sf::Vector2f(300.f, 200.f));
////
////    //sf::Text AboutText("About", font, 50);
////    //AboutText.setPosition(sf::Vector2f(300.f, 300.f));
////
////    //sf::Text CreditsText("Credits", font, 50);
////    //CreditsText.setPosition(sf::Vector2f(300.f, 400.f));
////
////    //sf::Text ExitText("Exit", font, 50);
////    //ExitText.setPosition(sf::Vector2f(300.f, 500.f));
////
////    //// Create the text object for the time display
////    //sf::Text timeText("", font, 50);
////    //timeText.setPosition(sf::Vector2f(100.f, 100.f));
////
////    //// Highlight rectangle for selected menu item
////    //sf::RectangleShape highlight(sf::Vector2f(180, 50));
////    //highlight.setFillColor(sf::Color::Transparent);
////    //highlight.setOutlineThickness(2);
////    //highlight.setOutlineColor(sf::Color::White);
////
////    //// Initialize variables for keyboard control
////    //int selectedMenuItem = 0;
////    //bool upKeyPressed = false;
////    //bool downKeyPressed = false;
////
////    //// The game loop
////    //while (window.isOpen())
////    //{
////    //    // Handle events
////    //    sf::Event event;
////    //    while (window.pollEvent(event))
////    //    {
////    //        if (event.type == sf::Event::Closed)
////    //            window.close();
////   
////    //        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
////    //        {
////    //            // Check if the mouse click was inside any of the menu options
////    //            if (PlayText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
////    //            {
////    //                // Handle the "Play" option
////    //                std::cout << "Play option clicked!" << std::endl;
////    //            }
////    //            else if (AboutText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
////    //            {
////    //                // Handle the "About" option
////    //                std::cout << "About option clicked!" << std::endl;
////    //            }
////    //            else if (CreditsText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
////    //            {
////    //                // Handle the "Credits" option
////    //                std::cout << "Credits option clicked!" << std::endl;
////    //            }
////    //            else if (ExitText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
////    //            {
////    //                // Handle the "Exit" option
////    //                std::cout << "Exit option clicked!" << std::endl;
////    //                window.close();
////    //            }
////    //        }
////            //// Handle keyboard events
////            //if (event.type == sf::Event::KeyPressed)
////            //{
////            //    if (event.key.code == sf::Keyboard::Up)
////            //    {
////            //        upKeyPressed = true;
////            //    }
////            //    else if (event.key.code == sf::Keyboard::Down)
////            //    {
////            //        downKeyPressed = true;
////            //    }
////            //    else if (event.key.code == sf::Keyboard::Enter)
////            //    {
////            //        switch (selectedMenuItem)
////            //        {
////            //        case 0:
////            //            std::cout << "Play selected\n";
////            //            break;
////            //        case 1:
////            //            std::cout << "About selected\n";
////            //            break;
////            //        case 2:
////            //            std::cout << "Credits selected\n";
////            //            break;
////            //        case 3:
////            //            window.close();
////            //            break;
////            //        }
////            //    }
////
////            //    //else if (event.key.code == sf::Keyboard::Backspace)
////            //    //{
////            //    //    // Go back to previous menu
////            //    //    selectedMenuItem = 0;
////            //    //    highlight.setPosition(350, 200);
////            //    //}
////            //}
////            //else if (event.type == sf::Event::KeyReleased)
////            //{
////            //    if (event.key.code == sf::Keyboard::Up)
////            //    {
////            //        upKeyPressed = false;
////            //    }
////            //    else if (event.key.code == sf::Keyboard::Down)
////            //    {
////            //        downKeyPressed = false;
////            //    }
////            //}
////    //    }
////    //}
////
////
////        //// Handle keyboard events
////        //if (event.type == sf::Event::KeyPressed)
////        //{
////        //    if (event.key.code == sf::Keyboard::Up)
////        //    {
////        //        upKeyPressed = true;
////        //    }
////        //    else if (event.key.code == sf::Keyboard::Down)
////        //    {
////        //        downKeyPressed = true;
////        //    }
////        //    else if (event.key.code == sf::Keyboard::Enter)
////        //    {
////        //        switch (selectedMenuItem)
////        //        {
////        //        case 0:
////        //            std::cout << "Play selected\n";
////        //            break;
////        //        case 1:
////        //            std::cout << "About selected\n";
////        //            break;
////        //        case 2:
////        //            std::cout << "Credits selected\n";
////        //            break;
////        //        case 3:
////        //            window.close();
////        //            break;
////        //        }
////        //    }
////        //    else if (event.key.code == sf::Keyboard::Backspace)
////        //    {
////        //        // Go back to previous menu
////        //        selectedMenuItem = 0;
////        //        highlight.setPosition(350, 200);
////        //    }
////        //}
////        //else if (event.type == sf::Event::KeyReleased)
////        //{
////        //    if (event.key.code == sf::Keyboard::Up)
////        //    {
////        //        upKeyPressed = false;
////        //    }
////        //    else if (event.key.code == sf::Keyboard::Down)
////        //    {
////        //        downKeyPressed = false;
////        //    }
////        //}
////
////
////    //// Move highlight rectangle based on up/down key presses
////    //if (upKeyPressed)
////    //{
////    //    if (selectedMenuItem > 0)
////    //    {
////    //        selectedMenuItem--;
////    //        highlight.setPosition(350, 200 + selectedMenuItem * 60);
////    //    }
////    //}
////    //else if (downKeyPressed)
////    //{
////    //    if (selectedMenuItem < 3)
////    //    {
////    //        selectedMenuItem++;
////    //        highlight.setPosition(350, 200 + selectedMenuItem * 60);
////    //    }
////    //}
////
////    //// Get the current time in the user's local time zone
////    //auto currentTimeLocal = localtime(std::chrono::system_clock::now());
////
////    //// Format the time string
////    //char timeStr[9];
////    //std::strftime(timeStr, sizeof timeStr, "%T", &currentTimeLocal);
////
////    //// Set the time string in the SFML text
////    //timeText.setString(timeStr);
////
////    //// Draw the menu options on the window
////    //window.clear();
////    //window.draw(backgroundSprite);
////    //window.draw(PlayText);
////    //window.draw(AboutText);
////    //window.draw(CreditsText);
////    //window.draw(ExitText);
////    //window.draw(timeText);
////    ////window.draw(keyboardIcon1Sprite);
////    ////window.draw(keyboardIcon2Sprite);
////    //window.display();
////
////
////    // Wait for one second before updating the time again
////    //std::this_thread::sleep_for(std::chrono::seconds(1));
////    MainMenu* m = new MainMenu();
////    sf::Text timeText;
////
////    tm currentTimeLocal = localtime(std::chrono::system_clock::now());
////
////    // Format the time string
////    char timeStr[9];
////    std::strftime(timeStr, sizeof timeStr, "%T", &currentTimeLocal);
////
////    // Set the time string in the SFML text
////    timeText.setString(timeStr);
////
////
////    // Wait for one second before updating the time again
////    std::this_thread::sleep_for(std::chrono::seconds(1));
////
////    m->run(timeText);
////    return 0;
////}
////
////
////
