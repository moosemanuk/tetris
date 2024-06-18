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
    for(Position item: tiles){
        Rectangle rec;
        rec.x = item.column*cellSize + 1;
        rec.y = item.row*cellSize + 1;
        rec.width = cellSize - 1;
        rec.height = cellSize - 1;
        DrawRectangleRounded(rec, 0.3f, 5, colours[id]);
        //DrawRectangle(item.column*cellSize + 1, item.row*cellSize + 1, cellSize - 1, cellSize - 1, colours[id]);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

void Block::Rotate()
{
    if(rotationState != 3){
        rotationState++;
    }
    else{
        rotationState = 0;
    }
}

void Block::UndoRotation()
{
    if(rotationState !=0){
        rotationState--;
    }
    else{
        rotationState = 3;
    }
}

std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for(Position item: tiles){
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
    
}
