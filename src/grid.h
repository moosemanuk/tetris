#pragma once
#include <vector>
#include <raylib.h>

class Grid{
    private:
        int numberOfRows = 24;
        int numberOfColumns = 12;
        int cellSize = 25;
        std::vector<Color> colours;
        std::vector<Color> GetCellColours(); 
    public:
        Grid();
        int grid[24][12];
        void Initialise();
        void PrintToConsole();
        void Draw();       

};