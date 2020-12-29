#include <iostream>
#include <vector>

using namespace std;
vector<vector<char>> grid = {
    {'G', 'I', 'Z'},
    {'U', 'E', 'K'},
    {'Q', 'S', 'E'}
};
vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

vector<string> dictionary = {"GEEKS", "FOR", "NO", "QUIZ"};

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}


bool isValid(int r, int c) {
    if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || visited[r][c])
        return false;
    return true;
}

bool isAvaliable(string word) {
    for(auto& s: dictionary) {
        if(s == word) 
            return true;
    }
    return false;
}

void SearchWord(int row, int col, string& word) {
    // cout << word << "\n";
    if (isAvaliable(word)){
        cout << word << "\n";
    }
    for (int r = row-1; r <= row+1; r++) {
        for (int c = col-1; c <= col+1; c++) {
            if (isValid(r, c)) {
                visited[r][c] = true;
                word.push_back(grid[r][c]);
                SearchWord(r, c, word);
                word.pop_back();
                visited[r][c] = false;
            }
        }
    }
    
}

void TraverseGrid() {
    string word;
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
            visited[row][col] = true;
            word.push_back(grid[row][col]);
            SearchWord(row, col, word);
            visited[row][col] = false;
            word.pop_back();
        }
    }
}

int32_t main() {
    tool();
    TraverseGrid();
}