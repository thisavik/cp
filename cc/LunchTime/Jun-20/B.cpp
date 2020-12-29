#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

 
#define FORi(i, a, n) for(int i=a; i<n; i++)

void tool() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	    freopen("C://git//cp//input.txt", "r", stdin);
	    freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}
void solve();

int main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for(int& val: a) {
        cin >> val;
        cnt[val]++;
    }
    for(auto& itr: cnt) {
        if(itr.second > 2) {
            cout << "NO\n";
            return;
        }
    }
    if(cnt[*max_element(a.begin(), a.end())] > 1) {
        cout << "NO\n";
        return;
    }
    int l=0, r=n-1;
    cout << "YES\n";
    for(auto& itr: cnt) {
        a[l++] = itr.first;
        if(itr.second == 2)
            a[r--] = itr.first;
    }
    for(int& val: a)
        cout << val << " ";
    cout << "\n";
}