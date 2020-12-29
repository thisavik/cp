#include <iostream>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
}

int sudoku[9][9];

void printSudoku();

bool isSafe(int r, int c, int k)
{
    // check for same element in column
    for(int i = 0; i < 9; i++)
        if(sudoku[r][i] == k)
            return false;
    // check for same element in row
    for(int i = 0; i < 9; i++)
        if(sudoku[i][c] == k)
            return false;
    // calculate (top, left) position of subgrid of which this cell is part
    int R = (r/3)*3, C = (c/3)*3;
    // check for same element in subgrid
    for(int i = R; i <= R+2; i++)
        for(int j = C; j <= C+2; j++)
            if(sudoku[i][j] == k)
                return false;
    return true;
}

bool solve(int r, int c)
{
    if(r == 8 && c == 9)
    {
        return true;
    }

    if(c == 9)
    {
        return solve(r+1, 0);
    }

    // if that particular cell already fill
    if(sudoku[r][c] != 0)
    {
        return solve(r, c+1);
    }

    // for empty cell
    for(int i = 1; i <= 9; i++)
    {
        if(isSafe(r, c, i))
        {
            sudoku[r][c] = i;

            if(solve(r, c+1))
                return true;

            sudoku[r][c] = 0;            
        }
    }
    return false;
}

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while(t--)
    {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                cin >> sudoku[i][j];
        
        if(solve(0, 0))
            printSudoku();
        cout << "\n";
    }
    return 0;
}

void printSudoku()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
            cout << sudoku[i][j] << " ";
    }
}

/*
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
*/