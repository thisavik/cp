#include <iostream>
#include <unordered_map>

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

pair<int, int> atMostK(int *a, int n, int k) {
    if(k <= 0)
        return {-1, -1};
    unordered_map<int, int> freq; 
    int s = 0, e = 0, maxlen = 0, dist = 0, start = 0, end = 0;
    while(e < n) {
        freq[a[e]]++;
        if(freq[a[e]] == 1)
            dist++;
        while(dist > k) {
            if(freq[a[s]] == 1)
                dist--;
            freq[a[s]]--;
            s++;       
        }
        if(dist == k && end-start+1 < e-s+1)
            end = e, start = s;
        e++;
    }
    return {start, end};
}

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int& val: a)
        cin >> val;
    auto ans = atMostK(a, n, k);
    if(ans.first == -1) {
        cout << -1;
        return;
    }
    for(int i = ans.first; i <= ans.second; i++)
        cout << a[i] << " ";
}

int32_t main() {
    tool();
    int t = 1;
    while(t--)
        solve();
    return 0;
}