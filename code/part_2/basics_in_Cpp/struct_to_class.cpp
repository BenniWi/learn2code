#include <cstdint>
#include <iostream>

// typedef struct {} MyCppStruct  -->  using
// normally you should not do it like this, prefere classes instead
using MyCppStruct = struct
{
    int16_t a = 0;  // type from cstdint https://en.cppreference.com/w/cpp/types/integer
    float b = 0.0F;

    void print() const
    {
        std::cout << "a = " << a << "; b = " << b << std::endl;
    }
};

// C++ class looks like this
class MyCppClass
{
   public:  // C++ Access Specifiers
    int16_t a = 0;
    float b = 0.0F;

    void print() const
    {
        std::cout << "a = " << a << "; b = " << b << std::endl;
    }
};

// class declaration -> normally goes into the header file
// ************************************************************
class Student
{
   public:
    int16_t num_of_exams = 0;
    int32_t id_number;
    std::string name;
    // define a constructor
    Student(std::string par_name, int32_t par_id, int64_t par_bank_account);
    void print() const;
    void update_bank_account(int64_t par_bank_account);

   private:
    int64_t bank_account_;
};
// ************************************************************

// class definition -> normally goes into the cpp file
// ------------------------------------------------------------
Student::Student(const std::string par_name, const int32_t par_id, const int64_t par_bank_account)
    : name{par_name}, bank_account_{par_bank_account}
{
    /*
        Initialization can be done
        1. directly in the declaration
        2. in the initializer list of the constructor definition
        3. in the constructor itself
    */
    id_number = par_id;
}
void Student::print() const
{
    std::cout << "********** Student ************" << std::endl;
    std::cout << "name: " << name << std::endl;
    // we can use the "this" pointer to make the usage 100% clear
    std::cout << "id: " << this->id_number << std::endl;
    std::cout << "num of exams: " << num_of_exams << std::endl;
    std::cout << "bank account: " << bank_account_ << std::endl;
    std::cout << "*******************************" << std::endl;
}
void Student::update_bank_account(const int64_t par_bank_account)
{
    bank_account_ = par_bank_account;
}
// ------------------------------------------------------------

auto main() -> int
{
    {
        MyCppStruct my_struct;

        std::cout << "Printing struct my_struct: " << std::endl;
        my_struct.print();
    }
    {
        MyCppClass my_class;

        std::cout << "Printing class my_class: " << std::endl;
        my_class.print();
    }
    {
        Student itsme(std::string("Benjamin"), 49589, 8533489684);
        itsme.update_bank_account(11111111111);
        itsme.print();
    }
}
