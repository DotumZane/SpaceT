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
    horizontalCooldown = false;
    verticalCooldown = false;
    end_time = std::chrono::system_clock::now() + std::chrono::seconds(1);
}

void tetrisGameManager::createBlock(BlockStatus status)
{
    switch(status)
    {
    case Cyan:
        for(int x = 0; x < 4; x++)
        {
            movingx[x] = x + 3;
            movingy[x] = 0;
        }
        break;
    case Yellow:
        for(int x = 0; x < 4; x++)
        {
            if(x < 3)
            {
                movingx[x] = x + 3;
                movingy[x] = 1;
            }
            else
            {
                movingx[x] = 5;
                movingy[x] = 0;
            }
        }
        break;
    case Orange:
        for(int x = 0; x < 4; x++)
        {
            if(x < 3)
            {
                movingx[x] = x + 3;
                movingy[x] = 0;
            }
            else
            {
                movingx[x] = 5;
                movingy[x] = 1;
            }
        }
        break;
    case Blue:
        for(int x = 0; x < 4; x++)
        {
            if(x < 2)
            {
                movingx[x] = x + 3;
                movingy[x] = 0;
            }
            else
            {
                movingx[x] = x + 1;
                movingy[x] = 1;
            }
        }
        break;
    case Green:
        for(int x = 0; x < 4; x++)
        {
            if(x < 2)
            {
                movingx[x] = x + 3;
                movingy[x] = 1;
            }
            else
            {
                movingx[x] = x + 2;
                movingy[x] = 0;
            }
        }
        break;
    case Red:
        for(int x = 0; x < 4; x++)
        {
            if(x < 2)
            {
                movingx[x] = x + 3;
                movingy[x] = 0;
            }
            else
            {
                movingx[x] = x + 2;
                movingy[x] = 1;
            }
        }
        break;
    case Purple:
        for(int x = 0; x < 4; x++)
        {
            if(x != 3)
            {
                movingx[x] = x + 3;
                movingy[x] = 1;
            }
            else
            {
                movingx[x] = x + 1;
                movingy[x] = 0;
            }
        }
        break;
    }
    currentBlock = status;
}

