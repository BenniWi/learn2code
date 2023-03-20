#include <cstdint>
#include <iostream>

// typedef struct {} MyCppStruct  -->  using
using MyCppStruct = struct
{
    int8_t a = 0;  // type from cstdint https://en.cppreference.com/w/cpp/types/integer
    float b = 0.0F;

    void print() const
    {
        std::cout << "a = " << a << "; b = " << b << std::endl;
    }
};

class MyCppClass
{
   public:  // C++ Access Specifiers
    int8_t a = 0;
    float b = 0.0F;

    void print() const
    {
        std::cout << "a = " << a << "; b = " << b << std::endl;
    }
};

auto main() -> int
{
    {
        MyCppStruct my_struct;

        std::cout << "Printing struct my_struct: " << std::endl;
        my_struct.print();
    }
    {
        MyCppClass my_class;

        std::cout << "Printing class my_class: " << std::endl;
        my_class.print();
    }
}
