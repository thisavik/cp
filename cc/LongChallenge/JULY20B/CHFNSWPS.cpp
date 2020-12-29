#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define FORI(i, a, n) for(int i=a; i<n; i++)
#define int long long 
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
    vector<int> a, b;
    map<int, int> m;
    int mn = INT32_MAX;
    FORI(i, 0, n) {
        int val;
        cin >> val;
        mn = min(mn, val);
        m[val]++;
    }
    FORI(i, 0, n) {
        int val;
        cin >> val;
        mn = min(mn, val);
        if(m[val] == 0) {
            b.push_back(val);
        } else {
            m[val]--;
        }
    }
    for(auto& p: m) {
        while(p.second != 0) {
            a.push_back(p.first);
            p.second--;
        }
    }
    m.clear();
    for(int& val: a) {
        m[val]++;
    }
    if(a.size() == 0) {
        cout << 0 << "\n";
        return;
    } 
    bool possible = true;
    for(auto& p: m) {
        if(p.second % 2 != 0)
            possible = false;
    }
    m.clear();
    for(int& val: b) {
        m[val]++;
    }
    for(auto& p: m) {
        if(p.second % 2 != 0)
            possible = false;
    }
    if(!possible) {
        cout << -1 << "\n";
        return;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    int cost = 0;

    for(int i=0; i<a.size(); i+=2) {
        cost += min(min(a[i], b[i]), 2*mn);
    }
    cout << cost << "\n";
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}