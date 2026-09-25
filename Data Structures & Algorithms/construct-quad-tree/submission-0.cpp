class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, grid.size());
    }

    Node* dfs(vector<vector<int>>& grid, int r, int c, int n) {
        if (n == 1) {
            return new Node(grid[r][c] == 1, true);
        }

        int mid = n / 2;

        Node* topLeft = dfs(grid, r, c, mid);
        Node* topRight = dfs(grid, r, c + mid, mid);
        Node* bottomLeft = dfs(grid, r + mid, c, mid);
        Node* bottomRight = dfs(grid, r + mid, c + mid, mid);

        if (topLeft->isLeaf &&
            topRight->isLeaf &&
            bottomLeft->isLeaf &&
            bottomRight->isLeaf &&
            topLeft->val == topRight->val &&
            topLeft->val == bottomLeft->val &&
            topLeft->val == bottomRight->val) {
            return topLeft;
        }

        return new Node(false, false,
                        topLeft,
                        topRight,
                        bottomLeft,
                        bottomRight);
    }
};