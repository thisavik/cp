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
    string I, O;
    cin >> I >> O;
    vector<vector<bool>> dp (n, vector<bool>(n, false));
    // allowed for same airport
    for(int i = 0; i < n ; i++)
        dp[i][i] = true;
    // from left to  right
    for(int i = 0; i+1 < n; i++)
        if(O[i] == 'Y' && I[i+1] == 'Y')
            dp[i][i+1] = true;
    // from right to left
    for(int i = n-1; i > 0; i--)
        if(O[i] == 'Y' && I[i-1] == 'Y')
            dp[i][i-1] = true;

    // fill remaining upper half cells
    for(int i = 2; i < n; i++) {
        for(int j = 0; j < n-i; j++) {
            dp[j][j+i] = dp[j][j+i-1] & dp[j+1][j+i];
            dp[i+j][j] = dp[i+j-1][j] & dp[i+j][j+1];
        }
    }
    for(int i = 0; i < n ; i++) {
        cout << "\n";
        for(int j = 0; j < n; j++)
            if(dp[i][j]) cout << "Y";
            else cout << "N"; 
    }
    cout << "\n";
}
int32_t main() {
    tool();
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i <<":";
        solve();
    }
    return 0;
}