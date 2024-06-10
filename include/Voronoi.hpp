#pragma once
#include "Toy.hpp"
#include <vector>
#include <raylib.h>

class Voronoi : public Toy
{
public:
    Voronoi();
    void update() override;
    void render() override;
    const std::string &get_name() const override;

private:
    int sqr_dist(int x1, int y1, int x2, int y2);

private:
    std::vector<Vector2> seeds;

    Color bright_red = {251, 73, 52, 255};
    Color bright_green = {184, 187, 38, 255};
    Color bright_yellow = {250, 189, 47, 255};
    Color bright_blue = {131, 165, 152, 255};
    Color bright_purple = {211, 134, 155, 255};
    Color bright_aqua = {142, 192, 124, 255};
    Color bright_orange = {254, 128, 24, 255};

    std::vector<Color> palette = {
        bright_red,
        bright_green,
        bright_yellow,
        bright_blue,
        bright_purple,
        bright_aqua,
        bright_orange,
    };

    RenderTexture2D image;
};