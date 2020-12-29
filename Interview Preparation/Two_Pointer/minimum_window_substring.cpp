/*
Given a string S and a string T, find the minimum window in S, 
which will contain all the characters in T in complexity O(n).
*/

#include <iostream>
#include <vector>
#include <algorithm>

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

// S1 = "ADOBECODEBANC", S2 = "ABC"
pair<int, int> help(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<int> fs1(128, 0), fs2(128, 0);
    for(char ch: s2)
        fs2[ch]++;
    int s = 0, e = 0, minLen = n+1, start = 0, cnt = 0; // cnt contain number of character matches with s2
    while(e < n) {
        fs1[s1[e]]++;
        if(fs1[s1[e]] <= fs2[s1[e]])
            cnt++;
        if(cnt == m) {
            while(fs1[s1[s]] > fs2[s1[s]]) {
                fs1[s1[s]]--;
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
    string s1, s2;
    getline(cin, s1); cout << s1 << "\n";
    getline(cin, s2); cout << s2 << "\n";
    auto ans = help(s1, s2);
    cout << ans.first << " " << ans.second << "\n";
    // cout << (ans.second == s1.size()+1 ? "" : s1.substr(ans.first, ans.second)) << "\n";
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

/*
bool isMatch(vector<int>& a, vector<int>& b) {
    for(int i = 0; i < 100; i++) {
        if(b[i] != 0 && a[i] < b[i])
            return false;
    }
    return true;
}

// S1 = "ADOBECODEBANC", S2 = "ABC"
pair<int, int> help(string s1, string s2) {
    int n = s1.size();
    vector<int> fs1(100, 0), fs2(100, 0);
    for(char ch: s2)
        fs2[ch-'A']++;
    int s = 0, e = 0, end = n, start = 0;
    while(e < n) {
        fs1[s1[e]-'A']++;
        while(isMatch(fs1, fs2) && s <= e) {
            if(end-start+1 > e-s+1)
                end = e, start = s;
            fs1[s1[s]-'A']--;
            s++;
        }
        e++;
    }
    return {start, end};
}
*/