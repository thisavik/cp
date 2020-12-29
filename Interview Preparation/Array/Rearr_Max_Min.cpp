// we are given array a size n
// we have to arrange that array in this way --> max1, min1, max2, min2, .....
// Contraint: O(n) TC , O(1) SC

// Solution:

// find a number that is just greater that max of all element --> max = (max_element +1)
// idea is to store max1*max + a[0], min1*max + a[1], max2*max + a[2], min2*max + a[3], ... so on
// then divide the array by max
// we will get our desired result

#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& val: a)
        cin >> val;
    sort(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end()) + 1;
    int s = 0, l = n-1;
    for(int i=0; i<n; i++) {
        if(i&1 && s<n) {
            a[i] += mx*(a[s]%mx);
            s++;
        } else if(l>=0){
            a[i] += mx*(a[l]%mx);
            l--;
        }
    }
    for(int& val: a)
        cout << val/mx << " ";
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