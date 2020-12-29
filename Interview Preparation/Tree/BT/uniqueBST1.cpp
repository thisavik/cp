// https://leetcode.com/problems/unique-binary-search-trees/

#include <iostream>
#include <vector>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

int numTrees(int n) {
    vector<int> catalan(n+1, 0);
    catalan[0] = catalan[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            catalan[i] += catalan[j]*catalan[i-j-1];
        }
    }
    return catalan[n];
}

void solve() {
    int n;
    cin >> n;
    cout << numTrees(n) << "\n"; 
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}