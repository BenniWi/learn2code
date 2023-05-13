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

    void operator+(const Cat &)
    {
        std::cout << "Cats like each other!" << std::endl;
    }

    void operator+(const Bird &)
    {
        std::cerr << "Cat and Bird don't like each other!" << std::endl;
    }
};

class Bird : public Animal
{
   public:
    void make_noise() const override
    {
        std::cout << "tschirp" << std::endl;
    }

    void operator+(const Cat &)
    {
        std::cerr << "Bird and Cat don't like each other!" << std::endl;
    }

    void operator+(const Bird &)
    {
        std::cout << "Birds like each other!" << std::endl;
    }
};

auto main() -> int
{
    Cat sylvester;
    sylvester.make_noise();
    Bird tweetie;
    tweetie.make_noise();

    Cat garfield;
    Bird woodstock;
    sylvester + garfield;
    sylvester + tweetie;
    tweetie + sylvester;
    tweetie + woodstock;

    return 0;
}