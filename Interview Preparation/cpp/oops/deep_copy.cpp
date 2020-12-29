#include <iostream>

using namespace std;

class A
{
    int x, y, *p;

public:
    A(): x(0), y(0)
    {
        p = new int;
    }
    A(int a, int b, int z)
    {
        x = a, y = b, p = new int(z);
    }
    A(A &a)
    {
        x = a.x, y = a.y, p = new int(*a.p);
    }
    void showdata()
    {
        cout << "x = " << x << " y = " << y << " " << " *p = " << *p << "\n";
        cout << p << "\n";
    }
    void operator=(A &a)
    {
        x = a.x, y = a.y, *p = *a.p; 
    }
};

int32_t main()
{
    A a(3, 4, 7);
    a.showdata();
    A c;
    c.showdata();
    c = a;
    c.showdata();
    return 0;
}