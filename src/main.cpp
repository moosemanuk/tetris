#include <raylib.h>


int main()
{
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkGreen);
        ball.Update();
        ball.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}