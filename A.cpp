#include <bits/stdc++.h>
using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/thisa/OneDrive/Documents/cp/input.txt", "r", stdin);
    freopen("C:/Users/thisa/OneDrive/Documents/cp/output.txt", "w", stdout);
    freopen("C:/Users/thisa/OneDrive/Documents/cp/error.txt", "w", stderr);
#endif
}

int main()
{
    tool();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string s;
        cin >> s;
        map<char, vector<int>> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]].push_back(i);
        }
        bool flag = false;
        for (auto val : mp)
        {
            if (val.second.size() > s.size() / 2)
                flag = true;
        }
        if (flag)
        {
            cout << "Case #" << i << ": "
                 << "IMPOSSIBLE"
                 << "\n";
        }
        else
        {
            string ans = s;
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                for(char _ch = ch+1; _ch <= 'z'; _ch++)
                {
                    while(mp[ch].size() != 0)
                    {
                        if(mp[_ch].size() == 0)
                            break;
                        else
                        {
                            ans[mp[ch].back()] = _ch;
                            ans[mp[_ch].back()] = ch;
                            mp[ch].pop_back();
                            mp[_ch].pop_back();
                        }
                    }
                }
            }
            if(s.size() % 2 == 1) 
            {
                int idx = 0;
                for(int i = 0; i < ans.size(); i++)
                {
                    if(s[i] == ans[i])
                        idx = i;
                }
                cout << ans << "\n";
                for(int i = 0; i < ans.size(); i++)
                {
                    if(s[i] != ans[i] && ans[i] != ans[idx] && s[i] != s[idx]) 
                    {
                        swap(ans[i], ans[idx]);
                        break;
                    }
                }
            }
            cout << "Case #" << i << ": "
                 << ans
                 << "\n";
        }
    }
}