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

void bitScore(int& val) {
    int a = val%10; val /=10;
    int b = val%10; val /=10;
    int c = val%10;
    val = max(a, max(b, c))*11 + min(a, min(b, c))*7;
}

int32_t main() {
    tool();
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& val: a) {
        cin >> val;
        bitScore(val);
    }
    vector<pair<int, int>> sgnBit(10, {0, 0});
    int ans = 0;
    for(int i=0; i<n; i+=2) {
        sgnBit[a[i]/10].first++;
    }
    for(int i=1; i<=9; i++) {
        if(sgnBit[i].first == 1) 
            sgnBit[i].first = 0;
    }
    for(int i=0; i<n; i+=2) {
        sgnBit[a[i]/10].second++;
    }
    for(int i=1; i<=9; i++) {
        if(sgnBit[i].first == 1) 
            sgnBit[i].first = 0;
    }
    for(int i=1; i<=9; i++) 
        ans += ceil(max(sgnBit[i].first, sgnBit[i].second)/2);
    cout << ans; 
}