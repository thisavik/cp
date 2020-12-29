#include <iostream>
#include <queue>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

int32_t main() {
    tool();
    int n;
    cin >> n;
    string bride, groom;
    cin >> bride >> groom;

    int r_cnt_bride = 0, r_cnt_groom = 0;
    int m_cnt_bride = 0, m_cnt_groom = 0;
    for(char& ch: bride)
        if(ch == 'r')
            r_cnt_bride++;
        else
            m_cnt_bride++;

    for(char& ch: groom)
        if(ch == 'r')
            r_cnt_groom++;
        else
            m_cnt_groom++;           

    if(r_cnt_bride == r_cnt_groom) {
        cout << 0;
        return 0;
    }
    queue<char> q;
    for(int i = 0; i < n; i++)
        q.push(groom[i]);
    int i = 0;
    while(!q.empty()) {
        cout << bride[i] << " " << q.front() << " " << q.size() << "\n";
        if(q.front() == bride[i]) {
            if(bride[i] == 'r') {
                r_cnt_bride--;
                r_cnt_groom--;
            } else {
                m_cnt_bride--;
                m_cnt_groom--;
            }
            q.pop(); i++;
        } else {
            if((bride[i] == 'r' && r_cnt_groom == 0) || (bride[i] == 'm' && m_cnt_groom == 0)) {
                cout << q.size();
                return 0;
            } 
            char ch = q.front();
            q.pop();
            q.push(ch);
        }
        // cout << r_cnt_bride << " " << m_cnt_bride << "\n";
        // cout << r_cnt_groom << " " << m_cnt_groom << "\n";
    }
    return 0;
}