// you have just given a string and you have to print all the permutation of the string 
// problem solved using backtracking


#include <bits/stdc++.h>
using namespace std;

void swap(char& c1, char& c2) {
	char temp = c1;
	c1 =  c2;
	c2 = temp;
}
void printAllPermutation(string str, int i, int n){
	// base case 
	if(i == n-1) {
		cout << str << endl;
		return;
	}
	for(int j = i; j<n; j++) {
		swap(str[i], str[j]);

		printAllPermutation(str, i+1, n);

		swap(str[i], str[j]);
	}
}

int main() {
	string str;
	cin >> str;
	cout << "All permutations are as follows : \n";
	printAllPermutation(str, 0, str.size());
}