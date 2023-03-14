#include <cstdio>
#include <iostream>
#include <memory>

// smart-pointers: https://en.cppreference.com/book/intro/smart_pointers
auto main() -> int
{
    int noe = 0;

    // Get the number of elements for the array
    std::cout << "Enter number of elements:";
    scanf("%d", &noe);
    std::cout << "Entered number of elements: " << noe << std::endl;

    // Dynamically allocate memory using smart pointers
    std::unique_ptr<int> ptr(new int[noe]);  // "new" syntax

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == nullptr)
    {
        std::cout << "Memory not allocated." << std::endl;
        exit(0);
    }
    else
    {
        // Memory has been successfully allocated
        std::cout << "Memory successfully allocated." << std::endl;

        // Get the elements of the array
        for (int i = 0; i < noe; ++i)
        {
            ptr.get()[i] = i + 1;
        }

        // Print the elements of the array
        std::cout << "The elements of the array are: ";
        for (int i = 0; i < noe; ++i)
        {
            std::cout << ptr.get()[i] << ",";
        }
        std::cout << std::endl;
    }

    // ATTENTION: no free-ing of memory necessary

    // BAD EXAMPLE from bevor has no leak any more
    for (int i = 0; i < noe; i++)
    {
        auto ptr2 = std::make_unique<int[]>(0);  // "make" syntax
    }

    return 0;
}
