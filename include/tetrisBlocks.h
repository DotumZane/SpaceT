#ifndef TETRISBLOCKS_H
#define TETRISBLOCKS_H


class tetrisBlocks
{
    public:
        tetrisBlocks();
        BlockType Gettype() { return type; }
        void Settype(BlockType val) { type = val; }
    protected:
    private:
        BlockType type;
};

#endif // TETRISBLOCKS_H
