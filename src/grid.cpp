#include <iostream>
#include "grid.h"

Grid::Grid()
{
    colours = GetCellColours();
}


std::vector<Color> Grid::GetCellColours()
{
    Color darkGrey = {26,31,40,255};
    Color green = {47,230,23,255};
    Color red = {232,18,18,255};
    Color orange = {226,116,17,255};
    Color yellow = {237,234,4,255};
    Color purple = {166,0,247,255};
    Color cyan = {21,204,209,255};
    Color blue = {13,64,216,255};

    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
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
