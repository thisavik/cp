/*
sample test case :
11
15 30 21 15 30 15 30 25 15 15 21
1 1 2 2 3 3 4 4 5 5 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C://git//cp//input.txt", "r", stdin);
    freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

#define maxN (int)1e5 + 1
int n;
vector<int> LPS(vector<pair<int, int>>);

int par[maxN], value[maxN];
void solve(int &, int &);

int32_t main()
{
    tool();
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> value[i];
    par[1] = -1;
    for (int i = 2; i <= n; i++)
        cin >> par[i];
    int len = 0, end = INT32_MAX;
    solve(len, end);
    cout << len << " " << end;
}

void solve(int &len, int &end)
{
    // make root node parent to -(n+!)
    for(int i = 1; i <= n; i++)
        if(par[i] == -1)
        {
            par[i] -= n;
            break;
        }
    // preprocessing to check child in parent array
    // partent of node which is none negative is leaf node
    for(int i = 1; i <= n; i++)
        if(par[i] != -(n+1))
            par[par[i]] = -abs(par[par[i]]);

    for(int i = 1; i <= n; i++)
    {
        // do nothing when we encounter none leaf node
        if(par[i] < 0)
            continue;
        // else create path with information (node, value)
        vector<pair<int, int>> path;
        int p = i;
        // create path (leaf to root)
        while(p <= n)
        {
            path.push_back({p, value[p]});
            p = abs(par[p]);
        }
        
        // change path (root to leaf)
        reverse(path.begin(), path.end());
        // use lps to find longest prefix palindrome
        // lps.back() will contain length of longest prefix palindrome 'len'
        // and at index of lps.back()-1 contain node value means 'end' here
        vector<int> lps = LPS(path);
        // update len and end as per condition
        if(len == lps.back())
            end = min(end, path[len-1].first);
        else if(len < lps.back())
        {
            len = lps.back();
            end = path[len-1].first;
        }
    }
}

vector<int> LPS(vector<pair<int, int>> path)
{
    int n = path.size();
    // put dummy pair to avoid same character 
    path.push_back({n+1, INT32_MAX});
    // the put path in reverse order
    for (int i = n - 1; i >= 0; i--)
        path.push_back(path[i]);
    n = path.size();
    // create lps for new path using KMP
    vector<int> lps(n, 0);
    int i = 1, j = 0;
    while (i < n)
    {
        // according to value(second) we have to check palindrome
        if (path[i].second == path[j].second)
            lps[i] = j + 1, j++, i++;
        else
            j == 0 ? i++ : j = lps[j - 1];
    }
    return lps;
}
