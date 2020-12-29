#include <bits/stdc++.h>
using namespace std;
void printCross(int a[][5], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<5; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
  int i=n-1,j=0;
}
int main() {
	int a[5][5];
	for(int i=0; i<5; i++){
		for(int j=0; i<5; j++)
      a[i][j]=i+j;
	}
	printCross(a, 5);
	return 0;
}