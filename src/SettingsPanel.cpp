#include "SettingsPanel.hpp"
#include <raylib.h>

SettingsPanel::SettingsPanel()
{
}

void SettingsPanel::render()
{
    int desired_render_width = GetScreenWidth() / 4;
    int render_width = desired_render_width < min_render_width ? min_render_width : desired_render_width;
    DrawRectangle(0, 0, render_width, GetScreenHeight(), ColorAlpha(RED, 0.2));
    DrawText("Settings Panel", render_width / 2 - MeasureText("Settings Panel", 40) / 2, GetScreenHeight() / 2 - 20, 40, WHITE);
}

void SettingsPanel::toggle_open()
{
    open = !open;
}
