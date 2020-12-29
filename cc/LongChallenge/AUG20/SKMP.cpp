#include <iostream>
#include <algorithm>
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

void solve() {
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    int fs[26] = {0}, fp[26] = {0};
    for(char ch: s)
        fs[ch-'a']++;
    for(char ch: p)
        fp[ch-'a']++;
    for(int i = 0; i < 26; i++) 
        fs[i] -= fp[i], fp[i] = fs[i];
    string res1 = "";
    for(int i = 0; i < 26; i++) {
        char ch = (char)(i+97);
        int n = fs[i];
        for(int j = 0; j < n; j++)
            if(ch < p[0]) {
                res1 += ch, fs[i]--;
            } else {
                break;
            }
    }
    res1 += p;
    for(int i = 0; i < 26; i++) {
        char ch = (char)(i+97);
        for(int j = 0; j < fs[i]; j++)
            res1 += ch;
    }
    string res2 = "";
    for(int i = 0; i < 26; i++) {
        char ch = (char)(i+97);
        int n = fp[i];
        for(int j = 0; j < n; j++)
            if(ch <= p[0]) {
                res2 += ch, fp[i]--;
            } else {
                break;
            }
    }
    res2 += p;
    for(int i = 0; i < 26; i++) {
        char ch = (char)(i+97);
        for(int j = 0; j < fp[i]; j++)
            res2 += ch;
    }
    cout << (res1 > res2 ? res2 : res1) << "\n";
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

3
akramkeeanany
aka
supahotboy
bohoty
daehabshatorawy
badawy

aaakaeekmnnry
abohotypsu
aabadawyehhorst
*/