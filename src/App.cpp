#include "App.hpp"
#include <raylib.h>
#include "Voronoi.hpp"

void App::run()
{
    Voronoi voronoi;

    InitWindow(1280, 720, "mathbox");
    SetTargetFPS(60);

    voronoi.init();

    while (!WindowShouldClose())
    {
        // Update
        voronoi.update();

        // Draw
        BeginDrawing();
        {
            ClearBackground(BLACK);
            voronoi.render();
            DrawFPS(20, 20);
        }
        EndDrawing();
    }
    CloseWindow();
}
