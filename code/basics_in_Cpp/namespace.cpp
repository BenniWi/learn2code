#include <iostream>
#include <cstdint>

namespace my_awesome_namespace
{
class awesome_class
{
   public:
    int8_t a = 0; // type from cstdint https://en.cppreference.com/w/cpp/types/integer
    float b = 0.0F;

    void print() const
    {
        std::cout << "a = " << a << "; b = " << b << std::endl;
    }
};
}  // namespace my_awesome_namespace

namespace my_awesome_namespace
{
namespace my_more_awesome_namespace
{
class more_awesome_class
{
   public:
    static void print_hello()
    {
        std::cout << "hello from a static class method in namespace" << std::endl;
    }
};
};  // namespace my_more_awesome_namespace
}  // namespace my_awesome_namespace

int main(void)
{
    my_awesome_namespace::awesome_class my_class;
    std::cout << "Printing class my_class from namespace: " << std::endl;
    my_class.print();

    my_awesome_namespace::my_more_awesome_namespace::more_awesome_class::print_hello();
}
