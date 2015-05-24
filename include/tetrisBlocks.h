#ifndef TETRISBLOCKS_H
#define TETRISBLOCKS_H


class tetrisBlocks
{
    public:
        tetrisBlocks();
        void rotate(void);
    protected:
    private:
        enum BlockType
        {
            linePiece,
            square,
            squiggly,
            reverse_squiggly,
            l_block,
            reverse_l_block
        };
        BlockType type;
};

#endif // TETRISBLOCKS_H
