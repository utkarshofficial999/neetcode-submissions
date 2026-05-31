class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 1. Check all rows
        for (int row = 0; row < 9; row++) { // Fixed: changed 'i' initialization to 'row'
            unordered_set<char> seen;       // Fixed: typo 'unorderd_set'
            for (int i = 0; i < 9; i++) {
                if (board[row][i] == '.') continue;
                if (seen.count(board[row][i])) return false; // Fixed: typo 'borad'
                seen.insert(board[row][i]);                  // Fixed: indexing board[row][i]
            }
        }
        
        // 2. Check all columns (This section was already perfect!)
        for (int col = 0; col < 9; col++) {
            unordered_set<char> seen;
            for (int i = 0; i < 9; i++) {
                if (board[i][col] == '.') continue;
                if (seen.count(board[i][col])) return false;
                seen.insert(board[i][col]);
            }
        }
        
        // 3. Check all 3x3 sub-boxes
        for (int square = 0; square < 9; square++) {
            unordered_set<char> seen; // Fixed: typo 'unorderd_set'
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) { // Fixed: changed capital 'J' to lowercase 'j'
                    int row = (square / 3) * 3 + i; // Fixed: typo 'sqaure'
                    int col = (square % 3) * 3 + j; // Fixed: typo 'sqaure'
                    
                    if (board[row][col] == '.') continue;        // Fixed: bracket nesting board[row][col]
                    if (seen.count(board[row][col])) return false; // Fixed: bracket nesting board[row][col]
                    seen.insert(board[row][col]);                 // Fixed: bracket nesting board[row][col]
                }
            }
        }
        return true;
    }
};