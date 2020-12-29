// In this sorting algorithm we are sorting like this

#include <iostream>
#include <vector>
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

void shellSort(vector<int>& a) {
    int n = a.size();
    for(int gap = n/2; gap > 0; gap = gap/2) {
        for(int j = gap; j < n; j++) {
            for(int i = j-gap; i >= 0 && a[i+gap] < a[i]; i -= gap) {
                swap(a[i+gap], a[i]);
            }
        }
    }
    for(int& val: a)
        cout << val << " ";
}

int32_t main() {
    tool();
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& val: a)
        cin >> val;
    shellSort(a);
    return 0;
}
