#include <stdio.h>

int* my_const_correct_function(int * mutable_ptr, int const * const immutable_ptr)
{
    int * inside_ptr; 
    int const * const inside_csc_ptr = immutable_ptr;

    inside_ptr = mutable_ptr; // fine
    ++*inside_ptr;  // fine
    ++*mutable_ptr; // fine
    
    //inside_ptr = immutable_ptr; // BAD, warning: assignment discards ‘const’ qualifier 
    //++*immutable_ptr; // ERROR, can not change the pointer value or address

    return inside_ptr; // fine
    //return inside_csc_ptr; // BAD, return discards ‘const’ qualifier
}

int main(void)
{
    int value_a = 11;
    int value_b = 22;    
    
    /* declare a const value variable */
    const int value_c = 33; // const value variable
    //value_c = 0; // assign a new value -> ERROR

    /* declare a normale pointer */
    int* ptr = &value_a;
    ptr = &value_b; // assign a new memory address
    *ptr = 33; // assign a new value

    /* declare a const value pointer */
    int const * const_s_ptr = &value_a; // const value pointer
    const_s_ptr = &value_b; // assign a new memory address
    // *const_s_ptr = 44; // assign a new value -> ERROR

    /* declare a const address pointer */
    int * const s_const_ptr = &value_a; // const address pointer
    // s_const_ptr = &value_b; // assign a new memory address -> ERROR
    *s_const_ptr = 55; // assign a new value

    /* declare a const value and const address pointer*/
    int const * const const_s_const_ptr = &value_a; // const value const address pointer
    // const_s_const_ptr = &value_b; // assign a new memory address -> ERROR
    // *const_s_const_ptr = 44; // assign a new value -> ERROR

    int* return_ptr = my_const_correct_function(ptr, s_const_ptr);

    return 0;
}