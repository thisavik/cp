#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Partition(vector<int>& a, int l, int r) {
    int pivot = a[r];
    int pIndex = l;
    for(int i = l; i<r; i++) {
        if(a[i] <= pivot) {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[r]);
    return pIndex;
}

// ristrict partition when we got partition index as k-1
int kth_Smallest_element(vector<int>& a, int l, int r, int k) {
    int pIndex = Partition(a, l, r);
    if(pIndex == k-1) {
        return pIndex;
    } else if(pIndex > k-1)
        return kth_Smallest_element(a, l, pIndex-1, k);
    else
        return kth_Smallest_element(a, pIndex+1, r, k);
}

int kth_Smallest_element(vector<int>& a, int k) {
    return kth_Smallest_element(a, 0, a.size()-1, k);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int& val: a)
        cin >> val;
    int ans = kth_Smallest_element(a, k);

    cout << ans << " " << a[ans] << "\n";

    for(int& val: a)
        cout << val << " ";
    cout << "\n";
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}