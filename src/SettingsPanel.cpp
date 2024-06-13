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

    int setting_idx = 0;
    for (auto &[name, value] : settings)
    {
        std::visit([this, &name, &value, &setting_idx](auto &&arg)
                   {
            using T = std::decay_t<decltype(arg)>;

            if constexpr (std::is_same_v<T, int>)
            {
                throw std::runtime_error("Settings for type: int not implemented");
            }
            else if constexpr (std::is_same_v<T, float>)
            {
                Rectangle draw_pos = slider_bounds;
                draw_pos.y += setting_spacing * setting_idx;
                draw_pos.width = settings_panel_bounds.width - draw_pos.x - 50;
                GuiSliderBar(
                    draw_pos,
                    TextFormat("%d", static_cast<int>(std::get<float>(setting_min_max.at(name).first))),
                    TextFormat("%d", static_cast<int>(std::get<float>(setting_min_max.at(name).second))),
                    std::get_if<float>(&value),
                    std::get<float>(setting_min_max.at(name).first),
                    std::get<float>(setting_min_max.at(name).second)
                );
                DrawText(TextFormat("%f", std::get<float>(value)), draw_pos.x + draw_pos.width / 2 - MeasureText(TextFormat("%f", std::get<float>(value)), 20) / 2, draw_pos.y + draw_pos.height / 2 - 10, 20, WHITE);
                setting_idx++;
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
                Rectangle draw_pos = check_box_bounds;
                draw_pos.y += setting_spacing * setting_idx;
                GuiCheckBox(draw_pos, name.c_str(), std::get_if<bool>(&value));
                setting_idx++;
            }
            else
            {
                throw std::runtime_error("Something went catastrophically wrong.");
            } }, value);
    }
}

void SettingsPanel::toggle_open()
{
    open = !open;
}

void SettingsPanel::add_setting(const std::string &name, SettingValue value)
{
    settings[name] = value;
}

void SettingsPanel::add_setting(const std::string &name, SettingValue value, SettingValue min, SettingValue max)
{
    add_setting(name, value);
    auto min_max = std::make_pair(min, max);
    setting_min_max[name] = min_max;
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
