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

void Longest_prefirLen_suffirLen(string s, vector<int>& lps) {
	int n = s.size();
	lps[0]=0;
	int i=1, len=0;
	while(i<n) {
		if(s[i]==s[len]) {
			len++;
			lps[i]=len;
			++i;
		} else {
			if(len==0) {
				lps[i]=0;
				i++;
			} else {
			  len = lps[len-1];
			}
		}
	}
}

void solve() {
    string s, r;
    cin >> s;
    vector<int> w(26);
    for(int& val: w) 
        cin >> val;
    int n = s.size();
    vector<int> lps(n);
    Longest_prefirLen_suffirLen(s, lps);
    int rLen;
    for(int i=n-1; i>=0; i--)
        if(lps[i] == 1) {
            rLen = i;
            break;
        }
    bool flag = true;
    for(int i=rLen; i+1<n; i++) {
        if(lps[i]+1 != lps[i+1]) {
            flag = false;
        }
    }
    if(flag) {
        r = s.substr(0, rLen);
    } else {
        rLen = s.size();
        r = s;
    }
    int mul = n / rLen;
    int rem = n % rLen;
    cout << r << " " << mul << " " << rem;

    


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