#include "MainMenu.h"
MainMenu::MainMenu() : window_(sf::VideoMode(800, 600), "Main Menu"), selectedOption(0) 
{

     //the window
    window_.setFramerateLimit(60);

	// Load the font
	if (!font.loadFromFile("Fonts/CHILLER.ttf"))
	{
		throw("COULD NOT LOAD FONT");
	}

	// Load the background
	if (!backgroundTexture.loadFromFile("C:/Users/Yara/Desktop/SMFLandProject/ConsoleApplication1/ConsoleApplication1/backgrounds/Image2.jpg"))
	{
		// Handle the error if background cannot be loaded
		std::cerr << "Error loading background file." << std::endl;
	}

	// Set up the background sprite
	backgroundSprite.setTexture(backgroundTexture);

	// Set up the title text
	title.setFont(font);
	title.setString("Main Menu");
	title.setCharacterSize(50);
	title.setPosition(200, 50);

	// Set up the menu options
	PlayText.setFont(font);
	PlayText.setString("Play");
	PlayText.setCharacterSize(30);
	PlayText.setPosition(300, 200);

	AboutText.setFont(font);
	AboutText.setString("About");
	AboutText.setCharacterSize(30);
	AboutText.setPosition(300, 250);

	CreditsText.setFont(font);
	CreditsText.setString("Credits");
	CreditsText.setCharacterSize(30);
	CreditsText.setPosition(300, 300);

	ExitText.setFont(font);
	ExitText.setString("Exit");
	ExitText.setCharacterSize(30);
	ExitText.setPosition(300, 350);

    selectedOption = 0;

};


void MainMenu::run()
{
    sf::Event event;

    while (window_.isOpen()) {
        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window_.close();
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                // Check if the mouse click was inside any of the menu options
                if (PlayText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    // Handle the "Play" option
                    std::cout << "Play option clicked!" << std::endl;
                }
                else if (AboutText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    // Handle the "About" option
                    std::cout << "About option clicked!" << std::endl;
                }
                else if (CreditsText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    // Handle the "Credits" option
                    std::cout << "Credits option clicked!" << std::endl;
                }
                else if (ExitText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    // Handle the "Exit" option
                    std::cout << "Exit option clicked!" << std::endl;
                    window_.close();
                }
            }
    

            //Handle Keyboard press

            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    selectedOption--;
                    break;
                case sf::Keyboard::Down:
                    selectedOption++;
                    break;
                case sf::Keyboard::Return:
                    // Perform action based on selected option
                    switch (selectedOption) {
                    case 0:
                        //play selected
                        break;
                    case 1:
                        //about selected
                        break;
                    case 2:
                        //Credits selected
                        break;
                    case 3:
                        //Exit selected
                        window_.close();
                    }
                    break;
                }

                // Ensure selectedOption is within bounds
                if (selectedOption < 0) {
                    selectedOption = 3;
                }
                else if (selectedOption > 3) {
                    selectedOption = 0;
                }
            }
        }

        // Clear window
        window_.clear(sf::Color::White);

        // Draw background and title
        window_.draw(backgroundSprite);
        window_.draw(title);

        // Draw menu options
        window_.draw(PlayText);
        window_.draw(AboutText);
        window_.draw(CreditsText);
        window_.draw(ExitText);

        // Update the window
        window_.display();
    }
}
