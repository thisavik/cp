/*
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

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}


bool isValid(int r, int c) {
    if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '$')
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

// void findWord(int r, int c, string& word) {
//     visited[r][c] = true;
//     word += grid[r][c];

//     // cout << word << "\n";

//     if(isAvaliable(word)) {
//         cout << word << "\n";
//     }

//     for(int i = 0; i < 8; i++) {
//         int rNew = r + dx[i];
//         int cNew = c + dy[i];
//         if(isValid(rNew, cNew))
//             findWord(rNew, cNew, word);
//     }

//     // for(int rNew = r-1; rNew <= r+1; rNew++) {
//     //     for(int cNew = c-1; cNew <= c+1; cNew++) {
//     //         if(isValid(rNew, cNew))
//     //             findWord(rNew, cNew, word);
//     //     }
//     // }

//     visited[r][c] = false;
//     word.erase(word.length() - 1);
// }

void findWord(int r, int c, string& word) {
    word += grid[r][c];
    grid[r][c] = '$';
    // cout << word << "\n";

    if(isAvaliable(word)) {
        cout << word << "\n";
    }

    for(int i = 0; i < 8; i++) {
        int rNew = r + dx[i];
        int cNew = c + dy[i];
        if(isValid(rNew, cNew))
            findWord(rNew, cNew, word);
    }

    // for(int rNew = r-1; rNew <= r+1; rNew++) {
    //     for(int cNew = c-1; cNew <= c+1; cNew++) {
    //         if(isValid(rNew, cNew))
    //             findWord(rNew, cNew, word);
    //     }
    // }
    grid[r][c] = word[word.length()-1];
    word.erase(word.length() - 1);
}

void TraverseGrid() {
    string word = "";
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            findWord(i, j, word);
        }
    }
}

int32_t main() {
    tool();
    TraverseGrid();
}


*/


#include <bits/stdc++.h>
using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};


bool isValid(int r, int c, vector<vector<char>>& grid) {
    if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '$')
        return false;
    return true;
}

struct Trie {
    char ch;
    int ends;
    string word;
    Trie* child[26];
    Trie(char ch) {
        this->ch = ch;
        ends = 0;
        word = "";
        for(int i = 0; i < 26; i++)
            this->child[i] = NULL;
    }
};

Trie *root = new Trie('/');

void insert(string s) {
    Trie *curr = root;
    int idx;
    for(int i = 0; i < s.size(); i++) {
        idx = s[i] - 'a';
        if(curr->child[idx] == NULL)
            curr->child[idx] = new Trie(s[i]);
        curr = curr->child[idx];
    }
    curr->ends++;
    curr->word = s;
}

void findWords(vector<vector<char>>& grid, int r, int c, Trie* curr, vector<string>& res) {
    int idx = grid[r][c] - 'a';
    if(grid[r][c] == '$' || curr->child[idx] == NULL)
        return;
        
    curr = curr->child[idx];
    
    if(curr->ends > 0) {
        res.push_back(curr->word);
        curr->ends--;
    }
    
    char ch = grid[r][c];
    grid[r][c] = '$';
    
    for(int i = 0; i < 8; i++) {
        int rNew = r + dx[i];
        int cNew = c + dy[i];
        if(isValid(rNew, cNew, grid))
            findWords(grid, rNew, cNew, curr, res);
    }
    
    grid[r][c] = ch;
}

void solve() {
    int n;
    cin >> n;
    vector<string> words(n);
    for(auto& word: words) {
        cin >> word;
        insert(word);
    }
    
    int r, c;
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    for(auto& v: grid)
        for(auto& ch: v)
            cin >> ch;
    vector<string> res;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) 
            findWords(grid, i, j, root, res);
    }
    
    for(auto& word: res)
        cout << word << " ";
    cout << "\n";
}

int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}