#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

#define int long long
#define FORI(i, a, b) for(int i=a; i<b; i++)
#define FORJ(j, a, b) for(int j=a; j>=b; j--)

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    stack<int> stk;
    map<int, int> m;
    FORI(i, 0, n) {
        char ch = s[i];
        if(ch == '(') {
            stk.push(i);
            m[i] = -2;
        } else {
            if(!stk.empty()) {
                m[stk.top()] = i;
                stk.pop();
            }
        }
    }
    // for(auto p: m) 
    //     cout << p.first << " " << p.second << "\n";
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        x--;
        if(m.find(x) != m.end()) {
            cout << m[x] + 1 << "\n";
            continue;
        } else {
            pair<int, int> ans;
            for(auto p: m) {
                if(p.first > x) {
                    ans = p;
                    break;
                }
            }
            cout << ans.second+1 << "\n";
        }
   }    
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}