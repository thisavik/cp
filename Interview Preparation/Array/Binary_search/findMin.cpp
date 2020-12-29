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

int findMin(int *a, int n) {
    int l = 0, h = n-1, mid;
    while(l < h) {
        mid = (l+h)/2;
        if(a[mid] > a[h])
            l = mid+1;
        else
            h = mid;
    }
    return a[l];
}

int32_t main() {
    tool();
    int n;
    cin >> n;
    int a[n];
    for(int& val: a)
        cin >> val;
    cout << findMin(a, n);
}