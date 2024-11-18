#pragma once
#include <vector>
#include <map>
#include <raylib.h>
#include "position.h"
#include "colours.h"

class Block
{
    private:
        int cellSize;
        int rotationState;
        int rowOffset = 0;
        int columnOffset = 0;
        std::vector<Color> colours;
    public:
        Block();        
        void Draw();
        void DrawNext(int xoffset, int yoffset);
        void Move(int rows, int columns);
        void Rotate();
        void UndoRotation();
        std::vector<Position> GetCellPositions();
        int id;
        std::map<int, std::vector<Position>> cells;

};