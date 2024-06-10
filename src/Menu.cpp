#include "Menu.hpp"
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include <iostream>

Menu::Menu(ToyHandler &toy_handler) : toy_handler(toy_handler)
{
    // Init Styles
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

    // Background
    GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, ColorToInt({76, 82, 99, 255}));
    GuiSetStyle(DEFAULT, BASE_COLOR_FOCUSED, ColorToInt({92, 99, 112, 255}));
    GuiSetStyle(DEFAULT, BASE_COLOR_PRESSED, ColorToInt({108, 116, 125, 255}));
    GuiSetStyle(DEFAULT, BACKGROUND_COLOR, ColorToInt({76, 82, 99, 255}));

    // Text
    GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, ColorToInt({171, 178, 191, 255}));
    GuiSetStyle(DEFAULT, TEXT_COLOR_FOCUSED, ColorToInt({229, 192, 123, 255}));
    GuiSetStyle(DEFAULT, TEXT_COLOR_PRESSED, ColorToInt({229, 192, 123, 255}));

    // Border
    GuiSetStyle(DEFAULT, BORDER_COLOR_NORMAL, ColorToInt({171, 178, 191, 255}));
    GuiSetStyle(DEFAULT, BORDER_COLOR_FOCUSED, ColorToInt({209, 154, 102, 255}));
    GuiSetStyle(DEFAULT, BORDER_COLOR_PRESSED, ColorToInt({209, 154, 102, 255}));
}

void Menu::render()
{
    ClearBackground({40, 44, 52, 255});

    if (GuiButton({100, 100, 200, 50}, "Voronoi"))
    {
        toy_handler.active_toy = ToyHandler::ToyType::VORONOI;
        std::cout << "Voronoi selected!" << std::endl;
    }
}
