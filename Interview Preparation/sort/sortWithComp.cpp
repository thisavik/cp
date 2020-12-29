#include <iostream>
#include <algorithm>
using namespace std;

// Define A Comparator Function
bool compare(int a, int b) {
  // cout << "Comparing " << a << " and " << b << "\n";
  return a < b;

  // return true then swap wouldn't happen
  // return false then swap happen 
}

int main() {
  int n, key;
  cin >> n;
  int a[1000];

  for(int i=0; i<n; i++) {
    cin >> a[i];
  }


  sort(a, a+n, compare);

  for(int i=0; i<n; i++) {
    cout << a[i] << ",";
  }
}