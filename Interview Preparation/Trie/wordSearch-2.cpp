#include <iostream>
#include <vector>

using namespace std;
#define Size 26

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct TrieNode {
    char ch;
    int ends;
    string word;
    vector<TrieNode*> child;
    TrieNode(char ch) {
        this->ch = ch;
        ends = 0;
        word = "";
        child = vector<TrieNode*>(26, nullptr);
    }
};

class Trie {

    TrieNode* root;

public:
    TrieNode* getRoot() {
        return root;
    }

    Trie(vector<string>& words) {
        root = new TrieNode('/');
        for(int i = 0; i < words.size(); i++)
            insert(words[i]);
    }

    void insert(string& s) {
        TrieNode *curr = root;
        int idx, i = 0;
        while(s[i]) {
            idx = s[i] - 'A';
            if(curr->child[idx] == NULL) 
                curr->child[idx] = new TrieNode(s[i]);
            curr = curr->child[idx];
            i++;
        }
        curr->ends++;
        curr->word = s;    
    }
};

bool isValid(vector<vector<char>> grid, int r, int c) {
    if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '$')
        return false;
    return true;
}

void findWord(vector<vector<char>>& grid, int r, int c, vector<string>& res, TrieNode* curr) {
    int idx = grid[r][c] - 'A';
    if(grid[r][c] == '$' || curr->child[idx] == nullptr)
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
        if(isValid(grid, rNew, cNew))
            findWord(grid, rNew, cNew, res, curr);
    }

    grid[r][c] = ch;

}

void TraverseGrid(vector<vector<char>>& grid, vector<string>& words) {
    int r = grid.size();
    int c = grid[0].size();

    Trie* trie = new Trie(words);
    
    TrieNode* root = trie->getRoot();

    vector<string> res;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            findWord(grid, i, j, res, root);
        }
    }
    for(auto& word: res) {
        cout << word << "\n";
    }
}

void solve() {
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }
    int r, c;
    cin >> r >> c;
    vector<vector<char>> board(r, vector<char>(c));
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> board[i][j];
    TraverseGrid(board, words);
}

int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--) {
		solve();
    }
	return 0;
}