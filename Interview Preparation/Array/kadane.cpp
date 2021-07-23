#include <iostream>
using namespace std;

int approach1(int a[], int n)
{
    int max_so_far = 0, max_till_now = 0;
    for (int i = 0; i < n; i++)
    {
        max_till_now += a[i];
        if (max_till_now < 0)
            max_till_now = 0;
        else if (max_so_far < max_till_now)
            max_so_far = max_till_now;
    }
    return max_so_far;
}

int approach2(int a[], int n)
{
    int max_so_far = a[0], max_till_now = a[0];
    for (int i = 1; i < n; i++)
    {
        max_till_now = max(a[i], max_till_now + a[i]);
        max_so_far = max(max_so_far, max_till_now);
    }
    return max_so_far;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << approach1(a, n) << "\n";
    cout << approach2(a, n) << "\n";
}