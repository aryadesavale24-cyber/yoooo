class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<int>>& grid, int i, int j, int xr) {
        if (i >= m || j >= n) {
            return false;
        }

        xr ^= grid[i][j];

        if (i == m - 1 && j == n - 1) {
            return xr == 0; // Not sufficient to compute the minimum alone
        }

        // Memoization state must include xr.
        // We need a different state for every reachable XOR value.
        return false;
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // A single boolean result per (i,j,xr) can tell us
        // whether a particular XOR value is achievable.
        vector<vector<vector<bool>>> memo(
            m, vector<vector<bool>>(n, vector<bool>(1024, false))
        );

        // Use a recursive search that marks all reachable XOR states.
        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(n, vector<bool>(1024, false))
        );

        function<void(int, int, int)> dfs =
            [&](int i, int j, int xr) {
                xr ^= grid[i][j];

                if (visited[i][j][xr]) return;
                visited[i][j][xr] = true;

                if (i + 1 < m) {
                    dfs(i + 1, j, xr);
                }

                if (j + 1 < n) {
                    dfs(i, j + 1, xr);
                }
            };

        dfs(0, 0, 0);

        for (int x = 0; x < 1024; x++) {
            if (visited[m - 1][n - 1][x]) {
                return x;
            }
        }

        return 0;
    }
};