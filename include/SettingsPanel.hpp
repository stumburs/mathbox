#pragma once

class SettingsPanel
{
public:
    SettingsPanel();
    void render();
    void toggle_open();

public:
    bool open = false;

private:
    int min_render_width = 1280 / 4;
};