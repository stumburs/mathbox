#include "Toy.hpp"
#include <stdexcept>

void Toy::update() { throw std::runtime_error("Toy::update() should not be called directly."); }

void Toy::render() { throw std::runtime_error("Toy::render() should not be called directly."); }
