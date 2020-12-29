#include <iostream>
using namespace std;

class e {};
struct node {};
int main() {
    cout << sizeof(e) << " " << sizeof(node);
    return 0;
}