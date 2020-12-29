// find number of divector<int>sor of product of array in efficient way

#include <iostream>
#include <vector>
#include <map>

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

void addx(int n, map<int, int>& ans, int& res) {
	int k = 2, cnt = 0;
	while (k <= n) {
		if (n % k == 0) {
			n /= k;
			cnt++;
		}
		else {
			res /= (ans[k] + 1);
			ans[k] += cnt;
			cnt = 0;
			res *= (ans[k] + 1);
			k++;
		}
	}
	if (cnt != 0) {
		res /= (ans[k] + 1);
		ans[k] += cnt;
		cnt = 0;
		res *= (ans[k] + 1);
	}
}

void removex(int n, map<int, int>& ans, int& res) {
	int k = 2, cnt = 0;
	while (k <= n) {
		if (n % k == 0) {
			n /= k;
			cnt++;
		}
		else {
			res /= (ans[k] + 1);
			ans[k] -= cnt;
			cnt = 0;
			res *= (ans[k] + 1);
			k++;
		}
	}
	if (cnt != 0) {
		res /= (ans[k] + 1);
		ans[k] -= cnt;
		cnt = 0;
		res *= (ans[k] + 1);
	}
}

map<int, int> prod(vector<int>& a) {
	map<int, int> ans;
	for(int n: a) {
		for(int k = 2; k <= n;) {
			if (n % k == 0) {
				n /= k;
				ans[k]++;
			}
			else
				k++;
		}
	}
	return ans;
}

int32_t main() {
	tool();
	int n; 
	cin >> n;
	vector<int> a(n);
	for(int& val: a)
		cin >> val;
	map<int, int> ans = prod(a);
	int res = 1;
	for (auto i = ans.begin(); i != ans.end(); i++) {
		cout << i->first << " -> " << i->second << "\n"; 
		res *= (i->second + 1);
	}
	cout << "Number of divisor of product of array -> " << res << "\n";
	// int q; cin >> q;
	// for(int i = 0; i < q; i++) {
	// 	int x, y;
	// 	cin >> x >> y;
	// 	if (x == 1) {
	// 		addx(y, ans, res);
	// 	}
	// 	else {
	// 		removex(y, ans, res);
	// 	}
	// 	cout << "Number of divisor of product of array -> " << res << "\n";
	// }
	return 0;
}