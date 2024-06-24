#include "game.h"
#include "grid.h"
#include <random>

Game::Game()
{
    grid = Grid();
    blocks = getAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    GameOver = false;
    score = 0;
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
    Rectangle scoreRec;
    Rectangle nextblockRec;

    scoreRec.x = 330;
    scoreRec.y = 70;
    scoreRec.width = 150;
    scoreRec.height = 40;

    nextblockRec.x = 330;
    nextblockRec.y = 140;
    nextblockRec.width = 150;
    nextblockRec.height = 75;

    DrawRectangleRounded(scoreRec, 0.1, 2, BLUE);
    DrawRectangleRounded(nextblockRec, 0.1, 2, BLUE);

    nextBlock.DrawNext(225,135);

    DrawText(TextFormat("Score: %03i", score), 350, 80, 20, WHITE);
    
    if(GameOver){
        DrawText("GAME OVER", 330, 500, 25, WHITE);
    }
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    if(GameOver && keyPressed != 0){
        GameOver = false;
        Reset();
    }
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
    if(!GameOver){
        currentBlock.Move(0, -1);
        if(IsBlockOutside() || BlockFits() == false){
            currentBlock.Move(0, 1);
        }
    }
}

void Game::MoveBlockRight()
{
    if(!GameOver){
        currentBlock.Move(0, 1);
        if(IsBlockOutside() || BlockFits() == false){
            currentBlock.Move(0, -1);
        }
    }
}

void Game::MoveBlockDown()
{
    if(!GameOver){
        currentBlock.Move(1, 0);
        if(IsBlockOutside() || BlockFits() == false){
            currentBlock.Move(-1, 0);
            LockBlock();       
        }
    }
}

void Game::RotateBlock()
{
    if(!GameOver){
        currentBlock.Rotate();
        if(IsBlockOutside() || BlockFits() == false){
            currentBlock.UndoRotation();
        }
    }
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

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles){
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if(BlockFits() == false){
        GameOver = true;
    }
    nextBlock = GetRandomBlock();
    score += grid.ClearFullRows();
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles){
        if(grid.IsCellEmpty(item.row, item.column) == false){
            return false;
        }
    }
    return true;

}

void Game::Reset()
{
    grid.Initialise();
    blocks = getAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();

}

std::vector<Block> Game::getAllBlocks()
{
    return {IBlock(), JBlock(), SBlock(), LBlock(), OBlock(), ZBlock(), TBlock()};
}