#include <iostream>
#include <vector>
#include <set>

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
    vector<int> a(n);
    for(int& val: a)
        cin >> val;
	set<int> ans;
	set<int> cur;
	cur.insert(0);
    for(int& val: a) {
		set<int> temp;
		for(int x: cur) {
			temp.insert(x|val);
			ans.insert(x|val);
		}
		temp.insert(val);
		ans.insert(val);
		cur = temp;
	}
	if(ans.size() == n*(n+1)/2)
		cout << "YES\n";
	else 
		cout << "NO\n";
}

int32_t main() {
	tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}


// brute force
    // for(int i=0; i<n; i++) {
	// 	int x = 0;
	// 	for(int j=i; j<n; j++) {
	// 		x |= a[j];
	// 		s.insert(x);
	// 	}
	// }
	// cout << "\n";
	// if(!flag)
	// 	cout << "YES\n";
	// else 
	// 	cout << "NO\n";