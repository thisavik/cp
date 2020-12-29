#include <iostream>
#include <stack>

using namespace std;

int32_t main()
{
    tool();
    int n;
    cin >> n;
    int a[n];
    for(int& val : a)
        cin >> val;
    int ans[n];
    stack<int> stk;
    for(int i = n-1; i >= 0; i--)
    {
        while(!stk.empty() && stk.top() <= a[i])
            stk.pop();
        if(stk.empty())
            ans[i] = -1;
        else
            ans[i] = stk.top();
        stk.push(a[i]);
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}