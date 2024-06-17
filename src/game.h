#pragma once
#include <vector>
#include "grid.h"
#include "blocks.cpp"

class Game
{
    private:
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;

    public:
        Game();
        Block GetRandomBlock();
        void Draw();
        std::vector<Block> getAllBlocks();
        Grid grid;
};