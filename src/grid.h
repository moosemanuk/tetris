#pragma once
#include <vector>
#include <raylib.h>
#include "constants.h"

using namespace constants;

class Grid{
    private:
        bool IsRowFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int numRows);
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
        bool IsCellEmpty(int row, int column);  
        int ClearFullRows(); 

};