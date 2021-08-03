/*
 *  author: thisavik
 *  created: 21:38:06 01-08-2021 Sun
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define range(i, a, b) for (int i = a; i <= b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

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

void tool()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

struct segTree
{
  int size;
  vector<int> seg;
  vector<int> lazy;
  segTree(int n)
  {
    size = 4 * n + 1;
    seg.resize(size, 0);
    lazy.resize(size, 0);
  }
  int build(vector<int> &arr, int s, int e, int idx)
  {
    if (s > e)
      return 0;
    if (s == e)
      return seg[idx] = arr[s];
    int mid = (s + e) / 2;
    return seg[idx] = __gcd(build(arr, s, mid, 2 * idx + 1), build(arr, mid + 1, e, 2 * idx + 2));
  }
  int query(int s, int e, int &qs, int &qe, int idx)
  {
    if (s > e || qs > e || qe < s)
      return 0;
    if (s >= qs && e <= qe)
      return seg[idx];
    int mid = (s + e) / 2;
    return __gcd(query(s, mid, qs, qe, 2 * idx + 1), query(mid + 1, e, qs, qe, 2 * idx + 2));
  }
  int update(int s, int e, int val, int idx)
  {
    if (s > e)
      return 0;
    if (s == e)
      return seg[idx] += val;
    int mid = (s + e) / 2;
    return seg[idx] = max(update(s, mid, val, 2 * idx + 1), update(mid + 1, e, val, 2 * idx + 2));
  }
  int updateRange(int s, int e, int val, int qs, int qe, int idx)
  {
    if (s > e || s > qe || e < qe)
      return 0;

    if (lazy[idx] != 0 && s != e)
    {
      lazy[2 * idx + 1] += lazy[idx];
      lazy[2 * idx + 2] += lazy[idx];
      lazy[idx] = 0;
    }

    if (s >= qs && e <= qe)
    {
      seg[idx] += val;
      if (s != e)
      {
        lazy[2 * idx + 1] += val;
        lazy[2 * idx + 2] += val;
      }
    }

    int mid = (s + e) / 2;
    return seg[idx] = max(updateRange(s, mid, val, qs, qe, 2 * idx + 1), updateRange(mid+1, e, val, qs, qe, 2 * idx + 2));
  }
};

void solve()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &val : v)
    cin >> val;
  if (n == 1)
  {
    cout << "1\n";
    return;
  }
  vector<int> diff(n - 1);
  for (int i = 0; i < n - 1; i++)
    diff[i] = abs(v[i + 1] - v[i]);
  segTree tree(n - 1);
  tree.build(diff, 0, n - 2, 0);
  int s = 0, e = 0, maxLen = 1, gcd = diff[s];
  while (e < n - 1)
  {
    int num = diff[e];
    gcd = __gcd(gcd, num);
    while (gcd == 1 && s < e)
    {
      s++;
      gcd = tree.query(0, n - 2, s, e, 0);
    }
    if (gcd != 1)
      maxLen = max(maxLen, e - s + 2);
    e++;
  }
  cout << maxLen << "\n";
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