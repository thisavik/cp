#include <iostream>
#include <queue>
#include <vector>

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

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int& val: a)
        cin >> val;
    vector<int> ans;
    deque<int> dq;
    
    // process for first k element
    for(int i = 0; i < k; i++) {
        while(!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();
        dq.push_back(i);
    }
    ans.push_back(a[dq.front()]);

    for(int i = k; i < n; i++) {
        // remove indexes which are not in our window
        while(!dq.empty() && dq.front() <= i-k)
            dq.pop_front();
        
        // remove unnecessary elements 
        while(!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();

        // add new element
        dq.push_back(i);
        ans.push_back(a[dq.front()]);
    }
    for(int val: ans)
        cout << val << " ";
    cout << "\n";
}

int32_t main() {
    tool();
    int t = 1;
    while(t--)
        solve();
    return 0;
}

/*
// nlog(k) solution with BST
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    if(n == 0 || k > n)
        return ans;
    int mn
    for(int i = 0; i < k; i++)
        s.insert(nums[i]);
    for(int val: s)
        cout << val << " ";
    cout << "\n";
    ans.push_back(*(--s.end()));
    for(int i = k; i < n; i++) {
        s.erase(s.find(nums[i-k]));
        s.insert(nums[i]);
        ans.push_back(*(--s.end()));
    }
    return ans;
}
*/