#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <cstdint>

class Animal
{
   protected:
    uint8_t num_of_feet_ = 0;

   public:
    auto get_num_of_feet() -> uint8_t;
};

class Spider : public Animal
{
   public:
    Spider();
};

class Mammal : public Animal
{
   public:
    explicit Mammal(uint8_t);
};

#endif /* ANIMALS_HPP */
