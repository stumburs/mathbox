#pragma once
#include "ToyHandler.hpp"
#include <memory>

class App
{
public:
    void run();

private:
    ToyHandler toy_handler;
};