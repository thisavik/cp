/*
 *  username: thisavik | created-at: 10:34:02 22-03-2022 Tue
 **/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../../algo/debug.h"
#else
#define trace(...) 42
#endif

#define int long long

#define FAST_IO cin.tie(0)->sync_with_stdio(0)
#define LL long long
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define EB emplace_back
#define MP make_pair
#define INS insert
#define LB lower_bound
#define UB upper_bound
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define NL '\n'

#define F0R(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define F0RR(i, n) for (int i = (n - 1); i >= 0; i--)
#define FORR(i, a, b) for (int i = a; i >= b; i++)
#define FORA(val, a) for (auto& val : a)

template <class T>
bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template <class T>
auto vect(const T& v, int n) { return vector<T>(n, v); }
template <class T, class... D>
auto vect(const T& v, int n, D... m) {
  auto vv = vect(v, m...);
  return vector<decltype(vv)>(n, vv);
}
const int N = 1e5 + 5;
const int X = 1e3 + 3;
int memo[N][X][2];

// num as R, n number of digit, x sum to form, tight represent tight constraint
int dp(string& num, int n, int x, int tight) {
  if (x < 0) return 0;
  if (n == 0) {
    return (x == 0);
  }
  int& ans = memo[n][x][tight];
  if (ans != -1) return ans;
  int tempAns = 0;
  int ub = tight ? (num[(num.size() - n)] - '0') : 9;
  for (int dig = 0; dig <= ub; ++dig) {
    tempAns += dp(num, n - 1, x - dig, tight & (dig == ub));
  }
  return ans = tempAns;
}

// s must be greater than t in integer form
string diff(string s, string t) {
  int i = s.size() - 1, j = t.size() - 1;
  while (i >= 0) {
    int cs = s[i] - '0', ct = (j >= 0 ? t[j--] - '0' : 0);
    if (cs < ct) {
      int k = i;
      while (s[k] == '0') s[k--] = '9';
      --s[k];
      cs += 10;
    }
    s[i--] = cs - ct + '0';
  }
  return s;
}

void solve(int& tc) {
  memset(memo, -1, sizeof memo);
  string l, r;
  int x;
  cin >> l >> r >> x;
  string l_1 = diff(l, "1");
  cout << dp(r, r.size(), x, 1) - dp(l_1, l_1.size(), x, 1) << endl;
}

int32_t main(int32_t argc, char* args[]) {
  FAST_IO;
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; i++)
    solve(i);
  return 0;
}