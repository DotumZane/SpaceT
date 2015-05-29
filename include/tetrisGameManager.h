#ifndef TETRISGAMEMANAGER_H
#define TETRISGAMEMANAGER_H
#include <chrono>
namespace sf
{
    class RenderWindow;
}

/**
 this classes handless
 everything to deal with tetris game side
 currently being worked on.
*/
class tetrisGameManager
{
public:
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
    tetrisGameManager();
    void createBlock(BlockColors status);
    void updateGrid(sf::RenderWindow& window);
private:
    const static int blockGridSize_Y = 24;
    const static int blockGridSize_X = 10;

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
    int movingx[4]; /// need to use more flexible system.
    int movingy[4]; /// for loops are to be used to access the arrays
    bool gameOver; /// needs to a way to signal game over conditon met
    bool horizontalCooldown;
    bool verticalCooldown;
    std::chrono::time_point<std::chrono::system_clock> end_time;
    bool moveBlock(BlockColors status);
    void drawGrid(sf::RenderWindow& window);
    bool checkLines();


};

#endif // TETRISGAMEMANAGER_H
