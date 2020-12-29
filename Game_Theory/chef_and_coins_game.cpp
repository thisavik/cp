// https://www.codechef.com/problems/CHCOINSG
// tags : pattern, observation
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 6)
            cout << "Chef\n";
        else
            cout << "Misha\n";
    }
    return 0;
}