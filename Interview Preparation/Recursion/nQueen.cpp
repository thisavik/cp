#include <iostream>
#include <vector>

using namespace std;
int cnt = 0, n;
vector<vector<int>> ans;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C://git//cp//input.txt", "r", stdin);
    freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

bool isSafe(vector<vector<char>> &chessBoard, int r, int c)
{

    // check for same column
    for (int i = 0; i < r; i++)
        if (chessBoard[i][c] == 'Q')
            return false;

    // check for principle diagonal i.e '\'
    for (int i = r, j = c; j >= 0 && i >= 0; i--, j--)
        if (chessBoard[i][j] == 'Q')
            return false;

    // check for other diagonal i.e '/'
    for (int i = r, j = c; i >= 0 && j < n; i--, j++)
        if (chessBoard[i][j] == 'Q')
            return false;

    // in all other cond. return true
    return true;
}

void printBoard(vector<vector<char>> &chessBoard)
{
    vector<int> temp;
    for (auto &v : chessBoard)
    {
        for (int i = 0; i < v.size(); i++)
            if (v[i] == 'Q')
                temp.push_back(i + 1);
    }
    ans.push_back(temp);
}

void nQueen(vector<vector<char>> &chessBoard, int r)
{
    // base cond.
    if (r == n)
    {
        printBoard(chessBoard);
        cnt++;
        return;
    }
    // check for each column(j) for row(r)
    for (int j = 0; j < n; j++)
    {

        // check if place if safe or not
        if (isSafe(chessBoard, r, j))
        {
            // place Queen there
            chessBoard[r][j] = 'Q';

            // if valid the check for other row(r+1)
            nQueen(chessBoard, r + 1);

            // backtrack and remove queen from current square
            chessBoard[r][j] = '-';
        }
    }
}

int32_t main()
{
    tool();
    cin >> n;
    vector<vector<char>> chessBoard(n, vector<char>(n, '-'));
    nQueen(chessBoard, 0);
    for (auto &v : ans)
    {
        cout << "[";
        for (int &val : v)
            cout << val << " ";
        cout << "]\n";
    }
}