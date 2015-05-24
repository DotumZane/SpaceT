#ifndef TETRISGAMEMANAGER_H
#define TETRISGAMEMANAGER_Hs
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
    protected:
    private:

};

#endif // TETRISGAMEMANAGER_H
