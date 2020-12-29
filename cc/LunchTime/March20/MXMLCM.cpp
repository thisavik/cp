#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull GCD(ull a, ull b) {
	if(a % b == 0)
		return b;
	return GCD(b, a % b);
}

ull LCM(ull a, ull b) {
	return (a*b)/GCD(a, b);
}

ull a[10001], n, m;
void solve() {
	cin >> n >> m;
	ull lcm = 1;
	for(ull i = 0; i<n; i++){
		cin >> a[i];
		lcm = LCM(lcm, a[i]);
	}
	for(int i=m; i>1; i--){
		
	}
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--)
		solve();
	return 00
}