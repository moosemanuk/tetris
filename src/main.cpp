#include <raylib.h>
#include <iostream>
#include "constants.h"
#include "grid.h"
#include "blocks.cpp"

using namespace constants;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "tetris");
    SetTargetFPS(60);

    Grid grid = Grid();

    grid.Initialise();
    grid.PrintToConsole();

    LBlock Lblock = LBlock();
    ZBlock Zblock = ZBlock();
    OBlock Oblock = OBlock();
    JBlock Jblock = JBlock();

    

    while (!WindowShouldClose())
    {
        BeginDrawing();        
        ClearBackground(DARKBLUE);
        grid.Draw();
        Jblock.Draw();
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}