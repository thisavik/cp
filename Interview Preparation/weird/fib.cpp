#include <iostream>
#include <vector>

using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define rep(i, n) for(int i = 0; i < n; i++)
#define range(i, a, b) for(int i = a; i <= b; i++)

#define int long long
const int mod = (int)1e9+7;

void tool();
vii mul(vii &m1, vii &m2);
vii power(vii &p, int n);
void print(vii &mat);

int solve(int a, int b, int n)
{
    if(n == 1)
        return b;
    vii p = {{1, 1}, {1, 0}};
    vii res = power(p, n-2);
    return (res[0][0]*b + res[0][1]*a) % mod;
}

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        cout << solve(a, b, n) << "\n";
    }
    return 0;
}

void tool() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
                ans[k][i] %= mod;
            }
        }
    }
    return ans;
}

vii power(vii &p, int n)
{
    vii res(2, vi(2, 1));
    while(n > 0)
    {
        if(n&1)
            res = mul(res, p);
        p = mul(p, p);
        n >>= 1;
    }
    return res;
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