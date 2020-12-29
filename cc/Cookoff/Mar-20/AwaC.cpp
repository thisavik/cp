#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void tool() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main() {
    tool();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ar[100000];
        for (int i = 0; i < n; i++)cin >> ar[i];
        int maxi = *max_element(ar, ar + n);
        int beg = -1, end = -1;
        for (int i = 0; i < n; i++) {
            if (ar[i] == maxi && beg != -1)end = i;
            if (ar[i] == maxi && end == -1)beg = i;
        }
        if (end == -1)cout << n / 2 << " \n";
        else {
            if (end - beg < n / 2)cout << n / 2 - (end - beg) << "\n";
            else
                cout << "0\n";
        }
    }
    return 0;
}
