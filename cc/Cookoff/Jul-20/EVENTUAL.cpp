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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> fre(26, 0);
    for(char& ch: s)
        fre[ch-'a']++;
    // for(int& val: fre)
    //     cout << val << " ";
    // cout << "\n";
    bool flag = true;
    for(int& val: fre) 
        if(val&1) {
            flag = false;
            break;
        }
    if(flag)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}