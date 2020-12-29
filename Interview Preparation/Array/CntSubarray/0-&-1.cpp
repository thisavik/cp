#include <iostream>
#include <vector>
#include <map>

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& val:a) {
        cin >> val;
        (val == 0) ? (val = -1) : (val = 1);
    }
    map<int, int> m;
    int sum = 0, maxLen = 0, endIndex = -1;
    for(int i=0; i<n; i++) {

        sum += a[i];
        if(sum == 0) {
            maxLen = i+1;
            endIndex = i;
        }

        if(m.find(sum) != m.end()) {
            if(maxLen < i-m[sum]) {
                maxLen = i - m[sum];
                endIndex = i;
            }
        } else 
            m[sum] = i;
    }
    cout << maxLen << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}