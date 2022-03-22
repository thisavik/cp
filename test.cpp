#include <bits/stdc++.h>
using namespace std;

vector<int> str_to_array(string s) {
    vector<int> v;
    string temp = "";
    for(int i = 0; i < s.size(); i++) {
        cout << s[i] << "\n";
        if(isdigit(s[i])) {
            temp.push_back(s[i]);
        } else {
            v.push_back(stoi(temp));
            temp = "";
        }
    }
    return v;
}

int main() {
    vector<int> ans = str_to_array("[10, 20, 30]");
    for(auto val: ans)
        cout << val << " ";
    return 0;
}