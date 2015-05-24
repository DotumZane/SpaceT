#ifndef TETRISGAMEMANAGER_H
#define TETRISGAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <chrono>

enum BlockStatus
	{
        Empty,
        Cyan,
        Yellow,
        Orange,
        Blue,
        Green,
        Red,
        Purple
	};

class tetrisGameManager
{
private:
    BlockStatus currentBlock;
	int blockGrid[10][24];
	int movingx[4];
	int movingy[4];
	bool horizontalCooldown;
	bool verticalCooldown;
	std::chrono::time_point<std::chrono::system_clock> end_time;
    void moveBlock(BlockStatus status);
    void drawGrid(sf::RenderWindow& window);
    void checkLines();
 public:
    tetrisGameManager();
    void createBlock(BlockStatus status);
    void updateGrid(sf::RenderWindow& window);

};

#endif // TETRISGAMEMANAGER_H
