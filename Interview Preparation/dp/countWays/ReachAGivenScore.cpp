// Consider a game where a player can score 3 or 5 or 10 points in a move. 
// Given a total score n, find number of distinct combinations to reach the given score.
// in this case also e.g. {3,5}, {5,3} both represent same combination

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define ff first
#define ss second
#define MOD (int)10e9+7
#define endl "\n"
#define pb push_back
#define mp make_pair
#define it iterator
#define pii pair<int,int>
#define si set<int>
#define mii map<int, int>
#define mci map<char, int>
#define Fori(i, a, n) for(int i=a; i<n; i++)
#define Forj(j, a, n) for(int j=a; j<n; j++)
#define ForG(k, a, n) for(int k=a; k<n; k++)
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

    // score 
    int a[3]={3,5,10};
    int dp[n+1]={0};

    // base condition
    dp[0]=1;

    for(int i=0; i<=2; i++) 
        for(int j=a[i]; j<=n; j++)
            dp[j] += dp[j-a[i]];
    cout << dp[n] << "\n";
}

int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}