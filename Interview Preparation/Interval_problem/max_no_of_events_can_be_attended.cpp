/*
 *  author: thisavik
 *  created: 19:17:46 18-08-2021 Wed
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
int maxEvents(vector<vector<int>> &A)
{
    int n = A.size();
    sort(A.begin(), A.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0, d = 0, res = 0;
    while(!pq.empty() || i < n)
    {
        if(pq.size() == 0)
            d = A[i][0];
        while(i < n && A[i][0] <= d)
            pq.push(A[i++][1]);
        ++res, ++d;
        pq.pop();
        while(!pq.empty() && pq.top() < d)
            pq.pop();
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> events;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        events.push_back({s, e});
    }
    cout << maxEvents(events) << "\n";
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