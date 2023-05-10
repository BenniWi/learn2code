#include "animals.hpp"

auto Animal::get_num_of_feet() -> uint8_t
{
    return num_of_feet_;
}

Spider::Spider()
{
    num_of_feet_ = 8;
}

Mammal::Mammal(const uint8_t par_num_of_feet)
{
    num_of_feet_ = par_num_of_feet;
}
