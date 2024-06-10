#include "ToyHandler.hpp"
#include <iostream>

ToyHandler::ToyHandler()
{
    active_toy = ToyType::NONE;

    toys.emplace(ToyType::VORONOI, Voronoi());
}

void ToyHandler::update_toy()
{
    toys.at(active_toy).update();
    return;
}

void ToyHandler::render_toy()
{
    toys.at(active_toy).render();
    return;
}
