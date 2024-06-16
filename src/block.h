#pragma once
#include <vector>
#include <map>
#include <raylib.h>
#include "position.h"
#include "colours.h"

class Block{
    private:
        int cellSize;
        int rotationState;
        std::vector<Color> colours;
    public:
        Block();
        void Draw();
        int id;
        std::map<int, std::vector<Position>> cells;

};