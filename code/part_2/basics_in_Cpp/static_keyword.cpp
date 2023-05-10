#include <iostream>

class ClassWithStatics
{
   public:
    static int instance_counter_;
    ClassWithStatics()
    {
        ++instance_counter_;
        std::cout << "Instance count is: " << instance_counter_ << std::endl;
    }

    static void say_hello()
    {
        std::cout << "Hello World! from static method" << std::endl;
    }
};
int ClassWithStatics::instance_counter_ = 0;

void function_with_static()
{
    static int call_count_ = 0;
    ++call_count_;
    std::cout << "call_count in function: " << call_count_ << std::endl;
}

auto main() -> int
{
    std::cout << "----static class member test----" << std::endl;
    ClassWithStatics cws1;
    ClassWithStatics cws2;

    std::cout << "----static class method test----" << std::endl;
    ClassWithStatics::say_hello();
    cws1.say_hello();  // also possible, but unusual

    std::cout << "----static variable in function scope test----" << std::endl;
    function_with_static();
    function_with_static();

    std::cout << "----static variable test in block scope----" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        int non_static_var = 0;
        static int static_var_ = 0;
        ++non_static_var;
        ++static_var_;
        std::cout << "non_static_var: " << non_static_var << " static_var_: " << static_var_ << std::endl;
    }

    return 0;
}