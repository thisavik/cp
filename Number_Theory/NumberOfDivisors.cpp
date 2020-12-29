/* 
	You are givdn teo number n, k. For each number in the interval [1, n], your task is to calculate its
  divisor that is not divisible by k. Print the sum of these divisors.

	Note : k is prime number

	constraint : t = [0, 3*10^6], n = [1, 10^9], k = [2, 10^9]
*/

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
#define pii pair<int,int>
#define si set<int>
#define mii map<int, int>
#define Fori(i, a, n) for(int i=a; i<n; i++)
#define Forj(j, a, n) for(int j=a; j<n; j++)
#define Fork(k, a, n) for(int k=a; k<n; k++)
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}
void solve() {
	int n, k;
  cin >> n >> k;
  int sum=n*(n+1)/2;
	int x=n/k;
	while(x>0) {
		int extraSum = k*(x*(x+1))/2;
		sum -= extraSum;
		extraSum = x*(x+1)/2;
		sum += extraSum;
		x=x/k;
	}
	cout << sum << "\n";
}
int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
