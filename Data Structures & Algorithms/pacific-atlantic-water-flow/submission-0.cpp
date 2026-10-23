
class Solution {
public:
    int m, n;
    vector<vector<int>> pacific, atlantic;

    void dfs(vector<vector<int>>& heights, int r, int c,
             vector<vector<int>>& visited) {

        visited[r][c] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if (visited[nr][nc])
                continue;

            if (heights[nr][nc] >= heights[r][c]) {
                dfs(heights, nr, nc, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        pacific.assign(m, vector<int>(n, 0));
        atlantic.assign(m, vector<int>(n, 0));

        for (int c = 0; c < n; c++) {
            dfs(heights, 0, c, pacific);
            dfs(heights, m - 1, c, atlantic);
        }

        for (int r = 0; r < m; r++) {
            dfs(heights, r, 0, pacific);
            dfs(heights, r, n - 1, atlantic);
        }

        vector<vector<int>> ans;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }
};
