#include <iostream>
#include <vector>
#include <algorithm>

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

int32_t main() {
    tool();
    int n, q;
    cin >> n >> q;
    vector<int> h(n), a(n);
    FORI(i, 0, n)
        cin >> h[i];
    FORI(i, 0, n)
        cin >> a[i];
    while(q--) {
        int ans = 0;
        int type, b, k; 
        cin >> type >> b >> k;
        b--;
        if(type&1) {
            a[b] = k;
        } else {
            k--;
            // cout << b << " " << k << "\n";
            if(b > k) {
                int mx = h[k];
                ans = a[k];
                FORI(i, k+1, b+1) {
                    // cout << mx << " " << h[i] << " " << h[b] << "\n";
                    if(mx < h[i]) {
                        mx = h[i];
                        ans += a[i];
                    }
                    if(h[b] <= mx && i != b) {
                        ans = -1;
                        break;
                    }
                }
            } else {
                int mx = h[k];
                ans += a[k];
                FORJ(j, k, b) {
                    // cout << mx << " " << h[j] << " " << h[b] << "\n";
                    if(mx < h[j]) {
                        mx = h[j];
                        ans += a[j];
                    }
                    if(h[b] <= mx && j != b) {
                        ans = -1;
                        break;
                    }
                }
            }
            cout << ans << "\n";
        }
    }
        
    return 0;
}