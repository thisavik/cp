#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v, vector<bool>& added)
{
  cout << "subset : ";
  for(int i = 0; i < added.size(); i++)
    if(added[i]) cout << v[i] << " ";
  cout << "\n";
}

// Approach-1
void printAllSubset(vector<int>& v, int& n, vector<bool>& added, int idx) 
{
  if(idx == n)
  {
    printVector(v, added);
    return;
  }
  added[idx] = true;
  printAllSubset(v, n, added, idx+1);
  added[idx] = false;
  printAllSubset(v, n, added, idx+1);
}

// Approach-2
void printAllSubset2(vector<int>& v, int& n, int idx, vector<int>& subset)
{
  cout << "subset : ";
  for(auto& val: subset)
    cout << val << " ";
  cout << "\n";
  for(int i = idx; i < n; i++) 
  {
    subset.push_back(v[i]);
    printAllSubset2(v, n, i+1, subset);
    subset.pop_back();
  }
}

int32_t main()
{
  vector<int> v {1, 2, 3};
  int n = v.size();
  // vector<bool> added(n, false);
  // printAllSubset(v, n, added, 0);
  vector<int> subset;
  printAllSubset2(v, n, 0, subset);
  return 0;
}