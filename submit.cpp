/*
 *  author: thisavik
 *  created: 10:08:06 13-08-2021 Fri
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/thisa/OneDrive/Documents/cp/input.txt", "r", stdin);
    freopen("C:/Users/thisa/OneDrive/Documents/cp/output.txt", "w", stdout);
    freopen("C:/Users/thisa/OneDrive/Documents/cp/error.txt", "w", stderr);
#endif
}
/*
bool isoperator(char ch)
{
    return ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-';
}

int priority(char ch)
{
    if(ch == '^') 
        return 3;
    if(ch == '/' || ch == '*')
        return 2;
    return 1;
}

string infixToPostfix(string s)
{
    s = "(" + s + ")";
    string ans = "";
    stack<char> st;
    for(int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if(ch == '(')
            st.push(ch);
        else if(ch == ')')
        {
            while(st.top() != '(')
                ans.push_back(st.top()), st.pop();
            st.pop();
        }
        else if(isalpha(ch))
            ans.push_back(ch);
        else if(isoperator(ch))
        {
            while(!st.empty() && isoperator(st.top()) && priority(ch) <= priority(st.top()))
                ans.push_back(st.top()), st.pop();
            st.push(ch);
        }
    }
    return ans;
}
*/
int coc(char c)
{
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    return 1;
}
string infixToPostfix(string s)
{
    stack<char> st;
    string res="";
    
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        
        if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        {
            res+=c;
        }
        else if(c=='(')
        {
            st.push(c);
        }
        else if(c == ')')
        {
            while(st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && coc(s[i]) <= coc(st.top()))
            {
                res += st.top();
                st.pop(); 
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    return res;
}

void solve()
{
    string s;
    cin >> s;
    cout << infixToPostfix(s) << "\n";
}

int32_t main(int32_t argc, char *args[])
{
    tool();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}