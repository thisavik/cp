#include <bits/stdc++.h>
using namespace std;

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
namespace
{
    template <typename A, typename B>
    ostream &operator<<(ostream &out, const pair<A, B> &a)
    {
        out << "(" << a.first << "," << a.second << ")";
        return out;
    }
    template <typename T, size_t N>
    ostream &operator<<(ostream &out, const array<T, N> &a)
    {
        out << "[";
        bool first = true;
        for (auto &v : a)
        {
            out << (first ? "" : ", ");
            out << v;
            first = 0;
        }
        out << "]";
        return out;
    }
    template <typename T>
    ostream &operator<<(ostream &out, const vector<T> &a)
    {
        out << "[";
        bool first = true;
        for (auto &v : a)
        {
            out << (first ? "" : ", ");
            out << v;
            first = 0;
        }
        out << "]";
        return out;
    }
    template <typename T, class Cmp>
    ostream &operator<<(ostream &out, const set<T, Cmp> &a)
    {
        out << "{";
        bool first = true;
        for (auto &v : a)
        {
            out << (first ? "" : ", ");
            out << v;
            first = 0;
        }
        out << "}";
        return out;
    }
    template <typename U, typename T, class Cmp>
    ostream &operator<<(ostream &out, const map<U, T, Cmp> &a)
    {
        out << "{";
        bool first = true;
        for (auto &p : a)
        {
            out << (first ? "" : ", ");
            out << p.first << ":" << p.second;
            first = 0;
        }
        out << "}";
        return out;
    }
#ifndef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
    template <typename Arg1>
    void __f(const char *name, Arg1 &&arg1)
    {
        cerr << name << ": " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char *names, Arg1 &&arg1, Args &&...args)
    {
        const char *comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << ": " << arg1 << " |";
        __f(comma + 1, args...);
    }
}
void solve()
{
    string s;
    cin >> s;
    string temp = "#";
    for (int i = 0; i < s.size(); i++)
    {
        temp.push_back(s[i]);
        temp.push_back('#');
    }
    vector<int> p(2 * s.size() + 1, 0);
    int center = 0, right = 0, tSz = temp.size(), idx = 0, len = 1;
    for (int i = 0; i < tSz; i++)
    {
        int mirror = center - (center - i);
        if (right > i)
            p[i] = min(p[mirror], right - i);
        int l = i - (p[i] + 1);
        int r = i + (p[i] + 1);
        trace(mirror, center, i);
        while (l >= 0 && r < tSz && temp[l] == temp[r])
            --l, ++r, ++p[i];
        if (2 * p[i] + 1 > len)
            idx = i - p[i], len = 2 * p[i] + 1;
        if (i + p[i] > right)
            center = i, right = i + p[i];
    }
    string ans;
    for (auto &ch : temp.substr(idx, len))
        if (ch != '#')
            ans.push_back(ch);
    cout << ans;
}

int main()
{
    tool();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}