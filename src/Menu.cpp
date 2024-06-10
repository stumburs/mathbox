#include "Menu.hpp"
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include <iostream>

Menu::Menu(ToyHandler &toy_handler) : toy_handler(toy_handler)
{
    std::cout << "Created menu!" << std::endl;
}

void Menu::render()
{
    ClearBackground({40, 44, 52, 255});

    if (GuiLabelButton({100, 100, 200, 50}, "Voronoi"))
    {
        toy_handler.active_toy = ToyHandler::ToyType::VORONOI;
        std::cout << "Voronoi selected!" << std::endl;
    }
}
