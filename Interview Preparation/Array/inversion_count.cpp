#include <iostream>

using namespace std;

int merge(int *arr, int *temp, int s, int mid, int e)
{
    int i = s; // start of left half
    int j = mid; // start of right half
    int k = s; // start of merge array
    int inv = 0;
    while(i <= mid-1 && j <= e)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++], inv += (mid-i);
    }
    while(i <= mid-1)
        temp[k++] = arr[i++];
    while(j <= e)
        temp[k++] = arr[j++];
    for(int i = s; i <= e; i++)
        arr[i] = temp[i];
    return inv;
}

int inversion_cnt(int *arr, int *temp, int s, int e)
{
    if(s < e)
    {
        int mid = (s+e)/2;
        int inv1 = inversion_cnt(arr, temp, s, mid);
        int inv2 = inversion_cnt(arr, temp, mid+1, e);
        int inv3 = merge(arr, temp, s, mid+1, e);
        return inv1+inv2+inv3;
    }
    return 0;
}

int inversion_cnt(int *arr, int n)
{
    int temp[n] = {0};
    return inversion_cnt(arr, temp, 0, n-1);
}

int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int &val: arr)
        cin >> val;
    cout << inversion_cnt(arr, n);
}