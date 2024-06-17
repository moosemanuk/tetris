#include "game.h"
#include "grid.h"
#include <random>

Game::Game()
{
    grid = Grid();
    blocks = getAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

void Game::Initialise()
{
    grid.Initialise();
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

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    switch(keyPressed){
        case KEY_LEFT: 
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            break;
        case KEY_UP:
            RotateBlock();
            break;
    }
}

void Game::MoveBlockLeft()
{
    currentBlock.Move(0, -1);
    if(IsBlockOutside()){
        currentBlock.Move(0, 1);
    }
}

void Game::MoveBlockRight()
{
    currentBlock.Move(0, 1);
    if(IsBlockOutside()){
        currentBlock.Move(0, -1);
    }
}

void Game::MoveBlockDown()
{
    currentBlock.Move(1, 0);
    if(IsBlockOutside()){
        currentBlock.Move(-1, 0);
    }
}

void Game::RotateBlock()
{
    currentBlock.Rotate();

}

bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles){
        if (grid.IsCellOutside(item.row, item.column)){
            return true;
        }
    }
    return false;
}

std::vector<Block> Game::getAllBlocks()
{
    return {IBlock(), JBlock(), SBlock(), LBlock(), OBlock(), ZBlock(), TBlock()};
}