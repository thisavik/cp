#include <iostream>
#include <queue>
using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
}

int32_t main() {
    tool();
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    int u = 0, d = n-1, l = 0, r = m-1;
    bool flag = true;
    while(l <= r && u <= d) {
        int x; cin >> x;
        deque<int> q;
        for(int i = l; i <= r; i++)
            q.push_back(a[u][i]);
        u++;
        for(int i = u; i <= d; i++)
            q.push_back(a[i][r]);
        r--;
        for(int i = r; i >= l; i--)
            q.push_back(a[d][i]);
        d--;
        for(int i = d; i >= u; i--)
            q.push_back(a[i][l]);
        l++;
        u--, r++, d++, l--;
        // anticlockwise
        if(flag) {
            while(x--) {
                int y = q.front(); q.pop_front();
                q.push_back(y);
            }
            // flag = false;
        }
        // // clockwise
        // else {
        //     while(x--) {
        //         int y = q.back(); q.pop_back();
        //         q.push_front(y);
        //     }
        //     flag = true;
        // }
        for(int i = l; i <= r; i++)
            a[u][i] = q.front(), q.pop_front();
        u++;
        for(int i = u; i <= d; i++)
            a[i][r] = q.front(), q.pop_front();
        r--;
        for(int i = r; i >= l; i--)
            a[d][i] = q.front(), q.pop_front();
        d--;
        for(int i = d; i >= u; i--)
            a[i][l] = q.front(), q.pop_front();
        l++;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}