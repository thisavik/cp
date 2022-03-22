#include <bits/stdc++.h>
using namespace std;

int prec(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    return 1;
}

int applyOp(int op1, char ch, int op2)
{
    if (ch == '/')
        return op1 / op2;
    if (ch == '*')
        return op1 * op2;
    if (ch == '+')
        return op1 + op2;
    if (ch == '-')
        return op1 - op2;
    if (ch == '^')
        return pow(op1, op2);
    return 0;
}

int evaluate_infix_expression(string &s)
{
    s = "(" + s + ")";
    stack<int> _oprend;
    stack<char> _operator;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == ' ')
            continue;
        else if (ch == '(')
        {
            _operator.push(ch);
        }
        else if (ch == ')')
        {
            while (_operator.top() != '(')
            {
                int op2 = _oprend.top();
                _oprend.pop();
                int op1 = _oprend.top();
                _oprend.pop();
                char opr = _operator.top();
                _operator.pop();
                _oprend.push(applyOp(op1, opr, op2));
            }
            _operator.pop();
        }
        else if (isdigit(ch))
        {
            int temp = 0;
            while (i < s.size() && isdigit(s[i]))
            {
                temp = temp * 10 + (s[i] - '0');
                i++;
            }
            i--;
            _oprend.push(temp);
        }
        else
        {
            while (_operator.top() != '(' && prec(ch) <= prec(_operator.top()))
            {
                int op2 = _oprend.top();
                _oprend.pop();
                int op1 = _oprend.top();
                _oprend.pop();
                char opr = _operator.top();
                _operator.pop();
                _oprend.push(applyOp(op1, opr, op2));
            }
            _operator.push(ch);
        }
    }
    cout << "\n";
    return _oprend.top();
}

int main()
{
    string s = "100 * ( 2 + 12 ) / 14";
    // cin >> s;
    cout << evaluate_infix_expression(s);
}