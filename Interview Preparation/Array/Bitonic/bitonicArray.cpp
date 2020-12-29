// find bitonic point in bitonic array
// bitonic array is sequence which is first stricly increasing then after a certain point 
// it is stricly decreasing

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

int findBitonicPoint(vector<int>& a) {
    if(a.size() == 1)
        return 0;
    if(a.size() == 2)
        return a[0] > a[1] ? 0 : 1;
    int l = 0, r = a.size()-1;
    int ans = 0;
    while(l < r) {
        int mid = l + (r-l)/2;
        if(a[mid] > a[mid+1] && a[mid] > a[mid-1]) {
            ans = mid;
            break;
        } else if(a[mid] < a[mid+1]) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& val: a)
        cin >> val;
    int idx = findBitonicPoint(a);
    cout << idx << " " << a[idx] << "\n";
    
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
