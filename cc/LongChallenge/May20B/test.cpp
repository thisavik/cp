#include <bits/stdc++.h>
using namespace std;
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}
int main() {
    tool();
    int t;
    cin >> t;
    while(t--) {
        int n, m, a[19];
        cin >> n >> m;
        for(int i=1; i<=n; i++) {
            int x;
            cin >> x;
            a[x]=i;
        }
        int cnt=0;
        for(int i=1; i<=n; i++) {
            if(a[i]!=i) {
                swap(a[i], a[a[i]]);
                cnt++;
                i--;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}