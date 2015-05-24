#include "tetrisGameManager.h"
tetrisGameManager::tetrisGameManager()
{

}

void tetrisGameManager::drawLogic(sf::RenderWindow& window)
{
    sf::RectangleShape block(sf::Vector2f(19, 19));
    block.setOutlineThickness(5);
    for(int x = 0; x < 9; x++)
    {
        for(int y = 0; y < 23; y++)
        {
            blockGrid[x][y] = Empty;
        }
    }
    blockGrid[0][0] = Cyan;
    blockGrid[1][0] = Cyan;
    blockGrid[2][0] = Cyan;
    blockGrid[3][0] = Cyan;
    blockGrid[4][0] = Cyan;
    blockGrid[5][0] = Cyan;
    blockGrid[6][0] = Cyan;
    blockGrid[7][0] = Cyan;
    blockGrid[8][0] = Cyan;
    blockGrid[9][0] = Cyan;
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
                block.setOutlineColor(sf::Color::Red);
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
