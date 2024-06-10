#pragma once
#include <map>
#include <memory>
#include <Toy.hpp>

class ToyHandler
{
public:
    ToyHandler();
    void update_toy();
    void render_toy();

public:
    enum class ToyType
    {
        VORONOI,
        NONE
    };

    ToyType active_toy;

    std::map<ToyType, std::unique_ptr<Toy>> toys;
};