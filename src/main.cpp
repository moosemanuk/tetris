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

    game.Initialise(); 
    
    while (!WindowShouldClose())
    {
        game.HandleInput();               
        BeginDrawing();        
        ClearBackground(DARKBLUE);         
        game.Draw();       
        EndDrawing();
    }

    CloseWindow();
    return 0;
}