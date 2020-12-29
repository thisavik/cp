#include <iostream>

using namespace std;

#define int long long

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
    int n;
    cin >> n;
    int cat[n+1];
    cat[0] = 1;
    cat[1] = 1;
    for(int i = 2; i <= n; i++) {
        int ans = 0;
        for(int j = 0; j < i; j++)
            ans += cat[j]*cat[i-j-1];
        cat[i] = ans;
    }
    cout << cat[n] << "\n"; 
}

int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}