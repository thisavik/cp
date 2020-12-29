#include <iostream>
using namespace std;

void tool() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	    freopen("C://git//cp//input.txt", "r", stdin);
	    freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

void solve() {
    int n, s, res = 0;
    cin >> s >> n;
    if(s&1) {
        s--;
        res++;
    }
    res += s/n;
    if(s%n)
        res++;
    cout << res << "\n";
}

int main() 
{
    tool();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
