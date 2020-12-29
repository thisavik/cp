#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("C://git//cp//input.txt", "r", stdin);
    freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

#define maxN 1001
int n, m;
bool grid[maxN][maxN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int r, int c)
{
    return !(r < 1 || r > n || c < 1 || c > m || !grid[r][c]);
}
int dfs();
void dfs(int, int);

int32_t main()
{
    tool();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            // # -> 0, . -> 1
            grid[i][j] = (ch == '.') ? 1 : 0; 
        }
    cout << dfs();
}

int dfs()
{
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            if(grid[i][j]) {
                dfs(i, j);
                cnt++;
            }
    }
    return cnt;
}

void dfs(int r, int c)
{
    grid[r][c] = 0;

    for(int i = 0; i < 4; i++)
    {
        int rNew = r + dx[i];
        int cNew = c + dy[i];
        if(isValid(rNew, cNew))
            dfs(rNew, cNew);
    }
}