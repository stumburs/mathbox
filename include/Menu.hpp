#pragma once
#include <memory>
#include "ToyHandler.hpp"
#include <raylib.h>

class Menu
{
public:
    Menu(ToyHandler &toy_handler);
    void render();

private:
    ToyHandler &toy_handler;

    // GUI
    Vector2 view_scroll = {0.0f, 0.0f};
    Rectangle panel_view = {0};
    Rectangle panel_content = {0.0f, 0.0f, 1280.0f, 1200.0f};
    Rectangle scroll_panel;
};