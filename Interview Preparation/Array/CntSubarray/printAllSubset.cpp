#include <iostream>
using namespace std;
int main()
{
    int a[] = {1, 2, 3};
    int b = (1 << 3);
    cout << b << "\n";
    for (int i = 0; i <= 7; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i & 1 << j)
                cout << a[j] << " ";
        }
        cout << "\n";
    }
}