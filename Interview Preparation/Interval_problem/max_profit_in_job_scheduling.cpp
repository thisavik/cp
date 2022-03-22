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

struct Job
{
    int start, end, profit;
};

void solve()
{
    int n;
    cin >> n;
    vector<Job> interval;
    for (int i = 0; i < n; i++)
    {
        int start, end, profit;
        cin >> start >> end >> profit;
        interval.push_back({start, end, profit});
    }
    sort(interval.begin(), interval.end(), [](Job &a, Job &b)
         { return a.end < b.end; });
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[0] = interval[i].profit;
            continue;
        }
        int lastProfit = 0;
        int l = 0, h = i;
        while(l <= h)
        {
            int mid = l + (h - l)/2;
            if(interval[mid].end <= interval[i].start)
                lastProfit = dp[mid], l = mid + 1;
            else
                h = mid - 1;
        }
        dp[i] = max(dp[i - 1], lastProfit + interval[i].profit);
    }
    cout << dp << "\n";
    trace(dp);
    cout << dp[n - 1];
}

int main()
{
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}