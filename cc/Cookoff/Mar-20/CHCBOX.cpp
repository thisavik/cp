#include <bits/stdc++.h>
using namespace std;
void tool() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void solve()
{
    int n;
    cin >> n;
    int a[n], mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    vector<int> v;
    int cnt = 0;
    // pushing the size of sub-array which does not contain the maximum element
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mx)
        {
            v.push_back(cnt);
            cnt = 0;
        }
        else
            cnt++;
    }
    // since array is circular so if we have sub-array at last of array the it should be added in 1st sub-array that we got
    if (cnt != 0)
        v[0] += cnt;
    cnt = 0;
    // finally count the number of sub-array that satisfy the condition of rotation if its minimum size should be n/2 for contribution in answer
    for (int i = 0; i < v.size(); i++)
        cnt += max(v[i] - n / 2 + 1 , 0);
    cout << cnt << "\n";
}
int main()
{
    tool();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
