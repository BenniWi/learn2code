---
marp: true
title: Programming 2
author: Benjamin Wilking
theme: uncover
style: |
  section {
    font-size: 30px
  }
class: invert
paginate: false
---

![width:800px](images/welcome2.jpg "welcome")

---

<style scoped>
  section{
  font-size: 20px;
  }
</style>

## Table of Contents

<a id="table-of-contents"></a>

- [Literature](#literature)
- [Exercises@Home \& Exam](#exerciseshome--exam)
- [Preparations for Every Lesson](#preparations-for-every-lesson)
- [From *C* to *C++*](#from-c-to-c)
- [Testing Code & Test Driven Development](#test-driven-development)
- [Dynamic Memory in *C* \& *C++*](#dynamic-memory-in-c--c)
- [Inheritance](#inheritance)
- [Polymorphism](#polymorphism)
- [STL](#stl)

---

<!-- paginate: true -->

<!-- header: Labor Softwareentwicklung 2, Q1 2023 -->

<!-- footer: Benjamin Wilking © -->

# Literature

<a id="literature"></a>

[free C++-books](https://tfetimes.com/free-c-books/)

---

# Exercises@Home & Exam  

<a id="exerciseshome--exam"></a>

## Homework

- Homework is voluntary but strongly recommended.
- You are welcome to ask questions, I'm glad to help.

## Exam

- During the last 3 weeks of the course.
- In teams of up to 3 people (2 preferred).
- Delivery in [Git](slides_learn2code_1.md#git).

---

# Preparations for Every Lesson

<a id="preparations-for-every-lesson"></a>

Complexity is increasing very fast, so make sure to

1. maintain a working repository (preferably on [GitHub](https://github.com/))
   - [CMake](https://cmake.org/) is mandatory
2. add our code from the lessons to this repository
   - try to evolve your [Git](https://git-scm.com/) capabilities
3. keep a continuous integration running on the repository (only with GitHub)
4. finish the tasks from the lessons at home
5. stick to coding conventions (clang-format, clang-tidy, doxygen)

---

# From *C* to *C++*

<a id="from-c-to-c"></a>

---

## Enable *C++* Language in *CMake*

```CMake
# define the project name
project(basics_in_Cpp VERSION 1.0 LANGUAGES CXX)

# define the c standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```

---

## *C++* Filenames

In order to tell CMake and the compiler you should use the following file names:

```*.cpp``` for all source files
```*.h``` and ```*.hpp``` for all header files

---

## *C++* Hello World

```cpp
#include <iostream>

auto main() -> int // see also "trailing return type"
{
    std::cout << "Hello World" << std::endl;

    return 0;
}
```

---

## From Structs to Classes

### *C++* Struct

```cpp
// old C-Style 
typedef struct 
{
 ....
}MyCppStruct;

// modern C++-Style
using MyCppStruct = struct
{
 ....
};
```

---

```cpp
using MyCppStruct = struct
{
    int16_t a = 0; // type from cstdint https://en.cppreference.com/w/cpp/types/integer
    float b = 0.0F;

    void print() const
    {
        std::cout << "a = " << a << "; b = " << b << std::endl;
    }
};

auto main() -> int
{
        MyCppStruct my_struct;
        std::cout << "Printing struct my_struct: " << std::endl;
        my_struct.print();
}
```

---

### *C++* Class

```cpp
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

auto main() -> int
{
        MyCppClass my_class;
        std::cout << "Printing class my_class: " << std::endl;
        my_class.print();
}
```

---

### Parts of a *C++* Class

```cpp
class MyCppClass
{
// publics are accessible from outside the class
   public:  
    float pub_member_var = 0.0F; // public member variable
    void pub_member_func(){}     // public member function (method)
    // Constructor: A constructor in C++ is a special method that is 
    // automatically called when an object of a class is created.
    MyCppClass();
    // There is also a destructor, but we don't use it for now
    ~ MyCppClass();
// privates cannot be accessed (or viewed) from outside the class
   private: 
    float priv_member_var = 0.0F; // private member variable
// protected elements cannot be accessed from outside the class, 
// but can be accessed in inherited classes.
   protected: 
    void prot_member_func(){}     // protected member function (method)
};
```

---

### *C++* Class Declaration

Class declaration :arrow_right: normally goes into the header file

```cpp
class Student
{
   public:
    int16_t num_of_exams = 0;
    int32_t id_number;
    std::string name;
    // define a constructor
    Student(std::string par_name, int32_t par_id);
    void print() const;
};
```

---

### *C++* Class Definition

Class definition :arrow_right: normally goes into the cpp file

```cpp
Student::Student(std::string par_name, int32_t par_id) : name{par_name}
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
    // print code goes here!
}
```

---

### *C++* Class Exercise

Take the "student" example from above and ...

1. add a **private** member for the *bank account number*
2. extend the *constructor* to initialize the bank account number
3. write an *update_bank_account* method to update the bank account number
4. implement the *print* method

You can find the code for this exercise in the file [struct_to_class.cpp](https://github.com/BenniWi/learn2code/blob/main/code/part_2/basics_in_Cpp/struct_to_class.cpp)

---

## Namespaces

---

```cpp
namespace my_awesome_namespace
{
class AwesomeClass
{
   public:
    int16_t a = 0;  // type from cstdint https://en.cppreference.com/w/cpp/types/integer
    float b = 0.0F;

    void print() const
    {
        std::cout << "a = " << a << "; b = " << b << std::endl;
    }
};
}  // namespace my_awesome_namespace

auto main() -> int
{
    my_awesome_namespace::AwesomeClass my_class;
    my_class.print();
}

```

---

```cpp
namespace my_awesome_namespace
{
  ....
}  // namespace my_awesome_namespace

namespace my_awesome_namespace
{
namespace my_more_awesome_namespace
{
class MoreAwesomeClass
{
   public:
    static void print_hello()
    {
        std::cout << "hello from a static class method in namespace" << std::endl;
    }
};
};  // namespace my_more_awesome_namespace
}  // namespace my_awesome_namespace

auto main() -> int
{
    my_awesome_namespace::my_more_awesome_namespace::MoreAwesomeClass::print_hello();
}
```

---

### **"using"** Namespaces

The [keyword](https://en.cppreference.com/w/cpp/language/using_declaration) ```using``` simplyfies things a lot.

```cpp
using namespace std
[...]
cout << "Hello World" << endl;
```

:warning: But:

- :zap: *NEVER* :zap: put ```using``` into a header file
- you *MIGHT* put it into the source file carefully
- prefer [namespace aliases](https://en.cppreference.com/w/cpp/language/namespace_alias) (only in source files)
  ```namespace fbz = foo::bar::baz;```

---

## References in *C++*

> A reference variable is an alias, that is, another name for an already existing variable. A reference, like a pointer, is also implemented by storing the address of an object. [[geeksforgeeks](https://www.geeksforgeeks.org/pointers-vs-references-cpp/)]

```cpp
int i = 3;
int a = 10;
// A pointer to variable i or "stores the address of i"
int *ptr = &i;
// A reference (or alias) for i.
int &ref = i;
// reassignment
ptr = &a;  // that's fine
&ref = a;  // ERROR as we should declare and initialize references at single step
// this means: also re-initialization is not possible
```

---

### References as Arguments in *C++*

```cpp
class MyTestClass
{
   public:
    int test_member = 0;
};

void function_with_copy(MyTestClass mtc)
{
    mtc.test_member = 1;
}

void function_with_reference(MyTestClass &mtc)
{
    mtc.test_member = 1;
}

void function_with_pointer(MyTestClass *mtc)
{
    mtc->test_member = 2;
}
```

---

![width:900px](images/copy_pointer_reference.svg "copy_pointer_reference")

---

![width:900px](images/reference_value_cups.gif "copy_pointer_reference")
<font size="+1"><a href=https://dev.to/erraghavkhanna/pass-by-value-reference-explained-with-single-gif-believe-me-it-s-true-23ki>dev.to</a></font>

---

<style scoped>
  section{
  font-size: 25px;
  }
</style>

### References vs. Pointers

<table><thead><tr><th>&nbsp;</th><th>References</th><th>Pointers</th></tr></thead><tbody><tr><th>Reassignment</th><td>The variable cannot be reassigned in Reference.</td><td>The variable can be reassigned in Pointers.</td></tr><tr><th>Memory Address</th><td>It shares the same address as the original variable.</td><td>Pointers have their own memory address.</td></tr><tr><th>Work</th><td>It is referring to another variable.</td><td>It is storing the address of the variable.</td></tr><tr><th>Null Value</th><td>It does not have null value.</td><td>It can have value assigned as null.</td></tr><tr><th>Arguments</th><td>This variable is referenced by the method pass by value.</td><td>The pointer does it work by the method known as pass by reference.</td></tr></tbody></table>

Refer to [geeks4geeks](https://www.geeksforgeeks.org/pointers-vs-references-cpp/) for more details

---

# Testing Code & Test Driven Development

<a id="test-driven-development"></a>

> Test-driven development (TDD) is a software development process relying on software requirements being converted to test cases before software is fully developed, and tracking all software development by repeatedly testing the software against all test cases. ([wikipedia](https://en.wikipedia.org/wiki/Test-driven_development))

---

## TDD Process

1. What are your requirements? What do you want to achieve?
2. Write your tests (using a test framework)
3. Write the most simple code to pass the tests
4. Improve your code to pass all tests
5. Beautify the code

---

## googletest

![width:300px](images/googletest.jpg "googletest")

> googletest is a testing framework developed by the Testing Technology team with Google’s specific requirements and constraints in mind. Whether you work on Linux, Windows, or a Mac, if you write C++ code, googletest can help you. ([googletest](https://google.github.io/googletest/primer.html))

---

## How to Use googletest

1. You only can test libraries, not executables
2. googletest is a **C++** library, so we have to use **C++** for our tests
3. add googletest to your *CMakeLists.txt*
4. write your tests
5. Run your tests

---

### Add googeltest to Your CMakeLists.txt

```cmake
# enable the testing
enable_testing()
# check if we have gtest
find_package(GTest REQUIRED)
# include the gtest CMake stuff
include(GoogleTest)
# create a test executable
add_executable(tests test/test_functions.cpp)
# link the gtest libraries
target_link_libraries(tests PRIVATE GTest::GTest GTest::Main)
# link the library we want to test
target_link_libraries(tests PRIVATE tdd_functions_lib)
# add the include directories
target_include_directories(tests PUBLIC include)
# discover and add tests to the test list
gtest_discover_tests(tests)
```

---

### Write a Test

```C
#include "gtest/gtest.h" // include the gtest functions & macros
#include "functions.h"

// the first test we want to write
TEST (tdd_tests, add_standard_integers) { 

    EXPECT_EQ (11, add_integers(5,6));
}
```

[GTest CheatSheet](https://qiangbo-workspace.oss-cn-shanghai.aliyuncs.com/2018-12-05-gtest-and-coverage/PlainGoogleQuickTestReferenceGuide1.pdf)

---

### Run the Tests

after compiling everything you have two possibilities:
```cd <build_folder>```
run ```ctest```
or
run the created the test target ```./tests```

---

# Dynamic Memory in *C* & *C++*

<a id="dynamic-memory-in-c--c"></a>

Every instantiated variable is allocated on the **stack**. The **stack** memory is very limited in size.
If more memory is needed, the solution is to use the **heap** memory instead.

---

## Dynamic Memory in *C*

1. [malloc](https://en.cppreference.com/w/c/memory/malloc)
Allocates memory on the heap and returns a pointer to this memory
2. [calloc](https://en.cppreference.com/w/c/memory/calloc)
Allocates memory for an array of num objects of size and initializes all bytes in the allocated storage to zero.

:warning: It is very important to free the memory if it is not needed anymore. Either use [free](https://en.cppreference.com/w/c/memory/free) or [realloc](https://en.cppreference.com/w/c/memory/realloc)

---

### Example for *malloc* & *calloc*

```C
int num_of_elements = 5;

// Dynamically allocate memory using malloc()
int* mal_ptr = (int*)malloc(num_of_elements * sizeof(int));
// do some stuff
// free the memory again
free(mal_ptr);

// Dynamically allocate memory using calloc()
int* cal_ptr = (int*)calloc(num_of_elements, sizeof(int));
// do some stuff
// free the memory again
free(cal_ptr);
```

----

### Example for memory leak with malloc/calloc

```C
// BAD EXAMPLE -- MEMORY LEAK
int* ptr2 = NULL;
for (int i = 0; i < noe; i++)
{
    ptr2 = (int*)calloc(100000, sizeof(int));
}
free(ptr2);
```

---

### Exercise for *malloc* & *calloc*

Write a small *C* program to

- read in a number as size of an array.
- create an array by allocating the corresponding amount of memory.
- initialize the elements of the array with numbers from 1 to *size*
- print the elements of the array to the terminal.

You can find the code for this exercise in the file [dynamic_memory.c](https://github.com/BenniWi/learn2code/blob/main/code/part_2/basics_in_Cpp/dynamic_memory.c)

---

## Dynamic Memory in *C++03* and Earlier

The **OLD** way of allocating memory in C++ is quite similar to *C*.
Instead of using ```malloc``` and ```free```, *C++* provides the functions
[new](https://en.cppreference.com/w/cpp/language/new) and [delete](https://en.cppreference.com/w/cpp/language/delete)

---

### Example for *new*

```Cpp
int num_of_elements = 5;

// Allocate memory for a single value
int* single_ptr = new int;
// Allocate memory for an array
int* arr_ptr = new int[num_of_elements];
// do some stuff
// free the memory again
delete single_ptr; 
delete[] arr_ptr; // Be aware of the [] in case of an array

```

---

### Exercise for *new*

Write a small *C++* program to

- read in a number as size of an array.
- create an array by allocating the corresponding amount of memory.
- initialize the elements of the array with numbers from 1 to *size*
- print the elements of the array to the terminal.

You can find the code for this exercise in the file [dynamic_memory_old.cpp](https://github.com/BenniWi/learn2code/blob/main/code/part_2/basics_in_Cpp/dynamic_memory_old.cpp)

---

## Dynamic Memory in *C++14* and later

The **NEW** way of allocating memory in C++ is quite different to the old style.
Instead of using ```new```, *C++14* and later provides [smart pointers](https://en.cppreference.com/book/intro/smart_pointers).

---

### *smart pointers*

Smart pointers are used to make sure that an object is deleted if it is no longer used (referenced).

```cpp
void my_func_w_leak()
{
    int* valuePtr = new int(15);
    int x = 45;
    if (x == 45)
        return;   // here we have a memory leak, valuePtr is not deleted
    delete valuePtr;
}
//---------------------
void my_func_wo_leak()
{
    std::unique_ptr<int> valuePtr(new int(15));
    int x = 45;
    if (x == 45)
        return;   // no memory leak anymore!
}
```

---

#### *unique_ptr*

>std::unique_ptr is a smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope. [[unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr)]

```cpp
// creating a unique_ptr
std::unique_ptr<int> uni_ptr(new int); // single value
std::unique_ptr<int[]> array_uni_ptr(new int[5]); // array of size 5
std::unique_ptr<int> make_uni_ptr = std::make_unique<int>(); // single value
std::unique_ptr<int[]> make_array_uni_ptr = std::make_unique<int[]>(5); // array of size 5
// we can also use "auto" here
auto auto_uni_ptr = std::make_unique<int>();
// accessing an element of an array inside a unique_ptr
array_uni_ptr.get()[0] = 5;
```

---

#### *shared_ptr*

>std::shared_ptr is a smart pointer that retains shared ownership of an object through a pointer. Several shared_ptr objects may own the same object. [[shared_ptr](https://en.cppreference.com/w/cpp/memory/shared_ptr)]

```cpp
// creating a shared_ptr
std::shared_ptr<int> shr_ptr(new int); // single value
std::shared_ptr<int[]> array_shr_ptr(new int[5]); // array of size 5
std::shared_ptr<int> make_shr_ptr = std::make_shared<int>(); // single value
std::shared_ptr<int[]> make_array_shr_ptr = std::make_shared<int[]>(5); // array of size 5
// we can also use "auto" here
auto auto_shr_ptr = std::make_shared<int>();
// accessing an element of an array inside a shared_ptr
array_shr_ptr.get()[0] = 5;
```

---

### Exercise for *smart pointers*

Write a small *C++* program to

- read in a number as size of an array.
- create an array by allocating the corresponding amount of memory using a *unique_ptr*.
- initialize the elements of the array with numbers from 1 to *size*
- print the elements of the array to the terminal.

You can find the code for this exercise in the file [dynamic_memory_new.cpp](https://github.com/BenniWi/learn2code/blob/main/code/part_2/basics_in_Cpp/dynamic_memory_new.cpp)

---

# Inheritance

<a id="inheritance"></a>

---

# Polymorphism

<a id="polymorphism"></a>

---

# STL

<a id="stl"></a>

---
