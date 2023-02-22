#include <cstdint>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/*
Example for function / method overloading -> compile time polymorphism
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
Example for operator overloading -> compile time polymorphism
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

/*
Example for function overriding -> runtime polymorphism
*/
class Animal
{
   public:
    void function()
    {
        cout << "Eating..." << endl;
    }
};
class Man : public Animal
{
   public:
    void function()
    {
        cout << "Walking ..." << endl;
    }
};

/*
Example for virtual function -> runtime polymorphism
*/
class Add
{
    int x = 5, y = 20;

   public:
    void display()  // overridden function
    {
        cout << "Add value of x is : " << x + y << endl;
    }
};
class Substract : public Add
{
    int y = 10, z = 30;

   public:
    void display()  // overridden function
    {
        cout << "Substract value of y is : " << y - z << endl;
    }
};

auto main() -> int
{
    // Example for function / method overloading
    cout << "Function Overloading:" << endl;
    cout << +Addition::ADD(3, 9) << endl;             // first method is called
    cout << Addition::ADD("Hallo", " Welt") << endl;  // second method is called

    // Example for operator overloading
    cout << "Operator Overloading:" << endl;
    A a1("Welcome");
    A a2(" Back");
    a1 + a2;

    // Example for function overriding
    cout << "Funciton Overriding:" << endl;
    Animal animal = Animal();
    animal.function();  // parent class object
    Man man = Man();
    man.function();  // child class object

    // Example for virtual function
    // TODO: nicht fertig
    Add *add;     // base class pointer .it can only access the base class members
    Substract s;  // making object of derived class
    s.display();
    add = &s;
    add->display();  // Accessing the function by using base class  pointer

    return 0;
}