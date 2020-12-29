#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int input[n];
    for(int& val : input)
        cin >> val;
    if(n == 1)
    {
        cout << 0 << "\n";
        return;
    }
    if(input[0] == 0)
    {
        cout << -1 << "\n";
        return;
    }
    int cur = input[0];
    int next = input[0];
    int jump = 1;
    for(int i = 1; i < n-1; i++)
    {
        next = max(next, i + input[i]);
        cur--;
        if(cur == 0)
        {
            jump++;
            if(i >= next)
            {
                cout << -1 << "\n";
                return;
            }
            cur = next - i;
        }        
    }
    cout << jump << "\n";
}

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int& val : a)
            cin >> val;
        int dp[n];
        fill(dp, dp+n, (int)1e9);
        dp[0] = 0;
        if(a[0] == 0)
        {
            cout << -1 << "\n";
            continue;
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(j + a[j] >= i)
                    dp[i] = min(dp[i], dp[j]+1);
            }
        }
        for(int i = 0; i < n; i++)
            cout << dp[i] << " ";
        cout << "\n";
    }
    return 0;
}