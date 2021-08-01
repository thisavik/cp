/*
 *  author: thisavik
 *  created: 21:49:19 30-07-2021 Fri
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, n) for (int i = 0; i < n; i++)
#define range(i, a, b) for (int i = a; i <= b; i++)
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

int helper(string &s1, string &s2, int &l, int &r)
{
  int changes = 0;
  for(int i = l; i <= r; i++)
    changes += (s1[i] != s2[i]);
  return changes;
}

int32_t main(int32_t argc, char *args[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<string> perm = {"abc", "acb", "bac", "bca", "cab", "cba"};
  vector<string> possible(6);
  for(int i = 0; i < 6; i++)
  {
    for(int j = 0; j < n; j++)
    {
      possible[i].push_back(perm[i][j % 3]);
    }
  }
  trace(possible);
  for(int i = 0; i < m; i++)
  {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int ans = INT_MAX;
    for(int i = 0; i < 6; i++)
    {
      ans = min(ans, helper(possible[i], s, l, r));
    }
    cout << ans << "\n";
  }
  return 0;
}