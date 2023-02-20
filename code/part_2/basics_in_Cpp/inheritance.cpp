#include <cstdint>
#include <iostream>

// Base class
class Shape
{
   public:  // C++ Access Specifiers
    void setWidth(int8_t w)
    {
        width = w;
    }
    void setHeight(int8_t h)
    {
        height = h;
    }

   protected:  // C++ Access Specifiers
    int8_t width;
    int8_t height;
};

// Derived class
class Rectangle : public Shape
{
   public:
    int16_t getArea()
    {
        return (width * height);
    }
};

int main(void)
{
    Rectangle Rect;

    Rect.setWidth(5);
    Rect.setHeight(7);

    // Print the area of the object.
    std::cout << "Total area: " << Rect.getArea() << std::endl;

    return 0;
}