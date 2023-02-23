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
    static auto add(int8_t num_x, int8_t num_y) -> int16_t
    {
        return num_x + num_y;  // this function is performing addition of  two Integer value
    }

    static auto add(const string &str1, const string &str2) -> string
    {
        return str1 + str2;  // this function concatenates two strings
    }
};

/*
Example for operator overloading -> compile time polymorphism
*/
class A
{
    string str_x_;

   public:
    A() = default;
    explicit A(const string &str_i)
    {
        str_x_ = str_i;
    }
    void operator+(const A &class_a)
    {
        string str_m = str_x_ + class_a.str_x_;
        cout << "The result of the addition of two objects is : " << str_m << endl;
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
    int x_ = 5, y_ = 20;

   public:
    void display()  // overridden function
    {
        cout << "Add value of x is : " << x_ + y_ << endl;
    }
};
class Substract : public Add
{
    int y_ = 10, z_ = 30;

   public:
    void display()  // overridden function
    {
        cout << "Substract value of y is : " << y_ - z_ << endl;
    }
};

auto main() -> int
{
    // Example for function / method overloading
    cout << "Function Overloading:" << endl;
    cout << +Addition::add(3, 9) << endl;             // first method is called
    cout << Addition::add("Hallo", " Welt") << endl;  // second method is called

    // Example for operator overloading
    cout << "Operator Overloading:" << endl;
    A ca1("Welcome");
    A ca2(" Back");
    ca1 + ca2;

    // Example for function overriding
    cout << "Funciton Overriding:" << endl;
    Animal animal = Animal();
    animal.function();  // parent class object
    Man man = Man();
    man.function();  // child class object

    // Example for virtual function
    // TODO: nicht fertig
    Add *add;       // base class pointer .it can only access the base class members
    Substract sub;  // making object of derived class
    sub.display();
    add = &sub;
    add->display();  // Accessing the function by using base class  pointer

    return 0;
}