/*
 *  author: thisavik
 *  created: 15:21:33 03-03-2022 Thu
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../algo/debug.h"
#else
#define trace(...) 42
#endif

#define int int64_t
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

pair<int, int> extendedEuclid(int a, int b)
{
  if(b == 0)
    return {1, 0};
  auto &&[x1, y1] = extendedEuclid(b, a % b);
  int x = y1;
  int y= x1 - (a / b) * y1;
  return {x, y};
}

int32_t main(int32_t argc, char *args[])
{
  int a, b;
  cin >> a >> b;
  auto &&[x, y] = extendedEuclid(a, b);
  cout << x << " " << y << "\n";
  return 0;
}

/**
 * problem: if we have given ax + by = gcd(a,b) then find valid x, y
 * 
 * approach: 
 * we know these three equations
 * gcd(a, b) = gcd(b, a%b)
 * gcd(b, a%b) = bx1 + (a%b)*y1
 * a%b = a - (a/b)*b
 * 
 * apply those:
 * ax + by = bx1 + (a%b)*y1
 * ax + by = bx1 + (a - (a/b)*b)*y1
 * ax + by = ay1 + b(x1 - (a/b)*y1)
 * 
 * gives x = y1, y = x1 - (a/b)*y1
 */
