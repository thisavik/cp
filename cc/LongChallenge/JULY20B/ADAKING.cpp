#include <bits/stdc++.h>
using namespace std;


void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

void solve() {
    int k;
    cin >> k;
    char ans[8][8];
    memset(ans, '.', sizeof(ans));
    int x = k/ 8;
    int rem = k % 8;
    // if(k < 8) 
    
    if(rem == 0 && x < 8) {
        for(int i=0; i<8; i++)
            ans[x][i]='X';
    } else {
        x++;
        for(int i=0; i<=rem; i++)
            ans[x][i]='X';
        for(int i=rem; i<8; i++)
            ans[x-1][i]='X';
    }
    ans[0][0]='O';
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++)
            cout << ans[i][j];
        cout << "\n";
    }
    cout << "\n";
}

int main() {
	tool();
	int t;
	cin >> t;
	while(t--)
	    solve();
	return 0;
}
