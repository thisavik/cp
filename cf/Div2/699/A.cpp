#include <iostream>
#include <vector>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

void solve()
{
    int n;
    cin >> n;
    vector<int> in(n);
    int one = 0 , zero = 0;
    for(int i = 0; i < n ; i++)
        cin >> in[i], in[i] == 1 ? one++ : zero++;
    if(one > n/2)
    {
        cout << n/2 << "\n";
        for(int i = 0; i < n; i++)
            
    }
    int l = 0, r = 1;
    while(l < n && r < n)
    {
        if(in[l] == 0)
            l++, r++;
        else
        {
            while(r < n && in[r] == 0)
                r++;
            if(r == n)
                break;
            if((r-l) % 2 == 0)
                in[r-1] = 2;
            l = ++r;
        }
    }
    if(l < r)
        in[l] = 2;
    vector<int> ans;
    for(int val : in)
        if(val != 2)
            ans.push_back(val);
    cout << ans.size() << "\n";
    for(int val : ans)
        cout << val << " ";
    cout << "\n";    
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


