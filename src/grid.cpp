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
            DrawRectangle(col*cellSize+1,row*cellSize+1,cellSize-1,cellSize-1,colours[cellValue]);
            //DrawRectangle(col*cellSize,row*cellSize,cellSize,cellSize,colours[cellValue]); REMOVE GRID LINES
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
