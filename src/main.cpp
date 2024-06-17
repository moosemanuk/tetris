#include <raylib.h>
#include <iostream>
#include "constants.h"
#include "game.h"

using namespace constants;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "tetris");
    SetTargetFPS(60);

    Game game = Game();
    game.grid.Initialise();
    //Grid grid = Grid();

    game.grid.Initialise();    
    
    while (!WindowShouldClose())
    {
        BeginDrawing();        
        ClearBackground(DARKBLUE);                
        game.Draw();       
        EndDrawing();
    }

    CloseWindow();
    return 0;
}