#include "Voronoi.hpp"
#include <iostream>

Voronoi::Voronoi()
{
    std::cout << "Created within\n";

    image = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
}

void Voronoi::update()
{
    std::cout << "updating within\n";

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        seeds.push_back(GetMousePosition());

        BeginTextureMode(image);
        {
            ClearBackground(BLACK);
            for (int y = 0; y < GetScreenHeight(); y++)
            {
                for (int x = 0; x < GetScreenWidth(); x++)
                {
                    int j = 0;
                    for (int i = 0; i < seeds.size(); i++)
                    {
                        if (sqr_dist(static_cast<int>(seeds[i].x), static_cast<int>(seeds[i].y), x, y) <
                            sqr_dist(static_cast<int>(seeds[j].x), static_cast<int>(seeds[j].y), x, y))
                        {
                            j = i;
                        }
                        int palette_index = j % palette.size();
                        DrawPixel(x, y, palette[palette_index]);
                    }
                }
            }
        }
        EndTextureMode();
    }
}

void Voronoi::render()
{
    std::cout << "Rendering within\n";
    DrawTexturePro(
        image.texture,
        {0, 0, static_cast<float>(image.texture.width), -static_cast<float>(image.texture.height)},
        {0, 0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight())},
        {0.0f, 0.0f},
        0.0f,
        WHITE);
}

int Voronoi::sqr_dist(int x1, int y1, int x2, int y2)
{
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx * dx + dy * dy;
}
