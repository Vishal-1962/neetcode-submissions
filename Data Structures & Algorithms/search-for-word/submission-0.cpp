class Solution {
public:
    bool search(vector<vector<char>>& board, string word,
                int i, int j, int idx) {

        // Word found
        if (idx == word.size())
            return true;

        // Out of bounds
        if (i < 0 || j < 0 ||
            i >= board.size() || j >= board[0].size())
            return false;

        // Character doesn't match
        if (board[i][j] != word[idx])
            return false;

        // Mark as visited
        char ch = board[i][j];
        board[i][j] = '#';

        // Explore 4 directions
        bool found = search(board, word, i + 1, j, idx + 1) ||
                     search(board, word, i - 1, j, idx + 1) ||
                     search(board, word, i, j + 1, idx + 1) ||
                     search(board, word, i, j - 1, idx + 1);

        // Backtrack
        board[i][j] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0]) {
                    if (search(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};