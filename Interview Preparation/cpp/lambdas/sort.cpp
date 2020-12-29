#include <iostream>
#include <vector>
#include <algorithm>

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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& val: a)
        cin >> val;

    // Lambdas 
    sort(a.begin(), a.end(), [](int a, int b) {
        return a > b;
    });
    for(int& val: a)
        cout << val << " ";
    cout << "\n";
}

int main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}