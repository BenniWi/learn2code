#include <iostream>

#include "animals.hpp"

auto main() -> int
{
    Spider tarantula(2.0);
    Mammal groundhog(4, 10.0);

    for (int i = 0; i < 10; ++i)
    {
        tarantula.move(static_cast<double>(i));
        groundhog.move(static_cast<double>(i));
    }

    return 0;
}
