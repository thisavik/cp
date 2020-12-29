#include <bits/stdc++.h>
using namespace std;
int res(int a1, int a2, int b1, int b2) {
    return 10*a1 + a2 + 10*b1 + b2;
}
int main() {
  int t;
  cin >> t;
  while(t--){
    int a, b;
    cin >> a >> b ;
    int a1 = a/10, a2 = a%10, b1 = b/10, b2 = b%10;
    if(a1 == 0 && b1 == 0){
      cout << (a + b) << endl;
      continue;
    }
    if(a1 == 0){
        if(a2 > b1){
            cout << (10*a2 + b2 + b1) << endl;
        }
        else{
            cout << (a + b) << endl;
        }
        continue;
    }
    if(b1 == 0){
        if(b2 > a1){
            cout << (10*b2 + a2 + a1) << endl;
        }
        else{
            cout << (a + b) << endl;
        }
        continue;
    }
    int mx = a + b;
    mx = max(mx, res(a1, b1, a2, b2));
    mx = max(mx, res(b2, a2, b1, a1));
    cout << mx << "\n";
  }
}