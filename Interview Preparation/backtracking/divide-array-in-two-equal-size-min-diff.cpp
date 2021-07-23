#include <bits/stdc++.h>

using namespace std;

void helper(int &n, int idx, int curSum, int totalAdded, int &minDiff, int &sum, vector<int> &arr, vector<int> &added, vector<int> &sol)
{
  if(idx == n)
    return;

  // add that index
  curSum += arr[idx];
  added[idx] = true;
  totalAdded++;
  if(totalAdded == n/2) 
  {
    if(abs(sum-2*curSum) < minDiff) 
    {
      cout << sum-curSum << " " << curSum << "\n";
      minDiff = abs(sum-2*curSum);
      for(int i = 0; i < n; i++)
        sol[i] = added[i];
    }
  } else {
    // solution with adding this index
    helper(n, idx+1, curSum, totalAdded, minDiff, sum, arr, added, sol);
  }

  // remove that index for backtrack
  added[idx] = false;
  curSum -= arr[idx];
  totalAdded--;
  helper(n, idx+1, curSum, totalAdded, minDiff, sum, arr, added, sol);
}

void solve(vector<int> &arr) 
{
  int n = arr.size();
  vector<int> added(n, false);
  vector<int> sol(n, false);
  int sum = 0;
  for(int &val: arr)
    sum += val;
  int minDiff = INT_MAX;
  helper(n, 0, 0, 0, minDiff, sum, arr, added, sol);
  for(int i = 0; i < n; i++)
    if(sol[i])
      cout << arr[i] << " ";
  cout << "\n";
  for(int i = 0; i < n; i++)
    if(!sol[i])
      cout << arr[i] << " ";
  cout << "\n";
  cout << minDiff << "\n";
}

int32_t main()
{
  vector<int> arr {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
  solve(arr);
  return 0;
}
