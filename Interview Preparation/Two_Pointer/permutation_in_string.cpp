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

bool isAvail(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    if(n > m)
        return false;
    bool flag = false;
    int fs1[26] = {0}, fs2[26] = {0};
    for(char ch: s1)
        fs1[ch-'a']++;
    for(int i = 0; i < n; i++)
        fs2[s2[i]-'a']++;
    int cnt = 0;
    for(int i = 0; i < 26; i++)
        if(fs1[i] == fs2[i])
            cnt++;
    if(cnt == 26)
        return true;
    for(int i = n; i < m; i++) {
        // remove this one
        int l = s2[i-n]-'a';
        if(fs1[l] == fs2[l])
            cnt--;
        fs2[l]--;
        if(fs1[l] == fs2[l])
            cnt++;
        // add this one 
        int r = s2[i]-'a';
        if(fs1[r] == fs2[r])
            cnt--;
        fs2[r]++;
        if(fs1[r] == fs2[r])
            cnt++;
        if(cnt == 26)
            return true;
    }
    return false;
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << (isAvail(s1, s2) ? "True" : "False") << "\n";
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
bool isSame(int *a, int *b) {
    for(int i = 0; i < 26; i++)
        if(a[i] != b[i])
            return false;
    return true;
}

bool isAvail(string& s1, string& s2) {
    int n = s1.size(), m = s2.size();
    if(n > m)
        return false;
    bool flag = false;
    int fs1[26] = {0}, fs2[26] = {0};
    for(char ch: s1)
        fs1[ch-'a']++;
    for(int i = 0; i < n; i++)
        fs2[s2[i]-'a']++;
    if(isSame(fs1, fs2))
        return true;
    for(int i = n; i < m; i++) {
        fs2[s2[i-n]-'a']--;
        fs2[s2[i]-'a']++;
        if(isSame(fs1, fs2))
            return true;
    }
    return false;
}
*/