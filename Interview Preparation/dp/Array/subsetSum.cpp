#include <iostream>
#include <bitset>

using namespace std;

// using bitset
bool solve(int a[], int n, int k) {
    bitset<5001> b(1);
    for(int i = 0; i < n; i++)
        b |= (b << a[i]);
    return b[k]; 
} 

int32_t main() {
    tool();
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int& val: a)
        cin >> val;
    cout << solve(a, n, k) << "\n";
}