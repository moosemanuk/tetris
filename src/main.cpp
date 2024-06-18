#include <raylib.h>
#include <iostream>
#include "constants.h"
#include "game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

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
                 
        if(EventTriggered(0.3)){
            game.MoveBlockDown();
        }
        
        BeginDrawing();        
        ClearBackground(BLACK);
        game.Draw();       
        EndDrawing();
    }

    CloseWindow();
    return 0;
}