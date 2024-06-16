#pragma once
#include <vector>
#include <map>
#include "position.h"

class Block{
    private:
        int cellSize;
        int rotationState;
    public:
        Block();
        int id;
        std::map<int, std::vector<Position>> cells;
};