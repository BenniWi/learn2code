#include <cstdio>
#include <iostream>
#include <memory>

// smart-pointers: https://en.cppreference.com/book/intro/smart_pointers
auto main() -> int
{
    // some examples for unique_ptr
    {
        // creating a unique_ptr
        std::unique_ptr<int> uni_ptr(new int);                                   // single value
        std::unique_ptr<int[]> array_uni_ptr(new int[5]);                        // array of size 5
        std::unique_ptr<int> make_uni_ptr = std::make_unique<int>();             // single value
        std::unique_ptr<int[]> make_array_uni_ptr = std::make_unique<int[]>(5);  // array of size 5
        // we can also use "auto" here
        auto auto_uni_ptr = std::make_unique<int>();
        // accessing an element of an array inside a unique_ptr
        array_uni_ptr.get()[0] = 5;
    }

    // some examples for shared_ptr
    {
        // creating a shared_ptr
        std::shared_ptr<int> shr_ptr(new int);                        // single value
        std::shared_ptr<int[]> array_shr_ptr(new int[5]);             // array of size 5
        std::shared_ptr<int> make_shr_ptr = std::make_shared<int>();  // single value
        // make_shared on arrays works only from C++20 on
        // std::shared_ptr<int[]> make_array_shr_ptr = std::make_shared<int[]>(5);  // array of size 5
        // we can also use "auto" here
        auto auto_shr_ptr = std::make_shared<int>();
        // accessing an element of an array inside a shared_ptr
        array_shr_ptr.get()[0] = 5;
    }

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

    // BAD EXAMPLE from befor has no leak any more
    for (int i = 0; i < noe; i++)
    {
        auto ptr2 = std::make_unique<int[]>(0);  // "make" syntax
    }

    return 0;
}
