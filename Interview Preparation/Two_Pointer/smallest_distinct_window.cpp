/*
Given a string 's'. The task is to find the smallest window length that contains 
all the characters of the given string at least one time.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.
*/

#include <iostream>
#include <vector>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

pair<int, int> help(string str) {
    int n = str.size(), dist = 0;
    vector<int> fs(128, 0);
    for(char ch: str) {
        fs[ch]++;
        if(fs[ch] == 1)
            dist++;
    }
    fill(fs.begin(), fs.end(), 0);
    int s = 0, e = 0, minLen = n, start = 0, cnt = 0; // cnt contains number of distinct char in current window
    while(e < n) {
        fs[str[e]]++;
        if(fs[str[e]] == 1)
            cnt++;
        if(cnt == dist) {
            while(fs[str[s]] > 1 && s <= e) {
                fs[str[s]]--;
                s++;
            }
            if(minLen > e-s+1)
                start = s, minLen = e-s+1;
        }
        e++;
    }
    return {start, minLen};
}

void solve() {
    string s;
    cin >> s;
    auto ans = help(s);
    cout << s.substr(ans.first, ans.second) << "\n";;
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}