#include <iostream>
#include <vector>

using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define rep(i, n) for(int i = 0; i < n; i++)

void print(vii &m);
vii mul(vii &m1, vii &m2);

int32_t main()
{
    tool();
    int n, m, o;
    cin >> n >> m >> o;
    vii m1(n, vi(m, 0));
    vii m2(m, vi(o, 0));
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> m1[i][j];
        }
    }
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> m2[i][j];
        }
    }
    vii ans = mul(m1, m2);
    print(ans);
}

void print(vii &mat)
{
    rep(i, mat.size())
    {
        rep(j, mat[0].size())
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

vii mul(vii &m1, vii &m2)
{
    int n = m1.size(), m = m1[0].size(), o = m2[0].size();
    vii ans(n, vi(o, 0));
    rep(k, n)
    {
        rep(i, o)
        {
            rep(j, m)
            {
                ans[k][i] += m1[k][j]*m2[j][i];
            }
        }
    }
    return ans;
}