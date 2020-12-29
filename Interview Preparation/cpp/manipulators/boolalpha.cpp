#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void tool() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	    freopen("C://git//cp//input.txt", "r", stdin);
	    freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

void solve() {
    bool a = true, c = 1;
    cout << a << " ";
    cout << c << "\n";
    // it simply convert boolean value in alpha numeric
    boolalpha(cout);
    cout << a << " ";
    cout << c << "\n";
}

int main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    cout << true << "\n"; 
    return 0;
}