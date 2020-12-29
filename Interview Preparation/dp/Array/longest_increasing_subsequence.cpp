#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

/*
vector<int> LIS(vector<int>& in)
{
    int n = in.size();
    vector<int> lis, pos;
    for(int i = 0; i < n; i++)
        lis.push_back(1), pos.push_back(i);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(in[i] >= in[j] && lis[i] < lis[j]+1)
            {
                lis[i] = lis[j]+1, pos[i] = j;
            }
        }
    }
    int idx = max_element(lis.begin(), lis.end()) - lis.begin();
    vector<int> ans;
    while(idx != pos[idx])
    {
        ans.push_back(in[idx]);
        idx = pos[idx];
    }
    ans.push_back(in[idx]);
    reverse(ans.begin(), ans.end());
    return ans;
}
*/

int LIS(vector<int>& in)
{
    int n = in.size();
    int dp[n];
    dp[0] = in[0];
    int ans = 1;
    for(int i = 1; i < n; i++)
    {
        int idx = upper_bound(dp, dp+ans, in[i])-dp;
        if(idx < 0)
            idx = 0;
        dp[idx] = in[i];
        if(idx == ans)
            ans++;
    }
    return ans;
}

int32_t main()
{
    tool();
    int n;
    cin >> n;
    vector<int> in(n);
    for(int& val : in)
        cin >> val;
    cout << LIS(in);
    // vector<int> ans = LIS(in);
    // for(int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";
    return 0;
}