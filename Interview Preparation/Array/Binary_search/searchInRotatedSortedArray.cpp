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

int binarySearch(int *a, int n, int key) {
    int l = 0, r = n-1;
    while(l <= r) {
        int mid = (l+r)/2;
        if(a[mid] == key)
            return mid;
        if(a[mid] > key)
            r = mid-1;
        else 
            l = mid+1;
    }
    return -1;
}

int findPivot(int *a, int n) {
    int l = 0, r = n-1;
    while(l <= r) {
        int mid = (l+r)/2;
        if(mid+1 <= r && a[mid] > a[mid+1] && mid-1 >= l && a[mid] > a[mid-1])
            return mid;
        if(a[mid] > a[l])
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}

int32_t main() {
    tool();
    int n;
    cin >> n;
    int a[n];
    for(int& val: a)
        cin >> val; 
    int key;
    cin >> key;
    int pivot = findPivot(a, n);
    cout << pivot << "\n" << a[pivot] << "\n";
    // cout << binarySearch(a, n, key);
}