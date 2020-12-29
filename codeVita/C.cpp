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

int32_t main() {
    tool();
    int p, q, r, s;
    cin >> p >> q >> r >> s;
    vector<int> mx, mn;
    for(int i=p; i<=q; i++) 
        mx.push_back(i);
    for(int i=r; i<=s; i++)
        mn.push_back(i);
    int ans = 0;
    for(int i=0; i<mx.size(); i++) {
        for(int j=0; j<mn.size(); j++) {
            int x = mx[i];
            int y = mn[j];
            while(x > 0 && y > 0) {
                ans++;
                if(x > y) {
                    x -= y;
                } else if(y > x) {
                    y -= x;
                } else {
                    x = 0;
                    y = 0;
                }
            }
        }
    }
    cout << ans << "\n";
}