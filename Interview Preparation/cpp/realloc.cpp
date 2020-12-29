#include <iostream>

using namespace  std;

int32_t main()
{
    int *ptr = (int*) malloc(sizeof(int)*2);
    ptr[0] = 1, ptr[1] = 2;
    cout << ptr[0] << " " << ptr[1] << "\n";
    ptr = (int*)realloc(ptr, sizeof(int)*4);
    ptr[2] = 3;
    ptr[3] = 4;
    cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << " " << ptr[3] << "\n";
}