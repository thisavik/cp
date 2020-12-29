#include <iostream>
using namespace std;

// Define A Comparator Function
bool compare(int a, int b) {
  cout << "Comparing " << a << " and " << b << "\n";
  return a>b;
}

// Bubble Sort
// Passing Function as parameter syntax "bool (&cmp)(int a, int b)"
void bubbleSort(int ar[], int n, bool (*cmp)(int a, int b)) {
  int flag=1;
  for(int i=0; i<n && flag; i++) {
    flag=0;
    for(int j=0; j<n-1-i; j++) {
      if(cmp(ar[j], ar[j+1])) {
        swap(ar[j], ar[j+1]);
        flag=1;
      }
    }
  }
}

int main() {
  int n, key;
  cin >> n;
  int a[1000];

  for(int i=0; i<n; i++) {
    cin >> a[i];
  }


  bubbleSort(a, n, compare);

  for(int i=0; i<n; i++) {
    cout << a[i] << ",";
  }
}