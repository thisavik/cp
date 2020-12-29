#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int ar[], int n) {
  int flag=1;
  for(int i=0; i<n && flag; i++) {
    flag=0;
    for(int j=0; j<n-1-i; j++) {
      if(ar[j] > ar[j+1]) {
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


  bubbleSort(a, n);

  for(int i=0; i<n; i++) {
    cout << a[i] << ",";
  }
}