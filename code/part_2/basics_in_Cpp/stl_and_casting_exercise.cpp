#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

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
    std::vector<std::shared_ptr<Animal>> animals;

    // if you don't want to use "rand", you can use the distribution functions
    std::random_device seed;   // a seed source for the random number engine
    std::mt19937 gen(seed());  // mersenne_twister_engine seeded with seed()
    std::uniform_int_distribution<> distribution(0, 1);

    for (int i = 0; i < 10; ++i)
    {
        // if(rand() > (RAND_MAX / 2))
        if (static_cast<bool>(distribution(gen)))
        {
            animals.push_back(std::make_shared<Cat>());
        }
        else
        {
            animals.push_back(std::make_shared<Bird>());
        }
    }

    for (auto &itr : animals)
    {
        itr->make_noise();
    }
    return 0;
}