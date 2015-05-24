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
        void drawLogic(sf::RenderWindow& app);
 private:
	int blockGrid[10][24];
	enum BlockColor
	{
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
