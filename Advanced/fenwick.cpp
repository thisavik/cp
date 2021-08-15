#include <bits/stdc++.h>
using namespace std;

struct BIT
{
    vector<int> bit;
    int n;
    BIT(int n) : n(n + 1)
    {
        bit.resize(this->n, 0);
    }

    void update(int idx, int val)
    {
        for (int i = idx; i <= n; i += (i & (-i)))
            bit[i] += val;
    }

    int sum(int idx)
    {
        int ans = 0;
        for (int i = idx; i > 0; i -= (i & (-i)))
            ans += bit[i];
        return ans;
    }
};

int main()
{
}
