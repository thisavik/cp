#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &v, int l, int mid, int r) 
{
  int i = l, j = mid+1, k = 0;
  vector<int> temp(r-l+1);
  while(i <= mid && j <= r) 
  {
    if(v[i] <= v[j])
      temp[k++] = v[i++];
    else
      temp[k++] = v[j++];
  }
  while(i <= mid)
    temp[k++] = v[i++];
  while(j <= r)
    temp[k++] = v[j++];
  for(k = 0; k < temp.size(); k++)
    v[l + k] = temp[k];
}

void mergeSortRec(vector<int> &v, int l, int r) 
{
  if(l < r)
  {
    int mid = l + (r - l)/2;
    mergeSortRec(v, l, mid);
    mergeSortRec(v, mid + 1, r);
    merge(v, l, mid, r);
  }
}

void mergeSort(vector<int> &v)
{
  int l = 0, r = v.size() - 1;
  mergeSortRec(v, l, r);
}

int32_t main()
{
  vector<int> v {7, 7, 6, 2, 4, 3, 8, 2, 1};
  mergeSort(v);
  for(const int i: v)
    cout << i << " ";
  cout << "\n";
  return 0;
}