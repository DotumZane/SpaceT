#ifndef TETRISMOVABLESHAPE_H
#define TETRISMOVABLESHAPE_H
#include <array>
#include <tetrisEnums.hpp>
#include <chrono>
class tetrisGameManager;
/*
    class: tetrisMovableShape
        the current active shape is reprensened by this
        class

    See Also:
        <tetrisGameManager>
*/
class tetrisMovableShape
{
public:
    tetrisMovableShape(tetrisGameManager&);
    void move();
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
    void createBlock(BlockColors);
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
protected:
private:
    const static int sizeOfBiggestPiece = 4;
    BlockColors currentBlock;
    bool horizontalCooldown;
    bool verticalCooldown;
    std::chrono::time_point<std::chrono::system_clock> end_time;
    tetrisGameManager& gameManager;
    /// movingx and movingy contain points on grid the system is
    /// cords(movingx[numBlock],movingy[numBlock]) == the cords for numBlock
    std::array<int,sizeOfBiggestPiece> movingx; /// need to use more flexible system.
    std::array<int,sizeOfBiggestPiece> movingy; /// for loops are to be used to access the arrays
};

#endif // TETRISMOVABLESHAPE_H
