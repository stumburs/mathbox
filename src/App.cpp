#include "App.hpp"
#include <raylib.h>
#include "Voronoi.hpp"
#include "Menu.hpp"
#include "ToyHandler.hpp"
#include <iostream>

void App::run()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1280, 720, "mathbox");
    SetTargetFPS(60);

    ToyHandler toy_handler;
    Menu menu(toy_handler);

    while (!WindowShouldClose())
    {
        // Update
        // Return to main menu
        if (IsMouseButtonPressed(MOUSE_BUTTON_SIDE))
        {
            toy_handler.active_toy = ToyHandler::ToyType::NONE;
        }

        if (toy_handler.active_toy != ToyHandler::ToyType::NONE)
        {
            toy_handler.update_toy();
        }

        // Draw
        BeginDrawing();
        {
            ClearBackground(BLACK);
            if (toy_handler.active_toy != ToyHandler::ToyType::NONE)
            {
                toy_handler.render_toy();
            }
            else
            {
                menu.render();
            }
            // DrawFPS(20, 20);
        }
        EndDrawing();
    }
    CloseWindow();
}
