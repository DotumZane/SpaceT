#ifndef TETRISGAMEMANAGER_H
#define TETRISGAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <chrono>

/*namespace sf
{
    class RenderWindow;
}*/

class tetrisGameManager
{
 public:
        tetrisGameManager();
        void moveBlock();
        void drawGrid(sf::RenderWindow& window);
 private:
	int blockGrid[10][24];
	int movingx[4];
	int movingy[4];
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
};

#endif // TETRISGAMEMANAGER_H
