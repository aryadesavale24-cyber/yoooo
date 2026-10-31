class Solution {
public:
    int n, m;
    long long MOD = 1e9 + 7;

    vector<vector<vector<long long>>> dp;

    long long f(int i, int j, char c, vector<vector<int>>& grid) {

        if (i >= n || i < 0 || j >= m || j < 0)
            return 0;

        if (i == n - 1 && j == m - 1)
            return 1;

        int dir = (c == 'r') ? 0 : 1;

        if (dp[i][j][dir] != -1)
            return dp[i][j][dir];

        if (grid[i][j] == 1) {

            if (c == 'r') {
                long long down = f(i + 1, j, 'd', grid);
                return dp[i][j][dir] = down % MOD;
            }
            else {
                long long right = f(i, j + 1, 'r', grid);
                return dp[i][j][dir] = right % MOD;
            }
        }

        long long r = f(i, j + 1, 'r', grid);
        long long d = f(i + 1, j, 'd', grid);

        return dp[i][j][dir] = (r + d) % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        dp = vector<vector<vector<long long>>>(
            n, vector<vector<long long>>(m, vector<long long>(2, -1))
        );

        return (int)(f(0, 0, 'r', grid) % MOD);
    }
};