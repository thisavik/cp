// https://leetcode.com/problems/unique-paths-ii/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>&);

void print(vector<vector<int>> grid) {
    for(auto v: grid) {
        for(int& val: v)
            cout << val << " ";
        cout << "\n";
    }
    cout << "\n";
}

int32_t main() {
    tool();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(auto& v: grid)
        for(int& val: v)
            cin >> val;
    print(grid);
    cout << uniquePathsWithObstacles(grid);
    return 0;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = INT_MAX;
        for(int i = 0; i < m; i++)
            if(obstacleGrid[i][0] == 0)
                dp[i][0] = 1;
            else
                break;
        for(int i = 0; i < n; i++)
            if(obstacleGrid[0][i] == 0)
                dp[0][i] = 1;
            else
                break;
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                if(obstacleGrid[i][j] == 0)
                    dp[i][j] = (dp[i-1][j] != INT_MAX ? dp[i-1][j] : 0) +
                                (dp[i][j-1] != INT_MAX ? dp[i][j-1] : 0);
        print(dp);
        return (dp[m-1][n-1] != INT_MAX ? dp[m-1][n-1] : 0);
    }