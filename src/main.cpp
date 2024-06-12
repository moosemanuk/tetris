#include <raylib.h>
#include <iostream>
#include "constants.h"

using namespace constants;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "tetris");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGREEN);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}