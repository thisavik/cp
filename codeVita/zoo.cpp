#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
}

int32_t main() {
    tool();
    vector<pair<int, int>> cost;
    for(int i = 0; i < 3; i++) {
        int x; cin >> x;
        cost.push_back({x, i});
    }
    sort(cost.begin(), cost.end());
    vector<int> maxArea(3);
    for(int i = 0; i < 3; i++)
        cin >> maxArea[i];
    int area[3];
    for(int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        area[i] = x*y;
    }
    int totalArea;
    cin >> totalArea;
    int ans = 0;
    for(int i = 2; i >= 0; i--) {
        ans += cost[i].first * area[cost[i].second];
        maxArea[cost[i].second] -= area[cost[i].second];
        totalArea -= area[cost[i].second];
    }

    for(int i = 0; i < 3 && totalArea != 0; i++) {
        if(totalArea > maxArea[cost[i].second]) {
            ans += cost[i].first * maxArea[cost[i].second];
            totalArea -= maxArea[cost[i].second];
        } else {
            ans += cost[i].first * totalArea;
            totalArea = 0;
        }
    }
    cout << ans;
    return 0;
}