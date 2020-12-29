#include <iostream>

using namespace  std;

class A
{
public:
    void f1() { }
    void f2() { }
};

class B:public A
{
public:
    void f1() { } // Method overridding
    void f2(int a) { } // Method Hiding
    void f1(int a) { } // Method overloading
};

int32_t main()
{
    printf("%p\n", A::f1);
    printf("%p\n", A::f2);
    printf("%p\n", B::f1);
    printf("%p\n", B::f2);
}
