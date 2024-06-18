#include <iostream>
#include "grid.h"
#include "colours.h"

Grid::Grid()
{
    colours = GetCellColours();
}

void Grid::Initialise()
{
    for(int row = 0; row < numberOfRows; row++){
        for(int col = 0; col < numberOfColumns; col++){
            grid[row][col] = 0; 
        }
    }
}

void Grid::PrintToConsole()
{
    for(int row = 0; row < numberOfRows; row++){
        for(int col = 0; col < numberOfColumns; col++){
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw()
{
    for(int row = 0; row < numberOfRows; row++){
        for(int col = 0; col < numberOfColumns; col++){
            int cellValue = grid[row][col];
            Rectangle rec;
            rec.x = col*cellSize + 1;
            rec.y = row*cellSize + 1;
            rec.width = cellSize - 1;
            rec.height = cellSize - 1;
            DrawRectangleRounded(rec, 0.3f, 5, colours[cellValue]);
            //DrawRectangle(col*cellSize+1,row*cellSize+1,cellSize-1,cellSize-1,colours[cellValue]);            
        }
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    if(row >= 0 && row < numberOfRows && column >= 0 && column < numberOfColumns){
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if(grid[row][column] == 0){
        return true;
    }
    return false;
}

bool Grid::CompletedRows()
{
    for(int row = 0; row < GRID_ROWS; row++){
        for(int col = 0; col < GRID_COLS; col++){
            if(grid[row][col] == 0){
                return false;
            }
        }
    }
    return true;
}
