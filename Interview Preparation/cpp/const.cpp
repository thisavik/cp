#include <iostream>

using namespace std;

// const 
//  -> A compile time contraint that an object can not be modified

int32_t main()
{
    const int i = 5; // const object
    int j = 7; // non const object
    int const k = 3; // same as const int k = 3;

    // int *p = &i; // simple pointer can't point const object
    int *q = &j; // valid


    const int *p1 = &i; // pointer is not const but data pointed by pointer is treated as const
    const int *p2 = &j; // whether object may be const or non-const
    cout << "p1 " << p1 << " " << *p1 << "\n"; 
    cout << "p2 " << p2 << " " << *p2 << "\n"; 

    int *const p3 = &j;    // pointer is const but data pointed by pointer must be non const
    // int *const p4 = &i; // error
    cout << "p3 " << p3 << " " << *p3 << "\n";

    const int *const p5 = &i; // pointer and data pointed by pointer both are const 
    const int *const p6 = &j; // whether object may be const or non-const
    cout << "p5 " << p5 << " " << *p5 << "\n";
    cout << "p6 " << p6 << " " << *p6 << "\n";

    // int &r1 = i; // error is object is const the it's reference must const
    int &r2 = j;
    cout << "r2 " << &r2 << " " << r2 << "\n";

    const int &r3 = i; // object and its reference both are const
    const int &r4 = j; // we can make const reference of non-const objec
    cout << "r3 " << &r3 << " " << r3 << "\n";
    cout << "r4 " << &r4 << " " << r4 << "\n";

    int const &r5 = i; // same as const int &r5 = i;
    int const &r6 = j; // same as const int &r6 = j;
    cout << "r5 " << &r5 << " " << r5 << "\n";
    cout << "r6 " << &r6 << " " << r6 << "\n";

    int *&rp1 = q; // reference of simple pointer
    const int *&rp2 = p1; // reference of pointer pointing to const object
    int *const &rp3 = p3; // reference of const pointer pointing to non-const object(must)
    const int *const &rp4 = p5; // reference of const pointer pointing to const/non-const object but treat it as const object

    return 0;
}