// you have just given a string and you have to print all the permutation of the string
// problem solved using backtracking

#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << "[" << #x << " = " << x<< "] " 

void swap(char &c1, char &c2)
{
	char temp = c1;
	c1 = c2;
	c2 = temp;
}
void printAllPermutation(string str, int i, int n)
{
	// base case
	if (i == n - 1)
	{
		cout << str << "  ";
		return;
	}
	for (int j = i; j < n; j++)
	{
		swap(str[i], str[j]);

		printAllPermutation(str, i + 1, n);

		swap(str[i], str[j]);
	}
}

void permute(string s, string answer)
{
	if (s.length() == 0)
	{
		cout << answer << "  ";
		return;
	}
	for (int i = 0; i < s.length(); i++)
	{
		char ch = s[i];
		string left_substr = s.substr(0, i);
		string right_substr = s.substr(i + 1);
		string rest = left_substr + right_substr;
		cout << "\n";
		permute(rest, answer + ch);
	}
}

int main()
{
	string str;
	cin >> str;
	cout << "All permutations are as follows : \n";
	// printAllPermutation(str, 0, str.size());
	// cout << "\n";
	permute(str, "");
}

