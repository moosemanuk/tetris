#pragma once
#include <vector>
#include <raylib.h>
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
        void Initialise();
        Block GetRandomBlock();
        void Draw();
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        std::vector<Block> getAllBlocks();
        Grid grid;
};