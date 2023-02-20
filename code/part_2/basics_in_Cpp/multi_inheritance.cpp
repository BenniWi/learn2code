#include <iostream>

// Base class Shape
class Shape
{
   public:
    void setWidth(int8_t w)
    {
        width = w;
    }
    void setHeight(int8_t h)
    {
        height = h;
    }

   protected:
    int8_t width;
    int8_t height;
};

// Base class PaintCost
class PaintCost
{
   public:
    int32_t getCost(int16_t area)
    {
        return area * 70;
    }
};

// Derived class
class Rectangle : public Shape, public PaintCost
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
    int8_t area;

    Rect.setWidth(5);
    Rect.setHeight(7);

    area = Rect.getArea();

    // Print the area of the object.
    std::cout << "Total area: " << Rect.getArea() << std::endl;

    // Print the total cost of painting
    std::cout << "Total paint cost: $" << Rect.getCost(area) << std::endl;

    return 0;
}