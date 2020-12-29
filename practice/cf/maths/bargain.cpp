#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define int int64_t

int addMod(vector<int> v)
{
    int res = 0;
    for(int val: v)
        res = ((res % mod) + (val % mod)) % mod;
    return res;
}

int mulMod(vector<int> v)
{
    int64_t res = 1;
    for(int val: v)
        res = ((res % mod) * (val % mod)) % mod;
    return res;
}

int32_t main()
{
    string str;
    cin >> str;
    int n = str.size();
    vector<int> left(n, 1), right(n, 0);
    for(int i = 1; i < n; i++)
    {
        left[i] = mulMod({left[i-1], 10});
        right[i] = addMod({mulMod({i, left[i-1]}), right[i-1]});
    }
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int idx = n-i-1;
        int l = mulMod({i*(i+1)/2, left[idx], str[i]-'0'});
        int r = mulMod({right[idx], str[i]-'0'});
        sum = addMod({sum, l, r});
    }
    cout << sum;
}