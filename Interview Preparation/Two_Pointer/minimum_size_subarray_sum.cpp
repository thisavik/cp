#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

/*
// two-pointer
int solve(vector<int>& a, int target) {
    int n = a.size();
    int s = 0, e = 0, sum = 0, minLen = n+1;
    while(e < n) {
        sum += a[e];
        while(sum >= target && s <= e) {
            minLen = min(minLen, e-s+1);
            sum -= a[s];
            s++;
        }
        e++;
    }
    return minLen == n+1 ? 0 : minLen;
}
*/

// binary-search method
int solve(vector<int>& a, int target) {
    int n = a.size(), minLen = n+1;
    if(n == 0) return 0;

    vector<int> prefix(n+1, 0);
    for(int i = 1; i <= n; i++)
        prefix[i] = prefix[i-1] + a[i-1];
        
    for(int i = n; i >= 0 && prefix[i] >= target; i--) {
        int j = upper_bound(prefix.begin(), prefix.end(), prefix[i]-target) - prefix.begin();
        minLen = min(minLen, i-j+1);
    }
    return minLen == n+1 ? 0 : minLen;
}

/*
// prefix sum method
int solve(vector<int>& a, int target) {
    int prefix[n+1] = {0}, minLen = n+1;
    for(int i = 1; i <= n; i++) 
        prefix[i] = prefix[i-1]+a[i-1];
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++)
            if(prefix[i]-prefix[j] >= k)
                minLen = min(minLen, i-j);
    }
    return minLen != n+1 ? minLen : 0;
}
*/

int32_t main() {
    tool();
    int n, sum;
    cin >> n >> sum;
    vector<int> a(n);
    for(int& val: a)
        cin >> val;
    cout << solve(a, sum);
}

// explaination of binary search solution
/*
First, we maintain an array of accumulated sums of elements in nums according to the following two equations.

1. sums[0] = 0
2. sums[i] = nums[0] + ... + nums[i - 1] for i > 0
Then, for each sums[i] >= s, we search for the first sums[j] > sums[i] - s (j < i) using binary search. In this case, we also have sums[j - 1] <= sums[i] - s. If we plug in the definition for sums, we have

* nums[0] + ... + nums[j - 1] > nums[0] + ... + nums[j - 1] + nums[j] + ... + nums[i - 1] - s
* nums[0] + ... + nums[j - 2] <= nums[0] + ... + nums[j - 2] + nums[j - 1] + ... + nums[i - 1] - s
If we minus the left-hand side from both inequalities, we have

* 0 > nums[j] + ... + nums[i - 1] - s
* 0 <= nums[j - 1] + ... + nums[i - 1] - s
So, we have nums[j - 1] + ... + nums[i - 1] >= s but nums[j] + ... + nums[i - 1] < s. So nums[j-1..i-1] is the shortest subarray with sum not less than s ending at i - 1. After traversing all possible i, we will find out the shortest subarray with sum not less than s.

By the way, a 0 is added to the head of sums to account for cases like nums = [3], s = 3.

*/