void tetrisGameManager::moveBlock(BlockStatus status)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !horizontalCooldown &&
    (blockGrid[movingx[0] - 1][movingy[0]] == Empty ||        (movingy[0] == movingy[1] && movingx[0] - 1 == movingx[1]) ||
                                                            (movingy[0] == movingy[2] && movingx[0] - 1 == movingx[2]) ||
                                                            (movingy[0] == movingy[3] && movingx[0] - 1 == movingx[3]))
         &&(blockGrid[movingx[1] - 1][movingy[1]] == Empty || (movingy[1] == movingy[0] && movingx[1] - 1 == movingx[0]) ||
                                                            (movingy[1] == movingy[2] && movingx[1] - 1 == movingx[2]) ||
                                                            (movingy[1] == movingy[3] && movingx[1] - 1 == movingx[3]))
         &&(blockGrid[movingx[2] - 1][movingy[2]] == Empty || (movingy[2] == movingy[0] && movingx[2] - 1 == movingx[0]) ||
                                                            (movingy[2] == movingy[1] && movingx[2] - 1 == movingx[1]) ||
                                                            (movingy[2] == movingy[3] && movingx[2] - 1 == movingx[3]))
         &&(blockGrid[movingx[3] - 1][movingy[3]] == Empty || (movingy[3] == movingy[0] && movingx[3] - 1 == movingx[0]) ||
                                                            (movingy[3] == movingy[1] && movingx[3] - 1 == movingx[1]) ||
                                                            (movingy[3] == movingy[2] && movingx[3] - 1 == movingx[2]))
    && !(movingx[0] == 0 || movingx[1] == 0 || movingx[2] == 0 || movingx[3] == 0))
    {
        horizontalCooldown = true;
        for(int x = 0; x < 4; x++)
        {
            blockGrid[movingx[x]][movingy[x]] = Empty;
            movingx[x] = movingx[x] - 1;
            blockGrid[movingx[x]][movingy[x]] = status;
        }

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !horizontalCooldown &&
    (blockGrid[movingx[0] + 1][movingy[0]] == Empty ||        (movingy[0] == movingy[1] && movingx[0] + 1 == movingx[1]) ||
                                                            (movingy[0] == movingy[2] && movingx[0] + 1 == movingx[2]) ||
                                                            (movingy[0] == movingy[3] && movingx[0] + 1 == movingx[3]))
         &&(blockGrid[movingx[1] + 1][movingy[1]] == Empty || (movingy[1] == movingy[0] && movingx[1] + 1 == movingx[0]) ||
                                                            (movingy[1] == movingy[2] && movingx[1] + 1 == movingx[2]) ||
                                                            (movingy[1] == movingy[3] && movingx[1] + 1 == movingx[3]))
         &&(blockGrid[movingx[2] + 1][movingy[2]] == Empty || (movingy[2] == movingy[0] && movingx[2] + 1 == movingx[0]) ||
                                                            (movingy[2] == movingy[1] && movingx[2] + 1 == movingx[1]) ||
                                                            (movingy[2] == movingy[3] && movingx[2] + 1 == movingx[3]))
         &&(blockGrid[movingx[3] + 1][movingy[3]] == Empty || (movingy[3] == movingy[0] && movingx[3] + 1 == movingx[0]) ||
                                                            (movingy[3] == movingy[1] && movingx[3] + 1 == movingx[1]) ||
                                                            (movingy[3] == movingy[2] && movingx[3] + 1 == movingx[2]))
    && !(movingx[0] == 9 || movingx[1] == 9 || movingx[2] == 9 || movingx[3] == 9))
    {
        horizontalCooldown = true;
        for(int x = 0; x < 4; x++)
        {
            blockGrid[movingx[x]][movingy[x]] = Empty;
            movingx[x] = movingx[x] + 1;
            blockGrid[movingx[x]][movingy[x]] = status;
        }
    }
    else
    {
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            horizontalCooldown = false;
        for(int x = 0; x < 4; x++)
        {
            blockGrid[movingx[x]][movingy[x]] = status;
        }
    }
    if(end_time < std::chrono::system_clock::now() || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !verticalCooldown)
    {
        if((blockGrid[movingx[0]][movingy[0]+1] == Empty || (movingy[0] + 1 == movingy[1] && movingx[0] == movingx[1]) ||
                                                            (movingy[0] + 1 == movingy[2] && movingx[0] == movingx[2]) ||
                                                            (movingy[0] + 1 == movingy[3] && movingx[0] == movingx[3]))
         &&(blockGrid[movingx[1]][movingy[1]+1] == Empty || (movingy[1] + 1 == movingy[0] && movingx[1] == movingx[0]) ||
                                                            (movingy[1] + 1 == movingy[2] && movingx[1] == movingx[2]) ||
                                                            (movingy[1] + 1 == movingy[3] && movingx[1] == movingx[3]))
         &&(blockGrid[movingx[2]][movingy[2]+1] == Empty || (movingy[2] + 1 == movingy[0] && movingx[2] == movingx[0]) ||
                                                            (movingy[2] + 1 == movingy[1] && movingx[2] == movingx[1]) ||
                                                            (movingy[2] + 1 == movingy[3] && movingx[2] == movingx[3]))
         &&(blockGrid[movingx[3]][movingy[3]+1] == Empty || (movingy[3] + 1 == movingy[0] && movingx[3] == movingx[0]) ||
                                                            (movingy[3] + 1 == movingy[1] && movingx[3] == movingx[1]) ||
                                                            (movingy[3] + 1 == movingy[2] && movingx[3] == movingx[2]))
         && movingy[0] < 23 && movingy[1] < 23 && movingy[2] < 23 && movingy[3] < 23)
        {
            for(int x = 0; x < 4; x++)
            {
                blockGrid[movingx[x]][movingy[x]] = Empty;
                movingy[x] = movingy[x] + 1;
                blockGrid[movingx[x]][movingy[x]] = status;
            }
            verticalCooldown = true;
        }
        else
        {
            switch(rand() % 7 + 1)
            {
            case 1:
                createBlock(Cyan);
                break;
            case 2:
                createBlock(Yellow);
                break;
            case 3:
                createBlock(Orange);
                break;
            case 4:
                createBlock(Blue);
                break;
            case 5:
                createBlock(Green);
                break;
            case 6:
                createBlock(Red);
                break;
            case 7:
                createBlock(Purple);
                break;
            };
            checkLines();
        }
        end_time = std::chrono::system_clock::now() + std::chrono::seconds(1);
    }
    else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        verticalCooldown = false;
}

void tetrisGameManager::checkLines()
{
    int blocks = 0;
    bool lines[24];
    int times = 0;
    for(int y = 0; y < 24; y++)
        lines[y] = false;
    for(int y = 0; y < 24; y++)
    {
        for(int x = 0; x < 10; x++)
        {
            if(blockGrid[x][y] != Empty)
                blocks++;
        }
        if(blocks == 10)
            lines[y] = true;
        blocks = 0;
    }
    for(int y = 23; y  > 0; y--)
    {
        if(lines[y])
            times++;
        for(int x = 0; x < 10; x++)
            blockGrid[x][y] = blockGrid[x][y - times];
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

void tetrisGameManager::updateGrid(sf::RenderWindow& window)
{
    moveBlock(currentBlock);
    drawGrid(window);
}
