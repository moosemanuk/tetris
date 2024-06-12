#pragma once
#include <vector>
#include <raylib.h>

class Grid{
    private:
        int numberOfRows = 10;
        int numberOfColumns = 20;
        int cellSize = 25;
        std::vector<Color> colours;
        std::vector<Color> GetCellColours(); 
    public:
        Grid(int rows, int columns, int cellsize);
        int grid[10][20];
        void Initialise();
        void PrintToConsole();
        void Draw();       

};