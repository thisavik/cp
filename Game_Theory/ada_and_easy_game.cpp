// https://www.spoj.com/problems/ADAGAME2/

#include <iostream>
#include <unordered_set>
#include <cstring>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C://git//cp//input.txt", "r", stdin);
    freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

int grundy[(int)1e6 + 1];

int calculateMex(unordered_set<int> &S)
{
    int Mex = 0;
    while (S.find(Mex) != S.end())
        Mex++;
    return Mex;
}

void calculateGrundy(int n, int *rule, int m)
{
    for (int i = 1; i <= n; i++)
    {
        unordered_set<int> S;
        for (int j = 0; j < m; j++)
        {
            if (i >= rule[j])
            {
                int x = i - rule[j];
                if (grundy[x] != -1)
                    S.insert(grundy[x]);
                else
                    S.insert(x);
            }
        }
        grundy[i] = calculateMex(S);
    }
}

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while (t--)
    {
        memset(grundy, -1, sizeof grundy);
        grundy[0] = 0;
        int n, m, mx = -1e9;
        cin >> n >> m;
        int rule[m], pile[n];
        rep(i, m)
        {
            cin >> rule[i];
        }
        rep(i, n)
        {
            cin >> pile[i];
            mx = max(pile[i], mx);
        }
        calculateGrundy(mx, rule, m);
        int ans = 0;
        rep(i, n)
        {
            ans ^= grundy[pile[i]];
        }
        if (ans != 0)
            cout << "Ada\n";
        else
            cout << "Vinit\n";
    }
    return 0;
}

/*
6
4 1
2
1 2 3 4
4 2
1 2
4 4 3 5
1 3
2 3 5
20
2 2
1 3
4 7
5 5
1 2 7 13 15
10 20 30 40 50
1 2
1 2
98997
*/