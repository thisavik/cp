#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

void merge(vector<int>& a, int l, int mid, int r) {
    int n1 = mid-l+1;
    int n2 = r-mid;
    vector<int> L(n1);
    vector<int> R(n2);
    for(int i=0; i<n1; i++) {
        L[i] = a[l+i];
    }
    for(int i=0; i<n2; i++) {
        R[i] = a[mid+1+i];
    }
    int i=0, j=0;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            a[l++] = L[i++];
        } else {
            a[l++] = R[j++];
        }
    }
    while(i < n1) {
        a[l++] = L[i++];
    }
    while(j < n2) {
        a[l++] = R[j++];
    }
}

void mergeSort(vector<int>& a, int l, int r) {
    if(l < r) {
        int mid = l + (r-l)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);
        merge(a, l, mid, r);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& val: a)
        cin >> val;
    mergeSort(a, 0, a.size()-1);
    for(int& val: a)
        cout << val << " ";
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}