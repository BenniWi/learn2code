#include <cstdint>
#include <iostream>

auto main() -> int
{
    {
        std::cout << "implicit conversion" << std::endl;
        int8_t int_short = 127;
        int32_t int_long = int_short;  // implicit conversion
    }

    {
        std::cout << "explicit conversion" << std::endl;
        int8_t int_short = 127;
        int32_t int_long;
        int_long = (int32_t)int_short;  // c-like cast notation
        int_long = int32_t(int_short);  // functional notation
    }

    {
        std::cout << "dynamic_cast" << std::endl;
        class CBase
        {
        };
        class CDerived : public CBase
        {
        };

        CBase base;
        CBase* pbase;
        CDerived derived;
        CDerived* pderived;

        pbase = dynamic_cast<CBase*>(&derived);  // ok: derived-to-base
        // pderived = dynamic_cast<CDerived*>(&base);  // wrong: base-to-derived
    }

    {
        std::cout << "static_cast" << std::endl;
        double dpi = 3.14159265;
        int ipi = static_cast<int>(dpi);

        class CBase
        {
        };
        class CDerived : public CBase
        {
        };
        CBase* base = new CBase;
        auto derived = static_cast<CDerived*>(base);
    }
    return 0;
}