#include <bits/stdc++.h>

using namespace std;

const int maxN = 5001;

string s1, s2;

int dp[maxN][maxN];

int solve(int i, int j)
{
    // string becomes equal
    if(i == -1 && j == -1)
        return 0;
    // s1 becomes empty before s2
    if(i == -1 && j > -1)
        return j+1;
    // s2 becomes empty before s1
    if(j == -1 && i > -1)
        return i+1;
    if(dp[i][j] == -1)
    {
        // character matches
        if(s1[i] == s2[j])
            dp[i][j] = solve(i-1, j-1);
        else
        {
            // insert
            int op1 = solve(i, j-1);
            // remove
            int op2 = solve(i-1, j);
            // replace
            int op3 = solve(i-1, j-1);
            dp[i][j] = min({op1, op2, op3}) + 1;
        }
    }
    return dp[i][j];
}

int solve() {
	cin >> s1 >> s2;
	memset(dp, -1, sizeof dp);
	cout << solve(s1.size()-1, s2.size()-1);
}

int main()
{
    int t = 1;
    while(t--)
        solve();
    return 0;
}
