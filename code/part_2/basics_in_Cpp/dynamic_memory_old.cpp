#include <cstdio>
#include <iostream>

// https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
auto main() -> int
{
    int noe = 0;

    // Get the number of elements for the array
    std::cout << "Enter number of elements:";
    std::cin >> noe;
    std::cout << "Entered number of elements: " << noe << std::endl;

    // Dynamically allocate memory using new()
    int* ptr = new int[noe];

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

        // Set the elements of the array
        for (int i = 0; i < noe; ++i)
        {
            ptr[i] = i + 1;
        }

        // Print the elements of the array
        std::cout << "The elements of the array are: ";
        for (int i = 0; i < noe; ++i)
        {
            std::cout << ptr[i] << ",";
        }
        std::cout << std::endl;
    }

    // ATTENTION: always FREE the memory, if you don't need it any more
    delete[] ptr;

    return 0;
}
