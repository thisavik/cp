#include <iostream>
#include <stack>
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

int LVP_using_stack(string s) {
    int maxLen = 0;
    // we will push index value n stack
    stack<int> stk;
    // push -1 for the corner case i.e. '()'
    stk.push(-1);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(')
            stk.push(i);
        else {
            stk.pop();
            if(stk.empty())
                stk.push(i);
            else
                maxLen = max(maxLen, i-stk.top());
        }
    }
    return maxLen;
}

int LVP_using_two_var(string s) {
    int oB = 0, cB = 0, maxLen = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(')
            oB++;
        else
            cB++;
        if(oB == cB)
            maxLen = max(maxLen, 2*oB);
        else if(cB > oB)
            cB = oB = 0;
    }
    cB = oB = 0;
    for(int i = s.size()-1; i >= 0; i--) {
        if(s[i] == '(')
            oB++;
        else
            cB++;
        if(oB == cB)
            maxLen = max(maxLen, 2*oB);
        else if(oB > cB)
            cB = oB = 0;
    }
    return maxLen;
}

int LVP_using_dp_array(string s) {
    int n = s.size(), maxLen = 0;
    int dp[n] = {0};
    for(int i = 0; i < n; i++) {
        if(s[i] == ')') {
            if(i-1 >= 0 && s[i-1] == '(')
                dp[i] = (i-2 >= 0 ? dp[i-2] : 0) + 2;
            else if(i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(')
                dp[i] = dp[i-1] + 2 + (i-dp[i-1]-2 >= 0 ? dp[i-dp[i-1]-2] : 0);
        }
        for(int i = 0; i < n; i++) cout << dp[i] << " ";
        cout << "\n";
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}
void solve() {
    string s;
    cin >> s;
    cout << LVP_using_stack(s) << "\n";
    cout << LVP_using_two_var(s) << "\n";
    cout << LVP_using_dp_array(s) << "\n";
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}