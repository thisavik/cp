#include<iostream>
#include<vector>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}
void printSol(vii& sol, int n) {
  for(auto& v: sol) {
    for(int& val: v) {
      cout << val << " ";
    }
    cout << "\n";
  }  
}
bool isValid(vii& mat, vii& sol, int x, int y, int n) {
  if(x >= n || y >=n || x < 0 || y < 0 || mat[x][y] == 0 || sol[x][y] == 1)
    return false;
  return true;
}

void solve(vii& mat, int n, vii& sol, int x, int y) {

  if(x == n-1 && y == n-1) {
    sol[x][y] = 1;
    printSol(sol, n);
    sol[x][y] = 0;
    return;
  }
  if(!(isValid(mat, sol, x, y, n)))
    return;
  // including own pos in solution if valid
  sol[x][y] = 1;

  // exploring up
  solve(mat, n, sol, x-1, y);
  // exploring down
  solve(mat, n, sol, x+1, y);
  // exploring left
  solve(mat, n, sol, x, y-1);
  // exploring right
  solve(mat, n, sol, x, y+1);

  // after exploring all from our pos again 
  // I have to return back for exploring other position from which we may came in that place again 
  // so make it 0
  sol[x][y] = 0;
}

void ratInAMaze(vii& mat, int n) {

  vii sol (n, vi(n, 0));

  solve(mat, n, sol, 0, 0);
}
int main() {
  tool();
  int t;
  cin >> t;
  int n;
  cin >> n;
  vii mat (n, vi(n, 0));
  for(auto& v: mat) {
    for(int& val: v) {
      cin >> val;
    }
  } 

  ratInAMaze(mat, n);
  return 0;
}