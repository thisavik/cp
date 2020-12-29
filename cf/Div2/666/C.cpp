#include <bits/stdc++.h>
using namespace std;

#define int long long

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
    if(n == 1)
    {
        cout << 1 << " " << 1 << "\n";
        cout << -a[0] << "\n";
        cout << 1 << " " << 1 << "\n";
        cout << 0 << "\n";
        cout << 1 << " " << 1 << "\n";
        cout << 0 << "\n";
        return 0;
    }
    cout << 1 << " " << n << "\n";
    for(int i = 0; i < n; i++)
    {
        cout << -a[i]*n << " ";
    }
    cout << "\n";
    cout << 1 << " " << n-1 << "\n";
    for(int i = 0; i < n-1; i++)
    {
        cout << a[i]*(n-1) << " ";
    }
    cout << "\n";
    cout << n << " " << n << "\n";
    cout << a[n-1]*(n-1);
    return 0;
}