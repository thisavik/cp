#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> in(n), res(n);
    int mx = 0;
    for (int &val : in)
        cin >> val, mx = max(mx, val);
    int fre[mx + 1] = {0};
    for (int val : in)
        fre[val]++;
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        // if current element freq is greater than stack top then that elt is answer for
        // that stack top
        while (!s.empty() && fre[in[s.top()]] < fre[in[i]])
            res[s.top()] = in[i], s.pop();
        // in the end push position in stack
        s.push(i);
    }
    // all elements at the end don't have and answer so keep -1
    while (!s.empty())
        res[s.top()] = -1, s.pop();
    for (int val : res)
        cout << val << " ";
    return 0;
}

/*
7
1 1 2 3 4 2 1
*/