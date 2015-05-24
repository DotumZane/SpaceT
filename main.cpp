#include <SFML/Graphics.hpp>
#include "tetrisGameManager.h"

const int screenWidth = 290;
const int screenHeight = 696;

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Space Tetris");
    tetrisGameManager gameManager;
    gameManager.createBlock(Blue);

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear(sf::Color::Black);

        // Draw tetris grid
        gameManager.updateGrid(window);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
