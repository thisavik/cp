#include <bits/stdc++.h>
using namespace std;

int Hash(char &ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    return 1;
}

bool isAlpha(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// infix to postfix
string infixToPostfix(string in)
{
    in = "(" + in + ")";
    string postfix;
    stack<char> st;
    for (int i = 0; i < in.size(); i++)
    {
        char cur = in[i];
        if (cur == '(')
        {
            st.push(cur);
            continue;
        }
        if (cur == ')')
        {
            while (st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
            continue;
        }
        // a-z || A-B
        if (isAlpha(cur))
            postfix += cur;
        else
        {
            bool flag = true;
            while (st.top() != '(' && flag && Hash(st.top()) >= Hash(cur))
            {
                flag = (Hash(st.top()) >= Hash(cur));
                // if st.top() is prior then cur operator then pop it
                if (flag)
                {
                    postfix += st.top();
                    st.pop();
                }
            }
            st.push(cur);
        }
    }
    return postfix;
}

// infix to prefix
string infixToPrefix(string in)
{
    in = "(" + in + ")";
    reverse(in.begin(), in.end());
    string prefix;
    stack<char> st;
    for (int i = 0; i < in.size(); i++)
    {
        char cur = in[i];
        if (cur == '(')
        {
            st.push(cur);
            continue;
        }
        if (cur == ')')
        {
            while (st.top() != '(')
            {
                prefix += st.top();
                st.pop();
            }
            st.pop();
            continue;
        }
        // a-z || A-B
        if (isAlpha(cur))
            prefix += cur;
        else
        {
            bool flag = true;
            while (st.top() != '(' && flag && Hash(st.top()) >= Hash(cur))
            {
                flag = (Hash(st.top()) >= Hash(cur));
                // if st.top() is prior then cur operator then pop it
                if (flag)
                {
                    prefix += st.top();
                    st.pop();
                }
            }
            st.push(cur);
        }
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

// postfix to infix
string postfixToInfix(string post)
{
    stack<string> st;
    for (int i = 0; i < post.size(); i++)
    {
        char cur = post[i];
        if (isAlpha(cur))
            st.push(string(1, cur));
        else
        {
            string &s2 = st.top();
            st.pop();
            string &s1 = st.top();
            st.pop();
            string res = "(" + s1 + cur + s2 + ")";
            st.push(res);
        }
    }
    return st.top();
}

// prefix to infix
string prefixToInfix(string pre)
{
    stack<string> st;
    for (int i = prefix.size() - 1; i >= 0; i--)
    {
        char cur = post[i];
        if (isAlpha(cur))
            st.push(string(1, cur));
        else
        {
            string &s1 = st.top();
            st.pop();
            string &s2 = st.top();
            st.pop();
            string res = "(" + s1 + cur + s2 + ")";
            st.push(res);
        }
    }
    return st.top();
}

// prefix to postfix
string prefixToInfix(string pre)
{
    stack<string> st;
    for (int i = prefix.size() - 1; i >= 0; i--)
    {
        char cur = post[i];
        if (isAlpha(cur))
            st.push(string(1, cur));
        else
        {
            string &s1 = st.top();
            st.pop();
            string &s2 = st.top();
            st.pop();
            string res = s1 + s2 + cur;
            st.push(res);
        }
    }
    return st.top();
}

// postfix to prefix
string postfixToPrefix(string post)
{
    stack<string> st;
    for (int i = 0; i < post.size(); i++)
    {
        char cur = post[i];
        if (isAlpha(cur))
            st.push(string(1, cur));
        else
        {
            string &s2 = st.top();
            st.pop();
            string &s1 = st.top();
            st.pop();
            string res = cur + s1 + s2;
            st.push(res);
        }
    }
    return st.top();
}

void solve()
{
    string s;
    cin >> s;
    cout << postfixToInfix(s) << "\n";
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}