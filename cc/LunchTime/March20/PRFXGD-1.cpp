#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    int k, x;
	    cin >> k >> x;
	    map<char, int> m;
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            if(k != 0 && m[s[i]] == x){
                k--;
                continue;
            }
            if(m[s[i]] < x){
                cnt++;
                m[s[i]]++;
            }
            else 
                break;
        }
        cout << cnt << "\n";
	}
	return 0;
}
