#pragma once
#include <string>

class Toy
{
public:
    virtual void update() = 0;
    virtual void render() = 0;
    const virtual std::string &get_name() const = 0;

    std::string name;
};