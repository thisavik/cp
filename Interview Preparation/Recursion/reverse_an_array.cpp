#include <iostream>
#include <vector>

using namespace std;
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}
void reverse(vector<int>& a, int i) {
    if(i < a.size()/2) {
        swap(a[i], a[a.size()-i-1]);
        reverse(a, i+1);
    }
}

int32_t main() {
    tool();
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& val: a)
        cin >> val;
    reverse(a, 0);
    for(int& val: a)
        cout << val << " ";
}