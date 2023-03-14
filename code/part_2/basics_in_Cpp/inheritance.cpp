#include <cstdint>
#include <iostream>

// Base class
class Shape
{
   public:  // C++ Access Specifiers
    void set_width(int8_t width_in)
    {
        width_ = width_in;
    }
    void set_height(int8_t height_in)
    {
        height_ = height_in;
    }

   protected:  // C++ Access Specifiers
    int8_t width_;
    int8_t height_;
};

// Derived class
class Rectangle : public Shape
{
   public:
    auto get_area() -> int16_t
    {
        return (width_ * height_);
    }
};

auto main() -> int
{
    Rectangle rect;

    rect.set_width(5);
    rect.set_height(7);

    // Print the area of the object.
    std::cout << "Total area: " << rect.get_area() << std::endl;

    return 0;
}