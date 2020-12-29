#include <iostream>
#include <vector>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

int32_t main() {
    tool();
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(auto& v: grid)
        for(auto& i: v) {
            char ch;
            cin >> ch;
            i = (ch -'C')^1;
        }
    int ans = 0;
    int my = 0, mx = 0, m = 0, t = 0;
    // case 1-3
    for(int i = 0; i < n; i++) {
        int m = 0;
        for(int j = 0; j < n; j++)
            if(grid[j][i])
                m++;
        my = max(m, my);
        if(m == 0)
            mx = max(mx, t), t = 0;
        else
            t++;
    }
    mx = max(t, mx);
    ans = min(mx, my);

    mx = 0, my = 0, t = 0;
    // case 1-3
    for(int i = 0; i < n; i++) {
        int m = 0;
        for(int j = 0; j < n; j++)
            if(grid[i][j])
                m++;
        my = max(m, my);
        if(m == 0)
            mx = max(mx, t), t = 0;
        else
            t++;
    }
    mx = max(t, mx);
    ans = max(ans, min(mx, my));
    cout << ans << "\n";  
    return 0;
}