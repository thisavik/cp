#include <iostream>
#include <vector>
#include <map>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &val : a)
    {
        cin >> val;
    }
    map<int, int> m;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < n; i++)
    {

        sum += a[i];
        if (sum == k)
        {
            maxLen = i + 1;
        }

        if (m.find(sum) == m.end())
            m[sum] = i;

        if (m.find(sum - k) != m.end())
        {
            maxLen = max(maxLen, i - m[sum - k]);
        }
    }
    cout << maxLen << "\n";
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