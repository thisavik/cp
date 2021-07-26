#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// lower_bound
// return position of 1st element greater than equal to val
// [s, e)
int Lower_bound(vector<int> a, int s, int e, int val)
{
    int ans = e;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] >= val)
            ans = mid, e = mid - 1;
        else
            s = mid + 1;
    }
    return ans;
}

// upper_bound
// return position of 1st element greater than val
// [s, e)
int Upper_bound(vector<int> a, int s, int e, int val)
{
    int ans = e;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] > val)
            ans = mid, e = mid - 1;
        else
            s = mid + 1;
    }
    return ans;
}

int32_t main()
{
    vector<int> v{10, 20, 30, 45, 45, 60, 70, 80};
    cout << Lower_bound(v, 0, 7, 45) << "\n";                        // 4
    cout << lower_bound(v.begin(), v.end(), 45) - v.begin() << "\n"; // 4
    cout << Upper_bound(v, 0, 7, 45) << "\n";                        // 4
    cout << upper_bound(v.begin(), v.end(), 45) - v.begin() << "\n"; // 4
}