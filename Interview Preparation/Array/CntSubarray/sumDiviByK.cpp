#include <iostream>
#include <vector>
#include <map>

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int& val:a) {
        cin >> val;
    }
    map<int, int> m;
    int sum = 0, maxLen = 0;
    for(int i=0; i<n; i++) {

        sum += a[i];
        if(sum % k == 0) {
            maxLen = i+1;
        }
            m[sum] = i;
        int x = k;
        while(x <= sum) {
            if(m.find(sum-x) != m.end()) {
                maxLen = max(maxLen, i-m[sum-x]);
            }
            x += k;
        }
    }
    cout << maxLen << "\n";
}

int main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}