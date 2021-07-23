#include <bits/stdc++.h>

using namespace std;

auto window(vector<int> &v, int k)
{
    vector<int> ans;
    deque<int> dq;
    // for 1st k element
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && v[i] >= v[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    ans.push_back(dq.front());
    // for next n - k element
    for (int i = k; i < v.size(); i++)
    {
        while(!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while(!dq.empty() && v[i] >= v[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        ans.push_back(dq.front());
    }
    return ans;
}

int32_t main()
{
    vector<int> v{1, 2, 3, 1, 4, 5, 2, 3, 6};
    vector<int> ans = window(v, 3);
    for(int val: ans)
        cout << v[val] << " ";
    cout << "\n";
    return 0;
}