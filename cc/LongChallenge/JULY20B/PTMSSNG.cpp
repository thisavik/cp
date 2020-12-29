#include <iostream>
using namespace std;

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
    n = 4*n-1;
    int input[n][2];
    for(int i=0; i<n; i++) 
        cin >> input[i][0] >> input[i][1];
    int xXor=input[0][0], yXor=input[0][1];
    for(int i=1; i<n; i++) {
        xXor ^= input[i][0];
        yXor ^= input[i][1];
    }
    cout << xXor << " " << yXor << "\n";
} 

int32_t main() {
	tool();
	int t;
	cin >> t;
	while(t--)
	    solve();
	return 0;
}
