#include <cmath>
#include <iostream>
#include <type_traits>

// One function works for all data types. This would work
// even for user defined types if operator '>' is overloaded
template <typename T>
auto my_max(T par_x, T par_y) -> T
{
    return (par_x > par_y) ? par_x : par_y;
}

template <typename T>
auto approx_equal(const T &par_x, const T &par_y, const double eps) -> bool
{
    static_assert(std::is_arithmetic<T>::value, "makes only sense for numbers");
    bool res = std::abs(static_cast<double>(par_x) - static_cast<double>(par_y)) < eps;
    return res;
}

auto main() -> int
{
    // Call myMax for int
    std::cout << my_max<int>(3, 7) << std::endl;
    // call myMax for double
    std::cout << my_max<double>(3.0, 7.0) << std::endl;
    // call myMax for char
    std::cout << my_max<char>('g', 'e') << std::endl;

    std::cout << "test 1: " << approx_equal<double>(3.0, 2.8, 0.1) << std::endl;
    std::cout << "test 1: " << approx_equal<double>(2.8, 3.0, 0.1) << std::endl;
    std::cout << "test 2: " << approx_equal<double>(3.0, 2.95, 0.1) << std::endl;
    std::cout << "test 2: " << approx_equal<double>(2.95, 3.0, 0.1) << std::endl;
    std::cout << "test 3: " << approx_equal<int>(3, 3, 0.1) << std::endl;
    std::cout << "test 4: " << approx_equal<int>(3, 2, 0.1) << std::endl;
    // following fails because of static assert
    // std::cout<<"test 5: "<<approx_equal<std::string>("g", "a", 0.1)<<std::endl;

    return 0;
}