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
        void drawGrid(sf::RenderWindow& window);
 private:
	int blockGrid[10][24];
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
