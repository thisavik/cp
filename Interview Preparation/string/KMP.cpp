#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void tool()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

void long_Pref_Suff(string &s, vector<int> &lps)
{
	lps[0] = 0;
	int i = 1, j = 0;
	while (i < lps.size())
	{
		if (s[i] == s[j])
		{
			lps[i] = j + 1;
			i++, j++;
		}
		else
		{
			j == 0 ? i++ : j = lps[j - 1];
		}
	}
}

bool KMP(string &s, string &p, vector<int> &lps)
{
	bool flag = false;
	int i = 0, j = 0;
	while (i < s.size())
	{
		if (s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j == 0 ? i++ : j = lps[j - 1];
		}
		if (j == p.size())
		{
			flag = true;
			break;
		}
	}
	return flag;
}

int repeatedStringMatch(string A, string B)
{
	int n = A.size();
	int i = 0, j = 0;
	while (i < B.size())
	{
		if (A[i] == B[j])
		{
			i++, j++;
		}
		else
		{
			j++;
		}
		if (j == n)
		{
			break;
		}
	}
	B = A.substr(0, j - i) + B;
	vector<int> lps(B.size());
	long_Pref_Suff(B, lps);
	for (int val : lps)
		cout << val << " ";
	cout << "\n";

	return -1;
}
void solve()
{
	string s, p;
	cin >> s >> p;
	cout << repeatedStringMatch(s, p);
	// vector<int> lps(p.size());
	// long_Pref_Suff(p, lps);
	// for(int val: lps)
	// 	cout << val << " ";
	// cout << "\n";

	// cout << boolalpha << KMP(s, p, lps) << "\n";
}

int32_t main()
{
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}