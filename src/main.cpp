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

    IBlock block = IBlock();
    
    while (!WindowShouldClose())
    {
        BeginDrawing();        
        ClearBackground(DARKBLUE);        
        grid.Draw();

        if(IsKeyPressed(KEY_RIGHT)){
            block.Move(0,1);
        }
        if(IsKeyPressed(KEY_LEFT)){
            block.Move(0,-1);
        }       

        block.Draw();       
        EndDrawing();
    }

    CloseWindow();
    return 0;
}