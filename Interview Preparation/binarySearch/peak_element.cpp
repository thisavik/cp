#include <bits/stdc++.h>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("C://git//cp//input.txt", "r", stdin);
    freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

int peakElt(vector<int> &a)
{
    int s = 0, e = a.size() - 1, mid, ans;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (mid > 0 && a[mid] > a[mid - 1])
        {
            if (mid + 1 < a.size() && a[mid] > a[mid + 1])
            {
                ans = mid;
                break;
            }
            else
                s = mid + 1;
        }
        else
            e = mid - 1;
        // edge condition handled here 
        ans = mid;
    }
    return ans;
}

int peakElt2(vector<int>& a)
{
    int s = 0, e = a.size()-1, mid;
    while(s < e)
    {
        mid = (s+e)/2;
        if(a[mid] < a[mid+1])
            s = mid+1;
        else
            e = mid;
    }
    return s;
}

int32_t main()
{
    tool();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &val : a)
        cin >> val;
    cout << peakElt2(a);
}