#include<iostream>
#include<bits/stdc++.h>
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
int main(){
  tool();
  int t;
  cin>>t;
  while(t--) {
    int n,k,ans=0;
    cin>>n>>k;
    string s;
    cin>>s;
    bool allZero = true;
    for(char& ch: s)
      if(ch == '1')
        allZero = false;
    if(allZero) {
      for(int i=0; i<n; i+=(k+1))
        ans++;
      cout << ans << "\n";
      continue;
    }
    int i=0,size=0;
    while(i<n){
      if(s[i]=='1') {
        i+=k+1;size=0;
      }
      else {
        while(s[i]=='0' && i<n) {
          size++;
          i++;
          if(size == k+1) {
            size = 0;
            ans++;
          }
        }
      }
    }
    cout << size << "\n";
    if(size == k)
      ans++;
    cout << ans << "\n";
  }
  return 0;
}