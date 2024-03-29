/*
 *  author: thisavik
 *  created: 20:42:20 19-08-2021 Thu
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

map<string, vector<string>> userWithFavGenres(map<string, vector<string>> &userSongs, map<string, vector<string>> &songGenres)
{
    map<string, string> mp;
    for (auto &songGenre : songGenres)
    {
        for (auto &song : songGenre.second)
            mp[song] = songGenre.first;
    }
    map<string, vector<string>> ans;
    map<string, int> cnt;
    for (auto &userSong : userSongs)
    {
        int mx = 0;
        for (auto &song : userSong.second)
        {
            cnt[mp[song]]++;
            if (mx < cnt[mp[song]])
                mx = cnt[mp[song]];
        }
        for (auto &p : cnt)
            if (p.second == mx)
                ans[userSong.first].push_back(p.first);
        cnt.clear();
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n;
    string str, s;
    map<string, vector<string>> userSongs, songGenres;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> str;
        for (int j = 0; j < m; j++)
            cin >> s, userSongs[str].push_back(s);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> str;
        for (int j = 0; j < m; j++)
            cin >> s, songGenres[str].push_back(s);
    }
    map<string, vector<string>> ans = userWithFavGenres(userSongs, songGenres);
    trace(ans);
}

int32_t main(int32_t argc, char *args[])
{
    tool();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}