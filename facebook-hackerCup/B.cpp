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
    int aCnt = 0, bCnt = 0;
    for(char& ch: s) {
        if(ch == 'A')
            aCnt++;
        else
            bCnt++;
    }
    
    int m = n/2;

    if(aCnt == m || bCnt == m)
        cout << "Y";
    else
        cout << "N";

}

int32_t main() {
    tool();
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}