#include <iostream>
#include <vector>

using namespace std;
#define Size 26

vector<vector<char>> grid = {
    {'G', 'I', 'Z'},
    {'U', 'E', 'K'},
    {'Q', 'S', 'E'}
};

vector<string> dictionary = {"GEEKS", "FOR", "NO", "QUIZ"};

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Trie {
    char ch;
    int ends;
    Trie* child[Size];
    string word;
    Trie() {}
    Trie(char ch) {
        this->ch = ch;
        ends = 0;
        word = "";
        for(int i = 0; i < Size; i++)
            this->child[i] = NULL; 
    }
};

Trie *root = new Trie('/');

void insert(string s) {
    Trie *curr = root;
    int idx, i = 0;
    while(s[i]) {
        idx = s[i] - 'a';
        if(curr->child[idx] == NULL) 
            curr->child[idx] = new Trie(s[i]);
        curr = curr->child[idx];
        i++;
    }
    curr->ends++;
    curr->word = s;
}

bool isValid(int r, int c) {
    if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '$')
        return false;
    return true;
}

void findWord(int r, int c, vector<string>& res, Trie* curr) {
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
        if(isValid(rNew, cNew)) 
            findWord(rNew, cNew, res, curr);
    }

    grid[r][c] = ch;

}

void TraverseGrid() {
    int r = grid.size();
    int c = grid[0].size();

    for(auto& word: dictionary)
        insert(word);
    
    vector<string> res;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            findWord(i, j, res, root);
        }
    }
    for(auto& word: res) {
        cout << "Found : " << word << "\n";
    }
}

int32_t main() {
    TraverseGrid();
}