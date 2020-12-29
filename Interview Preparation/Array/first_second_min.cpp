#include <iostream>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

pair<int, int> solve(int *a, int n) {
    int fMin = INT32_MAX, sMin = INT32_MAX;
    for(int i = 0; i < n; i++) {
        if(a[i] < fMin) 
            sMin = fMin, fMin = a[i];
        else if(a[i] < sMin)
            sMin = a[i];
    }
    return { fMin, sMin };
}
int32_t main() {
    tool();
    int n;
    cin >> n;
    int ar[n];
    for(int& val: ar)
        cin >> val;

    auto ans = solve(ar, n);

    cout << ans.first << " " << ans.second << "\n";
}