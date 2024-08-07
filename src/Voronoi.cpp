#include "Voronoi.hpp"
#include <iostream>
#include <raymath.h>

Voronoi::Voronoi()
{
    name = "Voronoi";
    image = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
    settings_panel.add_setting("Draw Points", true);
    settings_panel.add_setting("Pixel Size", 1.0f, 1.0f, 20.0f);
}

void Voronoi::update()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !settings_panel.open_and_hovering())
    {
        int draw_scale = static_cast<int>(std::get<float>(settings_panel.get_setting("Pixel Size")));
        seeds.push_back(GetMousePosition());

        BeginTextureMode(image);
        {
            ClearBackground(BLACK);
            for (int y = 0; y < GetScreenHeight(); y += draw_scale)
            {
                for (int x = 0; x < GetScreenWidth(); x += draw_scale)
                {
                    int j = 0;
                    for (size_t i = 0; i < seeds.size(); i++)
                    {
                        if (sqr_dist(static_cast<int>(seeds[i].x), static_cast<int>(seeds[i].y), x, y) <
                            sqr_dist(static_cast<int>(seeds[j].x), static_cast<int>(seeds[j].y), x, y))
                        {
                            j = i;
                        }
                        int palette_index = j % palette.size();
                        if (draw_scale > 1)
                        {
                            DrawRectangle(x, y, draw_scale, draw_scale, palette[palette_index]);
                        }
                        else
                        {
                            DrawPixel(x, y, palette[palette_index]);
                        }
                    }
                }
            }

            if (std::get<bool>(settings_panel.get_setting("Draw Points")))
                for (const auto seed : seeds)
                    DrawCircle(static_cast<int>(seed.x), static_cast<int>(seed.y), 4, BLACK);
        }
        EndTextureMode();
    }

    if (IsKeyPressed(KEY_R))
    {
        UnloadRenderTexture(image);
        image = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
        seeds.clear();
    }

    if (IsKeyPressed(KEY_TAB))
        settings_panel.toggle_open();
}

void Voronoi::render()
{
    DrawTexturePro(
        image.texture,
        {0, 0, static_cast<float>(image.texture.width), -static_cast<float>(image.texture.height)},
        {0, 0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight())},
        {0.0f, 0.0f},
        0.0f,
        WHITE);

    if (settings_panel.open)
        settings_panel.render();
}

const std::string &Voronoi::get_name() const
{
    return name;
}

int Voronoi::sqr_dist(int x1, int y1, int x2, int y2)
{
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx * dx + dy * dy;
}
