#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a , int b)
{
    if(b==0) return a;
        a%=b;
    return gcd(b,a);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &val : a)
        cin >> val;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int till = a[0];
    cout << till << " ";
    for(int i = 1; i < n ;i++)
    {
        int mx = 1, temp = i;
        for(int j = i; j < n; j++)
        {
            if(mx < gcd(till, a[j]));
                mx = gcd(till, a[j]), temp = j;
        }
        if(mx == 1)
        {
            while(temp < n)
                cout << a[temp] << " ";
            cout << "\n";
            return;
        }        
        till = mx;
        cout << a[temp] << " ";
        swap(a[temp], a[i]);
    }
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


