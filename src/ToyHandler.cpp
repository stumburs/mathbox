#include "ToyHandler.hpp"
#include "Voronoi.hpp"
#include <iostream>

ToyHandler::ToyHandler()
{
    active_toy = ToyType::NONE;

    toys.emplace(ToyType::VORONOI, Voronoi());
}

void ToyHandler::update_toy()
{
    if (toys.find(active_toy) != toys.end())
    {
        toys[active_toy].update();
    }
}

void ToyHandler::render_toy()
{
    if (toys.find(active_toy) != toys.end())
    {
        toys[active_toy].render();
    }
}