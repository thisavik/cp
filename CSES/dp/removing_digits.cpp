#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1e6+1; 

int dp[maxN];

vector<int> digits(int n)
{
    vector<int> digits;
    while(n > 0)
    {
        digits.push_back(n%10);
        n /= 10;
    }
    return digits;
}

int32_t main()
{
    int n;
    cin >> n;
    dp[0] = 0;
    for(int i = 1; i < 10; i++)
        dp[i] = 1;
    for(int i = 10; i <= n; i++)
    {
        vector<int> digit = digits(i);
        dp[i] = INT32_MAX;
        for(int val: digit)
        if(val != 0)
            dp[i] = min(dp[i], 1 + dp[i-val]);
    }
    cout << dp[n];
}

/*
// greedy solution
int ans = INT32_MAX, cnt = 0;
while(n)
{
    int temp = n, mx = 0;
    while(temp)
    {
        mx = max(mx, temp%10);
        temp /= 10;
    }
    n -= mx;
    cnt++;
}
cout << cnt;
*/