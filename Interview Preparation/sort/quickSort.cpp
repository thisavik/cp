#include <iostream>
using namespace std;

int partition(int *a, int s, int e)
{

  // taking pivot as last element of the segement
  int pivot = a[e];

  /*
  for randomized partition, we generate pivot index by randomized function

  pivotIndex = s + rand()%(e-s+1);
  then swap it with end index
  swap(a[pivotIndex], a[e]);
  pivot = a[e];

  */

  // set the index of the element which is greater than pivot and appear to the left most side in segement
  int pIndex = s;

  for (int i = s; i < e; i++)
  {

    /*
   if element at i is less than pivot then we will swap it with index with greater value i.e. pIndex and increment the pIndex by one to mantain its property to contain the index of left most greater element than pivot(p[e]) & at last we will swap pIndex with pivot
  */
    if (a[i] <= pivot)
    {
      swap(a[i], a[pIndex]);
      pIndex++;
    }
  }
  swap(a[pIndex], a[e]);
  return pIndex;
}

void Util(int *a, int s, int e)
{
  if (s < e)
  {
    int pIndex = partition(a, s, e);
    Util(a, s, pIndex - 1);
    Util(a, pIndex + 1, e);
  }
}

void q_sort(int *a, int *b)
{
  int n = 0;
  for (int *x = a; x != b; x++)
    n++;
  Util(a, 0, n - 1);
}

int main()
{
  int a[7] = {10, 80, 30, 90, 40, 50, 70};
  q_sort(a, a + 10);
  for (int val : a)
    cout << val << " ";
}