#pragma once
#include <memory>
#include "ToyHandler.hpp"

class Menu
{
public:
    Menu(ToyHandler &toy_handler);
    void render();

private:
    ToyHandler &toy_handler;
};