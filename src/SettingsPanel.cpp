#include "SettingsPanel.hpp"
#include <raylib.h>
#include <stdexcept>
#include <raygui.h>

SettingsPanel::SettingsPanel()
{
    settings_panel_bounds = {
        .x = 0,
        .y = 0,
        .width = static_cast<float>(min_render_width),
        .height = static_cast<float>(GetScreenHeight())};
}

void SettingsPanel::render()
{
    int desired_render_width = GetScreenWidth() / 4;
    settings_panel_bounds.width = desired_render_width < min_render_width ? min_render_width : desired_render_width;
    settings_panel_bounds.height = GetScreenHeight();
    DrawRectangleRec(settings_panel_bounds, ColorAlpha(GRAY, 0.4));

    for (auto &[name, value] : settings)
    {
        std::visit([&name, &value](auto &&arg)
                   {
            using T = std::decay_t<decltype(arg)>;

            if constexpr (std::is_same_v<T, int>)
            {
                throw std::runtime_error("Settings for type: int not implemented");
            }
            else if constexpr (std::is_same_v<T, float>)
            {
                throw std::runtime_error("Settings for type: float not implemented");
            }
            else if constexpr (std::is_same_v<T, std::string>)
            {
                throw std::runtime_error("Settings for type: std::string not implemented");
            }
            else if constexpr (std::is_same_v<T, Color>)
            {
                throw std::runtime_error("Settings for type: Color not implemented");
            }
            else if constexpr (std::is_same_v<T, bool>)
            {
                GuiCheckBox({0, 0, 100, 100}, name.c_str(), std::get_if<bool>(&value));
            }
            else
            {
                throw std::runtime_error("Something went catastrophically wrong.");
            } }, value);
    }

    DrawText("Settings Panel", settings_panel_bounds.width / 2 - MeasureText("Settings Panel", 40) / 2, GetScreenHeight() / 2 - 20, 40, WHITE);
}

void SettingsPanel::toggle_open()
{
    open = !open;
}

void SettingsPanel::add_setting(const std::string &name, SettingValue value)
{
    settings[name] = value;
}

SettingsPanel::SettingValue SettingsPanel::get_setting(const std::string &name)
{
    auto it = settings.find(name);
    if (it != settings.end())
    {
        return it->second;
    }
    else
    {
        throw std::runtime_error("Setting \"" + name + "\" not found");
    }
}

bool SettingsPanel::hovering_over_panel()
{
    return CheckCollisionPointRec(GetMousePosition(), settings_panel_bounds);
}

bool SettingsPanel::open_and_hovering()
{
    return hovering_over_panel() && open;
}
