#include <cstdint>
#include <iostream>
#include <string>

class Animal
{
   public:
    virtual void make_noise() const = 0;
};

class Bird;

class Cat : public Animal
{
   public:
    void make_noise() const override
    {
        std::cout << "miau" << std::endl;
    }

    void operator+(const Cat &par_cat)
    {
        std::cout << "Cats like each other!" << std::endl;
    }

    void operator+(const Bird &par_bird)
    {
        std::cout << "Cat and Bird does not work!" << std::endl;
    }
};

class Bird : public Animal
{
   public:
    void make_noise() const override
    {
        std::cout << "tschirp" << std::endl;
    }
};

auto main() -> int
{
    Cat sylvester;
    sylvester.make_noise();
    Bird tweetie;
    tweetie.make_noise();

    Cat minka;
    sylvester + minka;
    sylvester + tweetie;


    return 0;
}