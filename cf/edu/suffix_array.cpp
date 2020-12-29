// we have given a string s
// we have to sort all the suffix in lexicographical order
// for each suffix we have create an array which conatin starting index of suffix
// this will represent our desire result

// e.g.
// s = "ababba" ->012345
// ""       -> 6
// "a"      -> 5
// "ababba" -> 0
// "abba"   -> 2
// "ba"     -> 4
// "babba"  -> 1
// "bba"    -> 3

#include <bits/stdc++.h>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

int32_t main()
{
    tool();
    string s;
    cin >> s;
    s += '$';
    int n = s.size();
    vector<int> p(n), c(n);
    {
        // k = 0
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++)
            p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1; i < n; i++)
            if(a[i].first == a[i-1].first)
                c[p[i]] = c[p[i-1]];
            else
                c[p[i]] = c[p[i-1]] + 1;
    }
    int k = 0;
    while((1 << k) < n)
    {
        // k -> k+1
        vector<pair<pair<int, int>, int>> a(n);
        for(int i = 0; i < n; i++)
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++)
            p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1; i < n; i++)
            if(a[i].first == a[i-1].first)
                c[p[i]] = c[p[i-1]];
            else
                c[p[i]] = c[p[i-1]] + 1;
        k++;
    }
    for(int i = 0; i < n; i++)
        cout << p[i] << " " << s.substr(p[i], n-p[i]) << "\n";
    cout << "\n";
}