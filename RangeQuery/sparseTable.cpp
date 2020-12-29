// program to do range minimum query using sparse table
// lookUp[i][j] contain minimum in range from arr[i] to arr[i+2^j-1]

#include <iostream>
#include <vector>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C://git//cp//input.txt", "r", stdin);
    freopen("C://git//cp//output.txt", "w", stdout);
#endif
}
vector<vector<int>> bulidSparseTable(vector<int>& a) {
	int n = a.size();
	vii lookUp(n, vi ((ceil)(log2(n)), 0));
	loop(n) {
		lookUp[i][0] = a[i];
	}
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			// cout << i << " " << j << endl;
			lookUp[i][j] = lookUp[i][j - 1] + lookUp[i + (1 << (j - 1))][j - 1];
		}
		loop(n) {
			for (int j = 0; j < lookUp[i].size(); j++)
				cout << lookUp[i][j] << " ";
			cout << endl;
		}
	}
	return lookUp;
}
void solve() {
	int n;
	cin >> n;
	vi a(n);
	loop(n) {
		cin >> a[i];
	}
	loop(n) {
		cout << a[i] << " ";
	}
	cout << "\n";
	vii lookUp = bulidSparseTable(a);
}
int32_t main() {
	tool();
	int t;
	cin >> t;
	loop(t)
	solve();
	return 0;
}