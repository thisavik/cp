/*
1
4 1
3 4 5 1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FORi(i, a, n) for(ll i=a; i<n; i++)
#define ll ll

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
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

bool desc(pair<ll, ll>& p1, pair<ll, ll>& p2) {
    if(p1.second > p2.second) {
        return true;
    }
    else if(p1.second == p2.second) {
        if(p1.first <= p2.second)
            return true;
        else
            return false;
    } else
        return false;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<pair<ll, ll>> v(32, {0, 0});
    for(int& val: a) {
        cin >> val;
        FORi(i, 0, 32) {
            if(val&(1<<i))
                v[i].second++;
        }
    }
    FORi(i, 0, 32) {
        v[i].first = i;
        v[i].second *= (1LL<<i);
    }
    sort(v.begin(), v.end(), desc);
    ll ans = 0;
    FORi(i, 0, k) 
        ans += (1LL<<v[i].first);
    cout << ans << "\n";
}