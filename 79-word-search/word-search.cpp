#define ll long long

class Solution {
public:
    int arr[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int pos) {
        if (pos == word.size()) return true; // If the entire word is found
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[pos]) {
            return false; // Out of bounds or mismatch
        }

        char temp = board[i][j]; // Temporarily store the current character
        board[i][j] = '*'; // Mark the current cell as visited
        
        // Explore in all four directions
        for (auto x : arr) {
            int ni = i + x[0];
            int nj = j + x[1];
            if (dfs(board, word, ni, nj, pos + 1)) return true; // If found in any direction, return true
        }

        board[i][j] = temp; // Restore the character
        return false; // If word is not found
    }

    bool exist(vector<vector<char>>& board, string& word) {
        int r = board.size();
        int c = board[0].size();
        
        // Iterate through the board
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (dfs(board, word, i, j, 0)) return true; // Start DFS from each cell
            }
        }
        return false; // If word is not found anywhere
    }
};
