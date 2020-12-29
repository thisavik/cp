#include <iostream>
#include <vector>
using namespace std;

void tool()
{
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
    string s;
    getline(cin, s);
    vector<int> v;
    for (int i = 0; i < s.size(); i++)
    {
        string temp = "";
        while (s[i] != ' ' && i < s.size())
        {
            temp += s[i];
            i++;
        }
        v.push_back(stoi(temp));
    }
    int n = v.size();
	int sum = 0; 
	for (int i = 0; i < n; i++) 
		sum += v[i]; 
	bool dp[n+1][sum+1]; 
	for (int i = 0; i <= n; i++) 
		dp[i][0] = true; 
	for (int i = 1; i <= sum; i++) 
		dp[0][i] = false; 
	for (int i=1; i<=n; i++) 
	{ 
		for (int j=1; j<=sum; j++) 
		{ 
			dp[i][j] = dp[i-1][j];  
			if (v[i-1] <= j) 
				dp[i][j] |= dp[i-1][j-v[i-1]]; 
		} 
	} 

	int mn = sum; 
	for (int j=sum/2; j>=0; j--) 
	{ 
		if (dp[n][j] == true) 
		{ 
			mn = sum-2*j; 
			break; 
		} 
	}
    cout << (sum+mn)/2;
}