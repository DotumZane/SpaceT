#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <textureManager.h>
#include <enemyManager.h>
#include <playerManager.hpp>
#include "tetrisGameManager.h"
#include "main.h"
/*
    File: main
        contains the main loop.

        this is the file to start  looking at this file
        before editing anything.

    Depends on:
        <tetrisGameManager>
        <globals>
*/

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Space Tetris");
    tetrisGameManager gameManager;

    textureManager images;

    if(!images.addAllCommonTextures())
        return 255;
    sf::FloatRect screenRectSpaceInv(tetrisGameManager::getTetrisGameSize().x,0,
            screenWidth - tetrisGameManager::getTetrisGameSize().x,screenHeight);
    playerManager playMan(images,screenRectSpaceInv);
    enemyManager eneMan(images,screenRectSpaceInv);
            //the size of screen playing in.)

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            switch(event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
                }
        }

        // Clear screen
        window.clear(sf::Color::Black);

        // Draw tetris grid
        gameManager.updateGrid(window);
        eneMan.update(window);
        playMan.drawItems(window);
        playMan.KeyEvents();
        playMan.checkSides(); //*/
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
