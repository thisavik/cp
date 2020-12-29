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


bool comp(pair<int, int>& p1, pair<int, int>& p2) {
    if(p1.first == p2.first) {
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
    // return true, if it is ok (swap not required)
    // return false, if swap need (swap required)
}

int main() {
    tool();
    vector<pair<int, int>> v;
    for(int i=0; i<10; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), comp);
    for(pair<int, int>& p: v)
        cout << p.first << " " << p.second << "\n";
    return 0;
}