#include <iostream>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
}

int32_t main() {
    tool();
    int n;
    cin >> n;
    string s;
    cin >> s;
    int Acnt = 0, Bcnt = 0;
    for(char ch: s)
        if(ch == 'A') Acnt++;
        else if(ch == 'B') Bcnt++;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        char ch = s[i];
        if(ch == 'A' || ch == 'B') {
            continue;
        }
        cnt++;
        // consider '---A' case
        char pre = i-1 >= 0 ? s[i-1] : 'A';
        // consider 'B---' case
        char next = i+1 < n ? s[i+1] : 'B';
        // count continues '-'
        while(next == '-') {
            cnt++;
            i++;
            next = i+1 < n ? s[i+1] : 'B';
        }
        // 'A---A'
        if(pre == 'A' && next == 'A') {
            Acnt += cnt;
        }
        // 'B---A'
        else if(pre == 'B' && next == 'A') {
            Acnt += cnt/2, Bcnt += cnt/2;
        }
        // 'B---B'
        else if(pre == 'B' && next == 'B') {
            Bcnt += cnt;
        }
    }
    if(Acnt > Bcnt)
        cout << "A";
    else if(Acnt < Bcnt)
        cout << "B";
    else
        cout << "Coalition government";
    return 0;
}