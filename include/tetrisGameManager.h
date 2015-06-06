#ifndef TETRISGAMEMANAGER_H
#define TETRISGAMEMANAGER_H
#include <tetrisEnums.hpp>
#include <tetrisMovableShape.h>
#include "main.h"
#include <SFML/System/Vector2.hpp>
namespace sf
{
class RenderWindow;
}

/*
    Class: tetrisGameManager

        this classes handless
    everything to deal with tetris game side
    currently being worked on.

    cyclic refernces:
        tetrisMovable - current used as owner.

    Depends on:
        <tetrisMovable>

*/
class tetrisGameManager
{
    friend class tetrisMovableShape;
public:
    //group: public Constructors

    /*
        constructor: tetrisGamManager
            basic construction of game manager
    */
    tetrisGameManager();
    //group: public
    /*
        Function: updateGrid(sf::RenderWindow)
            update the tetris game

            this function needs to be called on every invocation
            of the event loop. every time called does some
            inner game

        Paramters:
            window(1) the window the manager will draw on
    */
    void updateGrid(sf::RenderWindow& window);

    //group: public static
    /*
        Function: getTetrisGameSize
            get the size of gameboard.

        this function estimates what the default size of
        the tetrisGameBoard size should be.

        Note:
            the numbers created by this function
            originate in ints and transform to floats.

        Return:
            size(sf::Vector2f)
            the size of gameboard in float numbers

    */
    inline static const sf::Vector2f getTetrisGameSize()
    {

        return sf::Vector2f((blockGridSize_X)* (screenHeight/blockGridSize_Y), screenHeight);
    }
private:
    const static int blockGridSize_Y = 24;
    const static int blockGridSize_X = 10;
    //the thickness of the
    const static int borderThickness = 5;


    int blockGrid[blockGridSize_X][blockGridSize_Y];
    bool gameOver; /// needs to a way to signal game over conditon met
    tetrisMovableShape playingShape;
    void drawGrid(sf::RenderWindow& window);
    void checkLines();
    bool checkLoseCondition();


};

#endif // TETRISGAMEMANAGER_H
