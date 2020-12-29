#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> in(n), res(n);
    for(int &val : in)
        cin >> val;
    stack<int> s;
    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && in[s.top()] <= in[i])
            s.pop();
        res[i] = (s.empty()) ? (i+1) : (i-s.top());
        s.push(i);
    }
    for(int val : res)
        cout << val << " ";
    cout << "\n";
}

int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}

/*
2
7
100 80 60 70 60 75 85
6
10 4 5 90 120 80
*/