#include <bits/stdc++.h>

using namespace std;

int countDigitOne(int n)
{
    int counter = 0;
    for(int i = 1; i <= n; i *= 10)
    {
        int divider = i*10;
        int x = (n / divider) * i;
        int y = min(max(n % divider-i+1, 0), i);
        cout << i << " " << x << " " << y << "\n";
        counter += (x+y);
    }
    return counter;
}
int32_t main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << countDigitOne(n) << "\n";
    }
    return 0;
}