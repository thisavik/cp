#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i=0; i<n; i++) {
	        cin >> a[i];
	    }
	    map<int, int> fre;
	    int flag=1;
	    for(int i=0; i<n && flag; i++) {
	        if(i==0)
	            fre[a[i]] = 1;
	        else if(a[i-1]!=a[i]) {
	             if(fre[a[i]]!=0)
    	            flag = 0;
    	         else
    	            fre[a[i]]++;
	        } else {
	            fre[a[i]]++;
	        }
	    }
	    vector<int> v;
	    for(auto itr=fre.begin(); itr!=fre.end() && flag; itr++)
	        v.push_back(itr->second);
	    sort(v.begin(), v.end());
	    for(int i=1; i<v.size() && flag; i++)
	        if(v[i-1]==v[i]) {
	            flag=0;
	        }
	    if(flag == 0)
	        cout << "NO" << "\n";
	    else
	        cout << "YES" << "\n";
	}
}
