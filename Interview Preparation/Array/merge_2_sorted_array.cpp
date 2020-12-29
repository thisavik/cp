// we have given two sorted arrays
// we have to merge these arrays

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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

int nextGap(int gap) {
    if(gap <= 1)
        return 0;
    return floor(gap/2);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m); 
    for(int& val: a)
        cin >> val;
    for(int& val: b)
        cin >> val;

    // first change any of the array to min heap 
    make_heap(a.begin(), a.end(), greater<int>());
    
    for(int i = 0; i < n; i++) {
        // we are just moving smallest element in a 
        if(a[i] > b[0]) {
            pop_heap(b.begin(), b.end(), greater<int>());
            swap(a[i], b[m-1]);
            push_heap(b.begin(), b.end(), greater<int>());
        }
    }

    // finaliy convert b in max heap 
    // (stl sort_heap arrange max_heap in asending order)
    make_heap(b.begin(), b.end());

    sort_heap(b.begin(), b.end());

    for(int& val: a)
        cout << val << " ";
    cout << "\n";
    for(int& val: b)
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

// M-1 using map O(n + m) TC & O(n + m) SC
    // map<int, int> mp;
    // for(int& val: a) {
    //     cin >> val;
    //     mp[val]++;
    // }
    // for(int& val: b) {
    //     cin >> val;
    //     mp[val]++;
    // }
    // int k=0, flag = false;
    // for(auto p: mp) {
    //     for(int i=0; i<p.second; i++) {
    //         if(k < n && !flag) {
    //             a[k++] = p.first;
    //         } else {
    //             flag = true;
    //             k = 0;
    //         }
    //         if(flag) {
    //             b[k++] = p.first;
    //         }
    //     }
    // }


 M-2 using gap method
    int len = n+m;
    int gap = (len+1)/2;
    while(gap > 0) 
    {
        int i = 0, j = gap;
        cout << j << "\n";
        while(j < len)
        {
            int &x = (i < n) ? a[i] : b[i-n];
            int &y = (j < n) ? a[j] : b[j-n];
            cout << x << " " << y << "\n";
            if(x > y)
                swap(x, y);
            i++, j++;
        }
        gap -= (gap == 1 ? gap : gap/2);
    }

// M-3 generate both array bitonic the use shellsort
    // int x = min(n, m);

    // // convert both arrays in bitonic form
    // for(int i=0; i<x; i++) 
    //     if(a[n-i-1] > b[i])
    //         swap(a[n-i-1], b[i]);
    
    // // sort array-1 using shell sort
    // for(int gap = ceil(n/2); gap > 0; gap = ceil(gap/2))
    //     for(int i=0; i+gap < n; i++)
    //         if(a[i+gap] < a[i])
    //             swap(a[i+gap], a[i]);

    // // sort array-2 using shell sort
    // for(int gap = ceil(m/2); gap > 0; gap = ceil(gap/2))
    //     for(int i = 0; i+gap < n; i++)
    //         if(b[i+gap] < b[i])
    //             swap(b[i+gap], b[i]);     

// M-4 Using Heap
    // // first change any of the array to min heap 
    // make_heap(a.begin(), a.end(), greater<int>());
    
    // for(int i = 0; i < n; i++) {
    //     // we are just moving smallest element in a 
    //     if(a[i] > b[0]) {
    //         pop_heap(b.begin(), b.end(), greater<int>());
    //         swap(a[i], b[m-1]);
    //         push_heap(b.begin(), b.end(), greater<int>());
    //     }
    // }

    // // finaliy convert b in max heap 
    // // (stl sort_heap arrange max_heap in asending order)
    // make_heap(b.begin(), b.end());

    // sort_heap(b.begin(), b.end());