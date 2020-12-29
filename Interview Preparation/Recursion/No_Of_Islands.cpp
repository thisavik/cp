#include <iostream>
#include <vector>

using namespace std;

void printGrid(vector<vector<int>>& grid) {
    for(auto& v: grid) {
        for(auto& val: v)
            cout << val << " ";
        cout << '\n';
    }
    cout << "\n";
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isSafe(vector<vector<int>>& grid, int r, int c) {
    return !(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0');
}

void convert1to0(vector<vector<int>>& grid, int r, int c) {
    cout << r << " " << c << "\n";
    grid[r][c] = '0';

    for(int i = 0; i < 4; i++) {
        int rNew = r + dx[i];
        int cNew = c + dy[i];
        if(isSafe(grid, rNew, cNew)) {
            convert1to0(grid, rNew, cNew);
        }
    }
}

int noOfIsland(vector<vector<char>>& grid) {
    int cnt = 0;
    for(int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j] == '1') {
                convert1to0(grid, i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(auto& v: grid)
        for(auto& val: v)
            cin >> val;
    printGrid(grid);
    cout << noOfIsland(grid) << "\n";
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--) 
        solve();
    return 0;
}