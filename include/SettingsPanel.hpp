#pragma once
#include <variant>
#include <raylib.h>
#include <string>
#include <map>

class SettingsPanel
{
private:
    using SettingValue = std::variant<int, float, bool, Color, std::string>;

public:
    SettingsPanel();
    void render();
    void toggle_open();
    void add_setting(const std::string &name, SettingValue value);
    SettingValue get_setting(const std::string &name);
    bool hovering_over_panel();
    bool open_and_hovering();

public:
    // GUI
    Rectangle settings_panel_bounds;
    bool open = false;

private:
    // Settings
    std::map<std::string, SettingValue> settings;

    // GUI
    int min_render_width = 1280 / 4;
};