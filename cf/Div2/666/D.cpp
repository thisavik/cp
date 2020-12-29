#include <bits/stdc++.h>
using namespace std;

#define int long long

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

void solve()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> a(n);
    for(int& val : a)
        cin >> val, pq.push(val);
    int T = 0, HL = 0;
    while(!pq.empty())
    {
        T = pq.top(), pq.pop();
        if(!pq.empty())
        
    }
}

int32_t main()
{
   tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}