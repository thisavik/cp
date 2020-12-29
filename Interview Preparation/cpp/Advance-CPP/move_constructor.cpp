#include <iostream>

using namespace std;

class Base
{
    int *x;
public:
    Base()
    {
        x = new int[5];
        for(int i = 0; i < 5; i++)
            x[i] = i+1;
        cout << "Default Constructor " << x << "\n";
    }
    Base(Base &b)
    {
        x = new int[5];
        for(int i = 0; i < 5; i++)
            x[i] = b.x[i];
        cout << "Copy Constructor " << x << "\n";
    }
    Base(Base &&b): x(b.x)
    {
        cout << "Move Constructor " << x << "\n";
    }
    ~Base()
    {
        cout << "Destructor Call " << x << "\n";
        delete x;
    }
};

int32_t main()
{
    Base b1;
    Base b2 = b1;
    Base b3 = move(b2);
    Base b4(b1);
    Base b5 = move(b1);
    return 0;
}