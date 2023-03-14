#include <cstdint>
#include <iostream>

namespace my_awesome_namespace
{
class AwesomeClass
{
   public:
    int8_t a = 0;  // type from cstdint https://en.cppreference.com/w/cpp/types/integer
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
class MoreAwesomeClass
{
   public:
    static void print_hello()
    {
        std::cout << "hello from a static class method in namespace" << std::endl;
    }
};
};  // namespace my_more_awesome_namespace
}  // namespace my_awesome_namespace

auto main() -> int
{
    my_awesome_namespace::AwesomeClass my_class;
    std::cout << "Printing class my_class from namespace: " << std::endl;
    my_class.print();

    my_awesome_namespace::my_more_awesome_namespace::MoreAwesomeClass::print_hello();
}
