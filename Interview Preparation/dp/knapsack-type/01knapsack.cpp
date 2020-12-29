#include <bits/stdc++.h>
using namespace std;

// Recursive Approach

int knapsackRecursive(int wt[], int val[], int w, int n)
{
  // base case
  if (w == 0 || n == 0)
  {
    return 0;
  }

  // choice case
  if (wt[n - 1] <= w)
  {
    return max(val[n - 1] + knapsackRecursive(wt, val, w - wt[n - 1], n - 1), knapsackRecursive(wt, val, w, n - 1));
  }
  else
  {
    return knapsackRecursive(wt, val, w, n - 1);
  }
}

// Memoized code or DP code

int dp[1001][1001];

int knapsackMemoized(int wt[], int val[], int w, int n)
{
  // base case
  if (w == 0 || n == 0)
  {
    return 0;
  }

  // if for that n, w problem we already have calculated the result
  if (dp[n][w] != -1)
  {
    return dp[n][w];
  }

  // choice code
  if (wt[n - 1] <= w)
  {
    return dp[n][w] = max(val[n - 1] + knapsackMemoized(wt, val, w - wt[n - 1], n - 1), knapsackMemoized(wt, val, w, n - 1));
  }
  else
  {
    return dp[n][w] = knapsackMemoized(wt, val, w, n - 1);
  }
}

// Top-Down code(iterative version of memoized recursive code)

int knapsackTopDown(int wt[], int val[], int w, int n)
{
  int dp[n + 1][w + 1];
  // here dp[i][j] represent a sub-problem created during solving original problem
  // initialisation (same as base case in memoized)

  // for w=0 dp[i][0]=0
  for (int i = 0; i < n + 1; i++)
  {
    dp[i][0] = 0;
  }
  // for n=0 dp[0][i]=0
  for (int i = 0; i < w + 1; i++)
  {
    dp[0][i] = 0;
  }

  // choice code
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < w + 1; j++)
    {
      if (wt[i - 1] <= j)
      {
        dp[i][j] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]); // same as return statement
      }
      else
      {
        dp[i][j] = dp[i - 1][w]; // same as return statement
      }
    }
  }
  return dp[n][w]; // finally our answer is in dp[n][w] so return it
}

int main()
{
  memset(dp, -1, sizeof(dp));
}
