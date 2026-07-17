class Solution {
public:
    int f(int n, int m, vector<vector<int>>& dp,
          vector<vector<int>>& obs) {

        // Out of bounds
        if(n < 0 || m < 0)
            return 0;

        // Obstacle
        if(obs[n][m] == 1)
            return 0;

        // Reached starting point
        if(n == 0 && m == 0)
            return 1;

        // Already calculated
        if(dp[n][m] != -1)
            return dp[n][m];

        int up = f(n-1, m, dp, obs);
        int left = f(n, m-1, dp, obs);

        return dp[n][m] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obs) {

        int n = obs.size();
        int m = obs[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Last cell is (n-1, m-1)
        return f(n-1, m-1, dp, obs);
    }
};