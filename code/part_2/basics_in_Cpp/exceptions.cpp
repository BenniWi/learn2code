#include <exception>
#include <iostream>

// define a simple function to throw an exception
auto division(const int par_a, const int par_b) -> double
{
    if (par_b == 0)
    {
        throw std::invalid_argument("Division by zero!");
    }
    return (static_cast<double>(par_a) / static_cast<double>(par_b));
}

// define our own exception
struct MyException : public std::exception
{
    const char* what() const noexcept override
    {
        return "C++ Exception";
    }
};

auto main() -> int
{
    int var_x = 50;
    int var_y = 0;
    double var_z = 0.0;

    // test our function with division by zero
    try
    {
        // code we want to execute and catch errors
        var_z = division(var_x, var_y);
        std::cout << var_z << std::endl;
    }
    catch (std::invalid_argument& invalid_exception)
    {
        // in case of an "invalid_exception", we'll end up here
        std::cerr << invalid_exception.what() << std::endl;
    }
    catch (std::exception& e)
    {
        // Other errors
    }

    // Test our own exception type
    try
    {
        throw MyException();
    }
    catch (MyException& my_except)
    {
        std::cout << "MyException caught with: " << my_except.what() << std::endl;
    }

    // Test throwing an un-catched error
    // throw std::logic_error("Test aborting with exception");

    return 0;
}