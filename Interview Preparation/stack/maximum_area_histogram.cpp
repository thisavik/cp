#include <iostream>
#include <stack>

using namespace std;

int32_t main()
{
    tool();
    int n;
    cin >> n;
    int a[n];
    for (int &val : a)
        cin >> val;
    int ans = 0, i = 0, len, tp;
    stack<int> stk;
    while (i < n || !stk.empty())
    {
        if (i < n && (stk.empty() || a[i] >= a[stk.top()]))
        {
            stk.push(i);
            i++;
        }
        else
        {
            tp = a[stk.top()];
            stk.pop();
            len = stk.empty() ? i : i - stk.top() - 1;
            ans = max(ans, tp * len);
        }
    }
    cout << ans;
    return 0;
}