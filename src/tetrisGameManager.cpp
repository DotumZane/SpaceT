#include "tetrisGameManager.h"
#include <SFML/Window/Keyboard.hpp>
#include  <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "main.h"
/**
    this file is in major need of reformatting
    it has broken two major guidelines
    the 200 lines per file rule
    and the 4 indentations limit.
    and the code need to be re formatted
*/
/// setup a tetris game.
tetrisGameManager::tetrisGameManager()
{
    ///reset the entire block grid to none
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 24; y++)
        {
            blockGrid[x][y] = Empty;
        }
    }
    horizontalCooldown = false;
    verticalCooldown = false;
    end_time = std::chrono::system_clock::now() + std::chrono::milliseconds(250);
    gameOver = false;
    /// create a inital start piece
    this->createBlock(Red);
}
/// creates a block piece -- recommend moving to tetris block class.
void tetrisGameManager::createBlock(BlockColors status)
{
    /// note what shape describing with what color
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
                movingx[x] = x + 4;
                movingy[x] = 0;
            }
            else
            {
                movingx[x] = x + 2;
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
    default:
        break;
    }
    /// what is happening here why am i doing this?
    currentBlock = status;
}
/// which blocks am i moving
/// why am i returning a booleans
void tetrisGameManager::moveBlock(BlockColors status)
{


    if(!horizontalCooldown)
    {
        bool safeRight = false;
        bool safeLeft = false;
        for(unsigned int i = 0; i < movingx.size(); i++)
        {
            safeLeft  |= (blockGrid[movingx[i]-1][movingy[i]] == Empty);
            safeRight |= (blockGrid[movingx[i]+1][movingy[i]] == Empty);
            for(unsigned int k = 0; k < movingx.size(); k++)
            {
                safeLeft |= ( (movingx[i]-1 == movingx[k]) && movingy[i] == movingy[k]);
                safeRight |= ( (movingx[i]+1 == movingx[k]) && movingy[i] == movingy[k]);
            }
            safeLeft  &= (movingx[i]+1 < tetrisGameManager::blockGridSize_X - 1);
            safeRight &= (movingx[i]-1 > 1);

        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
                !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& safeLeft)
         {
            /*
                check if the closest block to the side of the wall is
                going to go off screen.
            */
                horizontalCooldown = true;
                for(int x = 0; x < 4; x++)
                {
                    blockGrid[movingx[x]][movingy[x]] = Empty;
                    movingx[x] = movingx[x] - 1;
                    blockGrid[movingx[x]][movingy[x]] = status;
                }
         } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) & safeRight)
        {
            horizontalCooldown = true;
            for(int x = 0; x < 4; x++)
            {
                blockGrid[movingx[x]][movingy[x]] = Empty;
                movingx[x] = movingx[x] + 1;
                blockGrid[movingx[x]][movingy[x]] = status;
            }
        }
    }
    else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        horizontalCooldown = false;
         for(int x = 0; x < 4; x++)
        {
            blockGrid[movingx[x]][movingy[x]] = status;
        }
    }

    /// this is really bad formatted code that looks extremely hard to adjust
    /// this really needs to broken up to different if statements
    /// looping through array would be more flexible and eaiser to read
  /*  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
    && !horizontalCooldown)
    {
        auto minMaxItr = std::minmax_element(movingx.begin(),movingy.end());
        if( !(*minMaxItr.first) - 1 == -1)
        {
            horizontalCooldown = true;
            for(int x = 0; x < 4; x++)
            {
                blockGrid[movingx[x]][movingy[x]] = Empty;
                movingx[x] = movingx[x] - 1;
                blockGrid[movingx[x]][movingy[x]] = status;
            }
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
        /// if not moving blocks use a simple setting of colors
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            horizontalCooldown = false;
        for(int x = 0; x < 4; x++)
        {
            blockGrid[movingx[x]][movingy[x]] = status;
        }
    } */
    ///vertical movement checking implemented here
    if(end_time < std::chrono::system_clock::now() || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !verticalCooldown)
    {
        /// please rewrite using a for loop system
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
            /// what does this loop do?
            /// how does it work?
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
        }
        end_time = std::chrono::system_clock::now() + std::chrono::milliseconds(250);
    }
    else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        verticalCooldown = false;
}
/// function needs a little explanation
/// why are we returning a boolean?
void tetrisGameManager::checkLines()
{

    int blocks = 0; /// number of blocks in a line that arent empty
    bool lines[blockGridSize_Y]; /// represent each line
    int times = 0;
    /// make sure that all of the lines are false
    /// please avoid using numeric constants
    for(int y = 0; y < blockGridSize_Y; y++)
        lines[y] = false;
    for(int y = 0; y < blockGridSize_Y; y++)
    {
        for(int x = 0; x < blockGridSize_X; x++)
        {
            if(blockGrid[x][y] != Empty)
                blocks++;
        }
        if(blocks == blockGridSize_X) /// all blocks are filled
            lines[y] = true;
        blocks = 0;
    }
    for(int y = (blockGridSize_Y - 1); y  > 0; y--)
    {
        if(lines[y])
            times++;
        /// shift blocks down to their new correct positon
        for(int x = 0; x < blockGridSize_X; x++)
            blockGrid[x][y] = blockGrid[x][y - times];
    }
}
bool  tetrisGameManager::checkLoseCondition()
{
        if(blockGrid[4][0] != Empty || blockGrid[5][0] != Empty ||
            blockGrid[6][0] != Empty || blockGrid[7][0] != Empty)
        return false;
    return true;
}

void tetrisGameManager::drawGrid(sf::RenderWindow& window)
{
    const int blockSize = screenHeight/blockGridSize_Y;
    sf::RectangleShape block(sf::Vector2f(blockSize, blockSize));
    block.setOutlineThickness(5);
    for(int x = 0; x < blockGridSize_X; x++)
    {
        for(int y = 0; y < blockGridSize_Y; y++)
        {
            /// i have no idea how you get this calculation
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

    this->moveBlock(currentBlock);
    this->checkLines();
    if(checkLoseCondition())
        this->gameOver = true;
    this->drawGrid(window);
}
