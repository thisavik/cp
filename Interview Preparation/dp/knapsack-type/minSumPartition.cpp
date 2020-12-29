// In this problem we have to divide a array in two partition such that difference of their sum is minimum

// so we have to calculate min(sum(s1) - sum(s2))

// also we have sum(s1) + sum(s2) = sum(arr)

// so min(sum(arr) - sum(s2) - sum(s2)) = min(sum(arr) - 2*sum(s2))

// here problem reduces to find a sum of a subset such that 2times difference it with= array sum is minimum

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

// using top-down approach
int findMin(vi a, int n) {
  int sum=accumulate(a.begin(), a.end(), 0);
  bool dp[n+1][sum+1];
  Fori(i, 1, sum+1) 
    dp[0][i]=false;
  Fori(i, 0, n+1)
    dp[i][0]=true;
  Fori(i, 1, n+1) {
    Forj(j, 1, sum+1)
      if(a[i-1]<=j) 
        dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
      else
        dp[i][j] = dp[i-1][j];
  }
  int mn=sum;
  Fori(i, 0, sum/2+1) {
    if(dp[n][i]) {
      mn = min(sum-2*i, mn);
    }
  }
  return mn;
}

// using bottom up approach
//int dp[1001][1001];
int findMin(vi a, int n, int s1, int s2) {
  if(n==0) {
    return abs(s1-s2);
  }
  if(dp[])
  int inc = findMin(a, n-1, s1+a[n-1], s2);
  int exc = findMin(a, n-1, s1, s2+a[n-1]);
  return min(inc, exc);
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  Fori(i, 0, n) 
    cin >> a[i];
  cout << findMin(a, n) << "\n";
  cout << findMin(a, n, 0, 0) << "\n";
}

int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}