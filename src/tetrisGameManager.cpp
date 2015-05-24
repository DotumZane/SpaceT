#include "tetrisGameManager.h"
tetrisGameManager::tetrisGameManager()
{

}

void tetrisGameManager::drawLogic(sf::RenderWindow& window)
{
    sf::RectangleShape block(sf::Vector2f(19, 19));
    block.setOutlineThickness(5);
    blockGrid[0][0] = Cyan;
    blockGrid[2][7] = Cyan;
    blockGrid[6][21] = Cyan;
    blockGrid[9][18] = Cyan;
    blockGrid[3][5] = Cyan;
    for(int x = 0; x < 9; x++)
    {
        for(int y = 0; y < 23; y++)
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
                break;
            case Yellow:
                block.setFillColor(sf::Color::Yellow);
                break;
            case Orange:
            //block.setFillColor(sf::Color::Orange)
                break;
            case Blue:
            block.setFillColor(sf::Color::Blue);
                break;
            case Green:
            block.setFillColor(sf::Color::Green);
                break;
            case Red:
            block.setFillColor(sf::Color::Red);
                break;
            case Purple:
            //block.setFillColor(sf::Color::Purple)
                break;
            }
            window.draw(block);
        }
    }
}
