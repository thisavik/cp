#include <bits/stdc++.h>

using namespace std;

int D[10] = { 1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
int power2[4] = { 6, 2, 4, 8 };

int lastNonZeroInFact(int n)
{
  // base case
  if(n < 10)
    return D[n];
  
  int ans = 1, cnt5 = n / 5, rem = n % 5;
  for(int i = 0; i < rem; i++)
    ans *= (n - i) % 10, ans %= 10;
  ans *= power2[cnt5 % 4] * lastNonZeroInFact(cnt5);
  return ans % 10;
}

int32_t main()
{
  int n = 1003;
  cout << lastNonZeroInFact(n) << "\n";
}