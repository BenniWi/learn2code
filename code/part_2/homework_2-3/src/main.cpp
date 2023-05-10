#include <iostream>

#include "animals.hpp"

auto main() -> int
{
    Spider tarantula;
    Mammal groundhog(4);

    std::cout << "a tarantula has: " << static_cast<unsigned>(tarantula.get_num_of_feet()) << " feet" << std::endl;
    std::cout << "a groundhog has: " << static_cast<unsigned>(groundhog.get_num_of_feet()) << " feet" << std::endl;

    return 0;
}
