#pragma once
#include <vector>
#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

class Game
{
    private:
        std::vector<Block> blocks;  
        int score;      
        Block currentBlock;
        Block nextBlock;
        void RotateBlock();
        bool IsBlockOutside();
        void LockBlock();
        bool BlockFits();
        void Reset();
        
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