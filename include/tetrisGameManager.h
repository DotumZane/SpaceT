#ifndef TETRISGAMEMANAGER_H
#define TETRISGAMEMANAGER_H

#include <chrono>

namespace sf
{
    class RenderWindow;
}

class tetrisGameManager
{
 public:
        tetrisGameManager();
        void drawLogic(sf::RenderWindow& window);
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
