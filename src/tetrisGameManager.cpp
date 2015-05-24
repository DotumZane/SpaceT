#include "tetrisGameManager.h"
tetrisGameManager::tetrisGameManager()
{
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 24; y++)
        {
            blockGrid[x][y] = Empty;
        }
    }
}

void tetrisGameManager::drawGrid(sf::RenderWindow& window)
{
    sf::RectangleShape block(sf::Vector2f(19, 19));
    block.setOutlineThickness(5);
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 24; y++)
        {
            block.setPosition(x * 29 + 5, y * 29 + 5);
            switch(blockGrid[x][y])
            {
            case Empty:
                block.setFillColor(sf::Color::Black);
                block.setOutlineColor(sf::Color::Black);
                break;
            case Cyan:
                block.setFillColor(sf::Color::Cyan);
                block.setOutlineColor(sf::Color(96, 216, 220, 225));
                break;
            case Yellow:
                block.setFillColor(sf::Color::Yellow);
                block.setOutlineColor(sf::Color(222, 222, 79, 225));
                break;
            case Orange:
                block.setFillColor(sf::Color(255, 166, 31, 255));
                block.setOutlineColor(sf::Color(192, 124, 22, 255));
                break;
            case Blue:
            block.setFillColor(sf::Color::Blue);
            block.setOutlineColor(sf::Color(23, 19, 138, 255));
                break;
            case Green:
            block.setFillColor(sf::Color::Green);
            block.setOutlineColor(sf::Color(42, 183, 37, 255));
                break;
            case Red:
            block.setFillColor(sf::Color::Red);
            block.setOutlineColor(sf::Color(195, 25, 30, 255));
                break;
            case Purple:
            block.setFillColor(sf::Color(239, 68, 245, 255));
            block.setOutlineColor(sf::Color(181, 69, 195, 255));
                break;
            }
            window.draw(block);
        }
    }
}
