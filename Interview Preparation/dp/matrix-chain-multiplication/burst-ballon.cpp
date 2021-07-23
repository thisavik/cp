#include <bits/stdc++.h>

using namespace std;

// Top-Down
int helperRec(int i, int j, vector<int> &nums, vector<vector<int>> &dp) 
{
  // if there are no ballon in range
  if(i > j)
    return 0;
  if(dp[i][j] != -1)
    return dp[i][j];
  int maxCoin = INT_MIN;
  for(int k = i; k <= j; k++) 
  {
    int coin = 
      // solve for (i, k-1) ballons
      helperRec(i, k-1, nums, dp) + 
      // solve for (k+1, j) ballons
      helperRec(k+1, j, nums, dp) + 
      // add cost of breaking Kth ballon
      (i == 0 ? 1 : nums[i-1]) * nums[k] * (j+1 == nums.size() ? 1 : nums[j+1]);
    maxCoin = max(maxCoin, coin);
  }
  return dp[i][j] = maxCoin;
}

int helper(vector<int> &nums) 
{
  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(n, -1));
  return helperRec(0, n-1, nums, dp);
}

// Bottom-Up
int helper2(vector<int> &nums)
{
  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));

  for(int len = 1; len <= n; len++) 
  {
    for(int i = 0; i+len-1 <= n-1; i++) 
    {
      int j = i+len-1;
      dp[i][j] = 0;
      for(int k = i; k <= j; k++)
      {
        dp[i][j] = max(dp[i][j], 
          (k == 0 ? 0 : dp[i][k-1]) + 
          (k+1 == nums.size() ? 0 : dp[k+1][j]) + 
          (i == 0 ? 1 : nums[i-1]) * nums[k] * (j+1 == nums.size() ? 1 : nums[j+1])
        );
      }
    }
  }
  return dp[0][n-1];
}
int32_t main()
{
  int n = 4;
  // cin >> n;
  vector<int> nums {3, 1, 5, 8};
  // for(auto &val: nums)
  //   cin >> val;
  cout << helper2(nums);
}