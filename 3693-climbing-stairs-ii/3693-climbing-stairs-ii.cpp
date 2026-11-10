class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);

        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int jump = 1; jump <= 3; jump++) {
                int next = i + jump;

                if (next <= n) {
                    int cost = costs[next - 1] + jump * jump;

                    dp[i] = min(dp[i], cost + dp[next]);
                }
            }
        }

        return dp[0];
    }
};