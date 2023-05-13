#include <iostream>

// One function works for all data types. This would work
// even for user defined types if operator '>' is overloaded
template <typename T>
auto my_max(T par_x, T par_y) -> T
{
    return (par_x > par_y) ? par_x : par_y;
}

auto main() -> int
{
    // Call myMax for int
    std::cout << my_max<int>(3, 7) << std::endl;
    // call myMax for double
    std::cout << my_max<double>(3.0, 7.0) << std::endl;
    // call myMax for char
    std::cout << my_max<char>('g', 'e') << std::endl;

    return 0;
}