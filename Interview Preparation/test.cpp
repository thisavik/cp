#include <bits/stdc++.h>
using namespace std;

#define int long long 
void solve() {
    int n, m;
    cin >> n >> m;
    if(n > m)
        cout << 0 << "\n";
    else {
        if(n % 2 == 0) {
            if(m >= 2*n-1) {
                cout << 2*n;
            }
            else 
            {
                cout << m % n;
            }
        }
        else 
        {
            cout << ceil((double)(m-n+1) / (n+1)) * (n+1);
        }
    }
    cout << "\n";
}

int32_t main() {
	int t;
	cin >> t;
	while(t--)
	    solve();
	return 0;
}


































