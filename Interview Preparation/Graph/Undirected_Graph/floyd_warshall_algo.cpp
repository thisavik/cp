#include <iostream>

using namespace std;
#define rep1(i, n) for (int i = 0; i < n; i++)
#define rep2(i, a, b) for (int i = a; i < b; i++)
void solve()
{
    int n;
    cin >> n;
    int graph[101][101];
    rep1(i, n)
    {
        rep1(j, n)
        {
            cin >> graph[i][j];
        }
    }
    int dist[101][101];
    rep1(i, n)
    {
        rep1(j, n)
        {
            dist[i][j] = graph[i][j];
        }
    }
    rep1(k, n)
    {
        rep1(i, n)
        {
            rep1(j, n)
            {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    rep1(i, n)
    {
        rep1(j, n)
        {
            if(dist[i][j] == 1e7)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
int32_t main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}