#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

auto main() -> int
{
    // documentation for stl containers in general: https://en.cppreference.com/w/cpp/container
    {
        // std::array -> example from: https://en.cppreference.com/w/cpp/container/array
        std::cout << "--------  std::array  --------" << std::endl;
        // construction uses aggregate initialization
        std::array<int, 3> stl_array1{1, 3, 2};
        std::array<int, 3> stl_array2 = {1, 2, 3};  // double braces never required after =
        std::array<std::string, 2> stl_array3 = {std::string("a"), "b"};

        // container operations are supported
        std::sort(stl_array1.begin(), stl_array1.end());
        std::cout << "stl_array1 after sort: ";
        std::copy(stl_array1.begin(), stl_array1.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::cout << "stl_array2 reversed: ";
        std::reverse_copy(stl_array2.begin(), stl_array2.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        // ranged for loop is supported
        std::cout << "stl_array ranged for loop: ";
        for (const auto& itr : stl_array3)
        {
            std::cout << itr << ' ';
        }
        std::cout << std::endl;
    }

    {
        // std::vector -> example from: https://en.cppreference.com/w/cpp/container/vector
        std::cout << "--------  std::vector  --------" << std::endl;

        // Create a vector containing integers
        std::vector<int> stl_vector = {7, 5, 16, 8};

        // Add two more integers to vector
        stl_vector.push_back(25);
        stl_vector.push_back(13);

        // Print out the vector
        std::cout << "stl_vector = { ";
        for (const auto& itr : stl_vector)
        {
            std::cout << itr << ", ";
        }
        std::cout << "};" << std::endl;
    }
}