#include<bits/stdc++.h>
using namespace std;
class cell {
    public:
        int r, c, k;
        cell(int r, int c, int k){
            this->r = r;
            this->c = c;
            this->k = k;
        }
};
bool isValid(cell p, int k){
    if(p.r < 1 || p.r > 8 || p.c < 1 || p.c > 8 || p.k > k)
        return false;
    return true;
}
int cntPlace(int r, int c, int k){
    const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
    queue<cell> Q;
    int visited[9][9];
    memset(visited, 0, sizeof(visited));
    Q.push(cell(r, c, 0));
    visited[r][c] = 1;
    int cnt = 1;
    while(!Q.empty()){
        cell node = Q.front();
        cout << node.r <<" " << node.c << " " << node.k << "\n";
        Q.pop();
        for(int j=0; j<9; j++){
            cell neighbour(node.r + dx[j], node.c + dy[j], node.k + 1);
            if(isValid(neighbour, k) && !visited[neighbour.r][neighbour.c] ){
                Q.push(neighbour);
                visited[neighbour.r][neighbour.c] = 1;
                cnt++;
            }
        }
    }
    return cnt;
}
void solve(){
    int r, c, k;
    cin >> r >> c >> k;
    cout << cntPlace(r, c, k);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
