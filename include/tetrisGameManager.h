#ifndef TETRISGAMEMANAGER_H
#define TETRISGAMEMANAGER_H
#include <chrono>
#include <array>
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
*/
class tetrisGameManager
{
public:
    //group: public Constructors

    /*
        constructor: tetrisGamManager
            basic construction of game manager
    */
    tetrisGameManager();
    // group: public type

     /// recommend to use enum class for type safety purpose
    /// needs to include what shape creates from color
    /*
        Enum: BlockColors
            the block colors that exist
    */
    enum BlockColors
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
    /*
        Function: createRandomNormBlock
            create a random Normal shape on screen.

            when a shape needs to be created
            on the tetris game. call this function
            to create a random normal block on the
            screen.

        Warning:
            this function should only be called when
            the currentBlock has been destroyed.

    */
    void createRandomNormBlock(void);
    /*
        Function: createBlock(BlockColors)
            create a shape based on color.

        Parameters:
            status(1)
                status is the color of which the
                shape is based on;

        See Also:
            <createRandomNormBlock>

    */
    void createBlock(BlockColors status);
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
    inline static sf::Vector2f getTetrisGameSize()
    {

        return sf::Vector2f((blockGridSize_X)* (screenHeight/blockGridSize_Y), screenHeight);
    }
private:
    const static int blockGridSize_Y = 24;
    const static int blockGridSize_X = 10;
    const static int sizeOfBiggestPiece = 4;
    //the thickness of the
    const static int borderThickness = 5;

    /// the following enum uses the url below as refernce
    /// http://mercurymasterpunk.ca/images/tetris.jpg
    enum class BlockShapes
    {
        I_shape,
        J_shape,
        L_shape,
        O_shape,
        Z_shape,
        T_shape,
        S_shape
        /// basic shapes
    };

    BlockColors currentBlock;

    int blockGrid[blockGridSize_X][blockGridSize_Y];
    /// movingx and movingy contain points on grid the system is
    /// cords(movingx[numBlock],movingy[numBlock]) == the cords for numBlock
    std::array<int,sizeOfBiggestPiece> movingx; /// need to use more flexible system.
    std::array<int,sizeOfBiggestPiece> movingy; /// for loops are to be used to access the arrays
    bool gameOver; /// needs to a way to signal game over conditon met
    bool horizontalCooldown;
    bool verticalCooldown;
    std::chrono::time_point<std::chrono::system_clock> end_time;
    void moveBlock(BlockColors status);
    void drawGrid(sf::RenderWindow& window);
    void checkLines();
    bool checkLoseCondition();


};

#endif // TETRISGAMEMANAGER_H
