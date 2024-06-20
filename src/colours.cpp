#include "colours.h"
#include <vector>

const Color black = {0,0,0,255};
const Color green = {47,230,23,255};
const Color red = {232,18,18,255};
const Color white = {255,255,255,255};
const Color yellow = {237,234,4,255};
const Color purple = {166,0,247,255};
const Color cyan = {21,204,209,255};
const Color blue = {13,64,216,255};
const Color midnightBlue = {25,25,112,255};

// tetrominoes are classified as I, J, L, O, S, T, Z

std::vector<Color> GetCellColours()
{
    return {black, red, white, purple, blue, green, yellow, cyan, midnightBlue};
}
