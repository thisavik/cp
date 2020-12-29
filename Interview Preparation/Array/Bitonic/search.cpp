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
 
int findBitonicPoint(int *a, int n) {
    if(n == 1)
        return 0;
    if(n == 2)
        return a[0] > a[1] ? 0 : 1;
    int l = 0, r = n-1, ans;
    while(l < r) {
        int mid = (l+r)/2;
        if(a[mid] > a[mid+1] && a[mid] > a[mid+1]) {
            ans = mid;
            break;
        }
        if(a[mid] > a[l])
            l = mid+1;
        else
            r = mid-1;
    }
    return ans;
}

int binarySearchAsec(int *a, int l, int r, int key) {
    int ans = -1;
    while(l <= r) {
        int mid = (l+r)/2;
        if(a[mid] == key) {
            ans = mid;
            break;
        }
        if(a[mid] > key)
            r = mid-1;
        else
            l = mid+1;
    }
    return ans;
}

int binarySearchDesc(int *a, int l, int r, int key) {
    int ans = -1;
    while(l <= r) {
        int mid = (l+r)/2;
        if(a[mid] == key) {
            ans = mid;
            break;
        }
        if(a[mid] > key)
            l = mid-1;
        else
            r = mid+1;
    }
    return ans;
}

int search(int *a, int n, int key) {
    int idx = findBitonicPoint(a, n);
    int ans = binarySearchAsec(a, 0, idx, key);
    if(ans == -1)
        ans = binarySearchDesc(a, idx, n-1, key);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int& val: a)
        cin >> val;
    int key;
    cin >> key;
    int idx = search(a, n, key);
    if(idx == -1)
        cout << -1 << "\n";
    else
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