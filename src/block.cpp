#include "block.h"
#include "constants.h"

using namespace constants;

Block::Block()
{
    cellSize = GRID_CELL_SIZE;
    rotationState = 0;
    colours = GetCellColours();
}

void Block::Draw()
{
    std::vector<Position> tiles = GetCellPositions();
    for(Position item: tiles)
    {
        DrawRectangle(item.column*cellSize + 11, 
                      item.row*cellSize + 11, 
                      cellSize - 1, cellSize - 1, colours[id]);
    }
}

void Block::DrawNext(int xoffset = 0, int yoffset = 0)
{
    std::vector<Position> tiles = GetCellPositions();
    for(Position item: tiles)
    {
        DrawRectangle(xoffset + item.column*cellSize + 11, 
                      yoffset + item.row*cellSize + 11, 
                      cellSize - 1, cellSize - 1, colours[id]);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

void Block::Rotate()
{
    if(rotationState != 3)
    {
        rotationState++;
    }
    else
    {
        rotationState = 0;
    }
}

void Block::UndoRotation()
{
    if(rotationState !=0)
    {
        rotationState--;
    }
    else
    {
        rotationState = 3;
    }
}

std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for(Position item: tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
    
}
