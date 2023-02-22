#include <cstdint>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/*
Example for function / method overloading
*/
class Addition
{
   public:
    static auto ADD(int8_t x, int8_t y) -> int8_t
    {
        return x + y;  // this function is performing addition of  two Integer value
    }

    static auto ADD(const string &x, const string &y) -> string
    {
        return x + y;  // this function concatenates two strings
    }
};

/*
Example for operator overloading
*/
class A
{
    string x;

   public:
    A() = default;
    explicit A(const string &i)
    {
        x = i;
    }
    void operator+(const A &a)
    {
        string m = x + a.x;
        cout << "The result of the addition of two objects is : " << m << endl;
    }
};

auto main() -> int
{
    // Example for function / method overloading
    cout << "Function Overloading:" << endl;
    cout << Addition::ADD(3, 9) << endl;          // first method is called
    cout << Addition::ADD("Hallo", " Welt") << endl;  // first method is called

    // Example for operator overloading
    cout << "Operator Overloading:" << endl;
    A a1("Welcome");  
    A a2(" Back");  
    a1+a2;

    return 0;
}