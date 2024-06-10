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

    // Toy selection window
    panel_content.width = static_cast<float>(GetScreenWidth()) - GuiGetStyle(LISTVIEW, SCROLLBAR_WIDTH) - 2;
    scroll_panel = {0.0f, 0.0f, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight())};

    GuiScrollPanel(scroll_panel, nullptr, panel_content, &view_scroll, &panel_view);

    // Scissored area within scrollpanel
    BeginScissorMode(panel_view.x, panel_view.y, panel_view.width, panel_view.height);
    {
        int dx = 0;
        int dy = 0;
        for (const auto &[toy_type, toy] : toy_handler.toys)
        {
            if (GuiButton({static_cast<float>(100 + dx), view_scroll.y + 100 + dy, 200, 50}, toy->get_name().c_str()))
            {
                toy_handler.active_toy = toy_type;
                std::cout << toy->get_name() << " selected!" << std::endl;
            }
            dx += 220;
            dy += 0;
        }
    }
    EndScissorMode();
}
