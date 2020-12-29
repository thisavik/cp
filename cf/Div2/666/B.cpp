#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxN = 1e15+1;
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

int32_t main()
{
    tool();
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& val : a)
        cin >> val;
    sort(a.begin(), a.end());
    int ans = maxN;
    int c = 1, pow = 1;
    bool flag = false;
    while(1)
    {
        int res = 0, pow = 1;
        for(int i = 0; i < n; i++)
        {
            res += abs(a[i]-pow);
            pow = pow*c;
            assert(pow < (long long)1e15);
            if(pow > maxN)
            {
                flag = true;
                break;
            }
        }
        if(flag)
            break;
        ans = min(ans, res), c++;
    }

    cout << ans;
    return 0;
}