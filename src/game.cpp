#include "game.h"
#include <random>

Game::Game()
{
    grid = Grid();
    blocks = getAllBlocks();
}

Block Game::GetRandomBlock()
{
    if(blocks.empty()){
        blocks = getAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::getAllBlocks()
{
    return {IBlock(), JBlock(), SBlock(), LBlock(), OBlock(), ZBlock(), TBlock()};
}