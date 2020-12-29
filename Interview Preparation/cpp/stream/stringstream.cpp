#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

int32_t main()
{
    tool();
    int n, temp;
    string str;
    cin >> n;
    getline(cin, str);
    vector<vector<int>> D2;
    for(int i = 1; i <= n; i++)
    {
        vector<int> D;
        getline(cin, str);
        stringstream ss(str);
        while (ss >> temp)
        {
            D.push_back(temp);
        }
        D2.push_back(D);
    }
    for(auto D : D2)
    {
        for(int val : D)
            cout << val << " ";
        cout << "\n";
    }
}