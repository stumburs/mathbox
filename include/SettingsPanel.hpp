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
    int setting_height = 50;
    int setting_spacing = setting_height + setting_height / 2;

    // Check box
    Rectangle check_box_bounds = {.x = 20, .y = 20, .width = static_cast<float>(setting_height), .height = 50};
};