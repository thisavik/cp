#include <iostream>
#include <vector>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

vector<int> LPS(string &s)
{
    int n = s.size();
    vector<int> lps(n, 0);
    int i = 1, j = 0;
    while(i < n)
    {
        if(s[i] == s[j])
            j++, lps[i] = j, i++;
        else
            (j == 0) ? i++ : j = lps[j-1];
    }
    return lps;
}

bool isSubstring(string &s1, string &s2)
{
    vector<int> lps = move(LPS(s2));
    int i = 0, j = 0;
    while(i < s1.size())
    {
        if(s1[i] == s2[j])
            i++, j++;
        else
            (j == 0) ? i++ : j = lps[j-1];
        if(j == s2.size())
            return true;
    }
    return false;
}

bool checkRotation(string &s1, string &s2)
{
    if(s1.size() != s2.size())
        return false;
    s1 += s1;
    return isSubstring(s1, s2);
}

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while(t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << boolalpha << checkRotation(s1, s2) << "\n";
    }

}

