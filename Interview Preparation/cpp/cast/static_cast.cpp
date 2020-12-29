#include <iostream>

using namespace std;

class Int
{
    int x;

public:
    Int(int x = 0) : x{x}
    {
        cout << "Conversion constructor" << x << "\n";
    }
    operator string()
    {
        cout << "Conversion operator" << x << "\n";
        return to_string(x);
    }
    ~Int()
    {
        cout << "Object destructed" << x << "\n";
    }
};

class Base
{
};
class Derived : private Base
{
};
class Derived1 : public Base
{
};
class Derived2 : public Base
{
};

int32_t main()
{
    // scenario 1
    // for compatible type conversion
    int a = 2;
    float f = 1.3;

    a = f;
    a = (int)f;
    a = static_cast<int>(f);

    // scenario 2
    Int obj(3);

    string s1 = obj;
    obj = 20;

    string s2 = static_cast<string>(obj);
    obj = static_cast<Int>(30);

    //scenario 2
    char c;
    int *p = (int *)&c;
    *p = 5;

    // int *q = static_cast<int*>(&c); // invalid but in c style cast, it is valid, we may get run time error in c

    // scenario 3
    // Derived d1;
    // Base *b1 = (Base*)&d1; // c style would not provide any error for this statement but it is.
    // Base *b2 = static_cast<Base*>(&d1); // base pointer pointing to privately inherited derived class is not allowed

    // scenario 4
    // Use for all upper cast bu tnever use for confused down cast
    Derived1 c1;
    Derived2 c2;
    Base *b1 = static_cast<Base *>(&c1);
    Base *b2 = static_cast<Base *>(&c2);
    Derived1 *cd1 = static_cast<Derived1*>(b2);  // wrongly type casted but code complies successfully
    Derived2 *cd2 = static_cast<Derived2*>(b1);  // same for this statement

    // scenario 5
    // should be prefered when converting to void* or from void* 
    int p = 10;
    void *v = static_cast<void*>(&p);
    int *ip = static_cast<int*>(v);
}