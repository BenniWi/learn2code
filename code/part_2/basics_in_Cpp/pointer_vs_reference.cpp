

class MyTestClass
{
   public:
    int test_member = 0;
};

void function_with_reference(MyTestClass &mtc)
{
    mtc.test_member = 1;
}

void function_with_pointer(MyTestClass *mtc)
{
    mtc->test_member = 2;
}

auto main() -> int
{
    int i = 3;
    int a = 10;

    // A pointer to variable i or "stores the address of i"
    int *ptr = &i;

    // A reference (or alias) for i.
    int &ref = i;

    // reassignment:
    ptr = &a;  // that's fine
    // &ref = a;  // It is incorrect as we should declare and initialize references at single step
    // this means: also re-initialization is not possible
}
