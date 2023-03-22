#include <iostream>

#include "functions.h"

auto main() -> int
{
    int val1 = 5;
    int val2 = 6;
    int ret_val = add_integers(val1, val2);

    std::cout << "Result of addition is: " << ret_val << std::endl;
    return 0;
}
