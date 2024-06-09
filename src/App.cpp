#include "App.h"
#include <raylib.h>

void App::Run()
{
    InitWindow(1280, 720, "mathbox");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update

        // Draw
        BeginDrawing();
        {
            ClearBackground(BLACK);
            DrawFPS(20, 20);
        }
        EndDrawing();
    }
    CloseWindow();
}
