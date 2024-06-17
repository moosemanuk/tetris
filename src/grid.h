#pragma once
#include <vector>
#include <raylib.h>
#include "constants.h"

using namespace constants;

class Grid{
    private:
        int numberOfRows = GRID_ROWS;
        int numberOfColumns = GRID_COLS;
        int cellSize = GRID_CELL_SIZE;
        std::vector<Color> colours;        
    public:
        Grid();
        int grid[GRID_ROWS][GRID_COLS];
        void Initialise();
        void PrintToConsole();
        void Draw();  
        bool IsCellOutside(int row, int column);     

};