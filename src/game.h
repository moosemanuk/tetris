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
        void RotateBlock();
        bool IsBlockOutside();
        void LockBlock();
        bool BlockFits();
        
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
        bool GameOver;
        Grid grid;
};