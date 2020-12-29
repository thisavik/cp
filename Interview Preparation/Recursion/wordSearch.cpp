#include <iostream>
#include <vector>

using namespace std;
vector<vector<char>> grid = {
    {'G', 'I', 'Z'},
    {'U', 'E', 'K'},
    {'Q', 'S', 'E'}
};

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

bool dfs(int r, int c, int cnt, string& word) {

    if(cnt == word.size()) {
        return true;
    }

    if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || word[cnt] != grid[r][c]) {
        return false;
    }

    char temp = grid[r][c];
    grid[r][c] = '$';
    bool found = dfs(r-1, c, cnt+1, word) 
                || dfs(r, c+1, cnt+1, word)
                || dfs(r+1, c, cnt+1, word) 
                || dfs(r, c-1, cnt+1, word);
    grid[r][c] = temp;
    return found;
}

bool searchWord(string& word) {
    for(int r = 0; r < grid.size(); r++) {
        for(int c = 0; c < grid[r].size(); c++) {
            if(grid[r][c] == word[0] && dfs(r, c, 0, word)) {
                return true;
            }
        }
    }
    return false;
}

int32_t main() {
    tool();
    string word;
    cin >> word;
    cout << boolalpha;
    cout << searchWord(word);
}