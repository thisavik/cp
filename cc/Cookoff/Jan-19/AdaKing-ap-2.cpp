#include <bits/stdc++.h>
using namespace std;

int cntPlace(int r, int c, int k)
{
    /*
    pair<int, int> ll(r-k < 1 ? 1 : r-k, c-k < 1 ? 1 : c-k);
    pair<int, int> lr(r-k < 1 ? 1 : r-k, c+k > 8 ? 8 : c+k);
    pair<int, int> ul(r+k > 8 ? 8 : r+k, c-k < 1 ? 1 : c-k);
    pair<int, int> ur(r+k > 8 ? 8 : r+k, c+k > 8 ? 8 : c+k);
    int l = lr.second - ll.second + 1;
    int b = ul.first - ll.first + 1;
    return l*b;
    */
    int lr = r-k < 1 ? 1 : r-k, ur = r+k > 8 ? 8 : r+k, lc = c-k < 1 ? 1 : c-k, rc = c+k > 8 ? 8 : c+k;
    return (ur -lr+1)*(rc-lc+1);
}
void solve()
{
    int r, c, k;
    cin >> r >> c >> k;
    cout << cntPlace(r, c, k) << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
