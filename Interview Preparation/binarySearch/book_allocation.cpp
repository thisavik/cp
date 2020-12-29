#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

bool isValid(vector<int>& pages, int k, int ans)
{
    int s = 1;
    int current_pages = 0;
    for(int i = 0; i < pages.size(); i++)
    {
        if(current_pages + pages[i] > ans)
        {
            current_pages = pages[i];
            s++;
            if(s > k)
                return false;
        }
        else
        {
            current_pages += pages[i];
        }
    }
    return true;
}

int binarySearchBooks(vector<int>& pages, int k)
{
    int s = 0, e = 0;
    for(int& val: pages)
        e += val, s = max(s, val);
    int ans = 0;
    while(s <= e)
    {
        int mid = (s + e)/2;
        if(isValid(pages, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n;
    vector<int> pages(n);
    for(int& val : pages)
        cin >> val;
    cin >> k;
    cout << binarySearchBooks(pages, k) << "\n";
}

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}