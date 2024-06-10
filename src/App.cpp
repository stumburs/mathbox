#include "App.hpp"
#include <raylib.h>
#include "Voronoi.hpp"
#include "Menu.hpp"
#include "ToyHandler.hpp"

void App::run()
{
    InitWindow(1280, 720, "mathbox");
    SetTargetFPS(60);

    Menu menu(toy_handler);

    while (!WindowShouldClose())
    {
        // Update
        // if (toy_handler.active_toy != ToyHandler::ToyType::NONE)
        // {
        //     toy_handler.update_toy();
        // }

        // Draw
        BeginDrawing();
        {
            ClearBackground(BLACK);
            // if (toy_handler.active_toy != ToyHandler::ToyType::NONE)
            // {
            //     toy_handler.render_toy();
            // }
            // else
            // {
            //     menu.render();
            // }
            DrawFPS(20, 20);
        }
        EndDrawing();
    }
    CloseWindow();
}
