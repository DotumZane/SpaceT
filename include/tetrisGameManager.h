#ifndef TETRISGAMEMANAGER_H
#define TETRISGAMEMANAGER_H
#include <chrono>
#include <array>
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
    // group: public

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
private:
    const static int blockGridSize_Y = 24;
    const static int blockGridSize_X = 10;
    const static int sizeOfBiggestPiece = 4;

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
     /// recommend to use enum class for type safety purpose
    /// needs to include what shape creates from color
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
    BlockColors currentBlock;

    int blockGrid[blockGridSize_X][blockGridSize_Y];
    /// movingx and movingy contain points on grid the system is
    /// cords(movingx[numBlock],movingy[numBlock]) == the cords for numBlock
    std::array<int,4> movingx; /// need to use more flexible system.
    std::array<int,4> movingy; /// for loops are to be used to access the arrays
    bool gameOver; /// needs to a way to signal game over conditon met
    bool horizontalCooldown;
    bool verticalCooldown;
    std::chrono::time_point<std::chrono::system_clock> end_time;
    void moveBlock(BlockColors status);
    void createBlock(BlockColors status);

    void drawGrid(sf::RenderWindow& window);
    void checkLines();
    bool checkLoseCondition();


};

#endif // TETRISGAMEMANAGER_H
