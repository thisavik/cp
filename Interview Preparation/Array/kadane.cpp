#include <iostream>
using namespace std;

int main()
{
    tool();
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int max_so_far = a[0], max_till_now = a[0];
    // for(int i=0; i<n; i++) {
    //   max_till_now += a[i];
    //   if(max_till_now < 0)
    //     max_till_now = 0;
    //   else if(max_so_far < max_till_now)
    //     max_so_far = max_till_now;
    // }
    for (int i = 1; i < n; i++)
    {
        max_till_now = max(a[i], max_till_now + a[i]);
        max_so_far = max(max_so_far, max_till_now);
    }
    cout << max_so_far;
}