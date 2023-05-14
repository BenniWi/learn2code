#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <cstdint>

class Animal
{
   protected:
    uint8_t num_of_feet_ = 0;
    double speed_;
    double position_ = 0;

   public:
    auto get_num_of_feet() -> uint8_t;
    virtual void move(double) = 0;
    static void die();
    virtual ~Animal();
    auto get_position() -> double;
};

class Spider : public Animal
{
   public:
    explicit Spider(double);
    void move(double time) override;
};

class Mammal : public Animal
{
   public:
    Mammal(uint8_t, double);
    void move(double time) override;
};

#endif /* ANIMALS_HPP */
