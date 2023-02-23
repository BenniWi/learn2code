#include <iostream>

// Base class Shape
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

// Base class PaintCost
class PaintCost
{
   public:
    auto get_cost(int16_t area) -> int32_t
    {
        return area * 70;
    }
};

// Derived class
class Rectangle : public Shape, public PaintCost
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

    int16_t area = rect.get_area();

    // Print the area of the object.
    std::cout << "Total area: " << rect.get_area() << std::endl;

    // Print the total cost of painting
    std::cout << "Total paint cost: $" << rect.get_cost(area) << std::endl;

    return 0;
}