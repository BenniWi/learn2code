#include <iostream>

typedef struct
{
    int a = 0;
    float b = 0.0F;

    void print() const
    {
        std::cout << "a = " << a << "; b = " << b << std::endl;
    }
} my_cpp_struct;

class my_cpp_class
{
   public:
    int a = 0;
    float b = 0.0F;

    void print() const
    {
        std::cout << "a = " << a << "; b = " << b << std::endl;
    }
};

int main(void)
{
    {
        my_cpp_struct my_struct;

        std::cout << "Printing struct my_struct: " << std::endl;
        my_struct.print();
    }
    {
        my_cpp_class my_class;

        std::cout << "Printing class my_class: " << std::endl;
        my_class.print();
    }
}
