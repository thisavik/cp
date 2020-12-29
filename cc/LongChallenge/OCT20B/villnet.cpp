#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define rep(i, n) for(int i = 0; i < n; i++)
#define range(i, a, b) for(int i = a; i <= b; i++)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

bool isValid(int x, int y, set<pair<int, int>> &isPresent)
{
    if(abs(x)&1 && y&1 && (__gcd(abs(x),y) == 1) && (isPresent.find({x, y}) == isPresent.end()))
        return true;
    return false;
}

int bfs(int x1, int y1, int x2, int y2)
{
    if(x1 == x2 && y1 == y2)
        return 0;
    set<pair<int, int>> isPresent;
    int cost = 0;
    queue<pair<int, int>> q;
    q.push({x1, y1});
    isPresent.insert({x1, y1});
    while(1)
    {
        int cnt = q.size();
        while(cnt--)
        {
            int x = q.front().first, y = q.front().second; q.pop();
            // cout << x << " " << y << "\n";
            int xNew, yNew;
            // east
            xNew = x+2*y, yNew = y;
            if(isValid(xNew, yNew, isPresent))
            {
                if(xNew == x2 && yNew == y2)
                {
                    // cout << x2 << " " << y2 << "\n";
                    cost++;
                    return cost;
                }
                q.push({xNew, yNew});
                isPresent.insert({xNew, yNew});
            }
            // west
            xNew = x-2*y, yNew = y;
            if(isValid(xNew, yNew, isPresent))
            {
                if(xNew == x2 && yNew == y2)
                {
                    // cout << x2 << " " << y2 << "\n";
                    cost++;
                    return cost;
                }
                q.push({xNew, yNew});
                isPresent.insert({xNew, yNew});
            }
            // north
            xNew = x, yNew = y+2*x;
            if(y+2*x < 0)
                xNew = -xNew, yNew = -yNew;
            if(isValid(xNew, yNew, isPresent))
            {
                if(xNew == x2 && yNew == y2)
                {
                    // cout << x2 << " " << y2 << "\n";
                    cost++;
                    return cost;
                }
                q.push({xNew, yNew});
                isPresent.insert({xNew, yNew});
            }
            // south
            xNew = x, yNew = y-2*x;
            if(y-2*x < 0)
                xNew = -xNew, yNew = -yNew;
            if(isValid(xNew, yNew, isPresent))
            {
                if(xNew == x2 && yNew == y2)
                {
                    // cout << x2 << " " << y2 << "\n";
                    cost++;
                    return cost;
                }
                q.push({xNew, yNew});
                isPresent.insert({xNew, yNew});
            }
        }
        cost++;
    }
    return cost;
}

void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << bfs(x1, y1, x2, y2) << "\n";
}

int32_t main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

/*
5
7 5 7 5
1 1 -1 1
3 7 5 9
113 167 361765 170831
24844359 74532371 14673633991 3057007029
*/