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

int sumEqualK(int *a, int n, int k) {
    int s = 0, e = 0, minLen = n+1, sum = 0;
    while(e < n) {
        sum += a[e];
        while(sum >= k && s <= e) {
            if(sum == k)
                minLen = min(minLen, e-s+1);
            sum -= a[s];
            s++;
        }
        e++;
    }
    return minLen;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int& val: a)
        cin >> val;
    
    cout << sumEqualK(a, n, k);
}

int32_t main() {
    tool();
    int t = 1;
    while(t--)
        solve();
    return 0;
}

/*
// use prefix array
int sumEqualk(int *a, int n) {
    int prefix[n+1] = {0}, minLen = n+1;
    for(int i = 1; i <= n; i++)
        prefix[i] = prefix[i-1] + a[i-1];

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++)
            if(prefix[i]-prefix[j] == k)
                minLen = min(minLen, i-j);
    }
    return minLen;
}
*/