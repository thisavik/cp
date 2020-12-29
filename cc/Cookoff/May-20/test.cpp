#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int a[n];
	    int cnt[1001]={0};
	    for(int i=0; i<n; i++) {
	        cin >> a[i];
	    }
	    int flag=1;
	    for(int i=0; i<n && flag; i++) {
	        if(i==0)
	            cnt[a[i]] = 1;
	        else if(a[i-1]!=a[i]) {
	             if(cnt[a[i]]!=0)
    	            flag = 0;
    	         else
    	            cnt[a[i]]++;
	        } else {
	            cnt[a[i]]++;
	        }
	    }
	    sort(cnt, cnt+1001);
	    vector<int> v;
	    for(int i=0; i<1001; i++)
	        if(cnt[i]!=0)
	            v.push_back(cnt[i]);
	    for(int i=1; i<v.size() && flag; i++)
	        if(v[i] == v[i-1])
	            flag = 0;
	    if(flag == 0)
	        cout << "NO" << "\n";
	    else
	        cout << "YES" << "\n";
	}
}
