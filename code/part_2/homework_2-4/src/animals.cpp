#include "animals.hpp"

#include <iostream>

auto Animal::get_num_of_feet() -> uint8_t
{
    return num_of_feet_;
}

Animal::~Animal()
{
    die();
}

auto Animal::get_position() -> double
{
    return position_;
}

void Animal::die()
{
    std::cout << "Aaaarghhhhh" << std::endl;
}

Spider::Spider(const double par_speed)
{
    num_of_feet_ = 8;
    speed_ = par_speed;
}

void Spider::move(const double time)
{
    std::cout << "cawl, crawl, crawl" << std::endl;
    position_ += (speed_ * time);
}

Mammal::Mammal(const uint8_t par_num_of_feet, const double par_speed)
{
    num_of_feet_ = par_num_of_feet;
    speed_ = par_speed;
}

void Mammal::move(const double time)
{
    std::cout << "walking, jumping, running" << std::endl;
    position_ += (speed_ * time);
}
