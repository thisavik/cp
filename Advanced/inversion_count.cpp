#include<bits/stdc++.h>

using namespace std; 

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

int getSum(int BITree[], int index)
{
    int sum = 0;
    while (index > 0) 
    { 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 2

void updateBIT(int BITree[], int n, int index, int val)
{ 
    while (index <= n) 
    { 
       BITree[index] += val; 
       index += index & (-index); 
    } 
} 
int getInvCount(int arr[], int n) 
{ 
    int invcount = 0;
    int maxElement = 0; 
    for (int i=0; i<n; i++) 
        if (maxElement < arr[i]) 
            maxElement = arr[i]; 
    int BIT[maxElement+1] = {0}; 
    for (int i=n-1; i>=0; i--) 
    { 
        invcount += getSum(BIT, arr[i]-1); 
        updateBIT(BIT, maxElement, arr[i], 1); 
    } 
  
    return invcount; 
} 
int main() 
{
    tool();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int& val : a)
            cin >> val;
        cout << getInvCount(a, n) << "\n";         
    }
}