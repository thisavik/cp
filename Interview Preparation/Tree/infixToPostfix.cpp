#include <bits/stdc++.h>
using namespace std;
#define int long long
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

string convFromInfixTOPostfix(string& inFix) {
	stack<char> st;
	st.push('N');
	string s = "";
	for (int i = 0; i < inFix.size(); i++) {
		if (inFix[i] == '(')
			st.push('(');
		else {
			if (inFix[i] == '#') {
				s += inFix[i];
			} else if (inFix[i] == ')') {
				while (st.top() != 'N' && st.top() != '(') {
					s += st.top();
					st.pop();
				}
				if (st.top() == '(') {
					st.pop();
				}
			}
		}
	}
	while (st.top() != 'N') {
		s += st.top();
		st.pop();
	}
	return s;
}

void solve() {
	string inFix;
	cin >> inFix;
	string postFix = convFromInfixTOPostfix(inFix);
	cout << postFix << endl;
}

int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}