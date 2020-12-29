#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define rep(i, n) for(int i = 0; i < n; i++)
#define range(i, a, b) for(int i = a; i <= b; i++)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

bool isPossible(vector<int> &A, int &x, int &p, int &k)
{
    if((p < k && A[p] < x) || (p > k && A[p] > x))
        return false;
    return true;
}

int solve()
{
    int n, x, p, k;
    cin >> n >> x >> p >> k; p--, k--;
    vector<int> A(n, 0);
    for(int &val: A)
        cin >> val;
    sort(A.begin(), A.end());
    if(A[p] == x)
        return 0;
    if(!isPossible(A, x, p, k))
    {
        return -1;
    }
    if(x < A.front())
        return p+1;
    if(x > A.back())
        return n-p;
    int l = lower_bound(A.begin(), A.end(), x)-A.begin();
    int r = upper_bound(A.begin(), A.end(), x)-A.begin();
    cout << l << " " << r << "\n";
    if(p == k)
        return (x > A[k] ? l-p : p-r+1);
    if(p > k)
        return l-p;
    return p-r+1;
}

int32_t main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--)
    {
        int ans = solve();
        cout << ans << "\n";
    }
    return 0;
}

/*
6
5 4 3 4
4 9 7 0 8
2 25 1 2
100 20
7 4 3 4
1 1 2 2 4 4 4 
9 10 3 5
1 2 3 4 5 6 7 8 9
8 15 3 3
2 4 6 8 10 12 14 16
8 5 8 8
2 4 6 8 10 12 14 16
*/