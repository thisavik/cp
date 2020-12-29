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

void PermutationOfString(string& input, string& res, vector<int>& cnt, int level) {
    if(level == input.size()) {
        // print the result
        cout << res << "\n";
    } else {
        // iterate through each letter for this level
        for(int i=0; i < input.size(); i++) {
            if(cnt[i] == 0) {
                // if count of any character is 0 simply continue
                continue;
            } else {
                // otherwise add it in res array
                res[level] = input[i];
                // decrease the count of that added char
                cnt[i]--;
                // recursive call for next level
                PermutationOfString(input, res, cnt, level+1);
                // restore the count for backtrack
                cnt[i]++;
            }
        }
    }
}

int32_t main() {
    tool();
    string s;
    cin >> s;
    string res = s;
    vector<int> cnt(s.size(), 1);
    PermutationOfString(s, res, cnt, 0);
}