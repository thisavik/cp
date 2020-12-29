#include <iostream>

using namespace std;

int sum(int a, int b)
{
    return a + b;
}

int mul(int a, int b)
{
    return a*b;
}

int sub(int a, int b)
{
    return a-b;
}

void wrapper(int (*fun)(int, int), int n, int m)
{
    cout << fun(n, m) << "\n";
}

int32_t main()
{
    int x = 8;
    int *p = &x;

    // function pointer
    int (*add)(int, int) = sum;
    cout << add(2, 3) << "\n";
    printf("%p %p\n", sum, add);

    // function pointer array
    int (*fun_ptr[])(int, int) = {sum, mul, sub};
    cout << fun_ptr[0](2, 2) << " " << fun_ptr[1](2, 2) << " " << fun_ptr[2](2, 2) << "\n";

    cout << "\n" << printf("%p %p", sum, fun_ptr[0]) << "\n";
    printf("%p %p\n", mul, fun_ptr[1]);
    printf("%p %p\n", sub, fun_ptr[2]);

    // wrapper class use to call other function
    wrapper(sum, 5, 3);
    wrapper(mul, 5, 3);
    wrapper(sub, 5, 3);

}