#include <raylib.h>
#include <iostream>
#include "constants.h"
#include "grid.h"

using namespace constants;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "tetris");
    SetTargetFPS(60);

    Grid grid(10, 20, 25);

    grid.Initialise();
    grid.PrintToConsole();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKBLUE);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}