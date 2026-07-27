class Solution {
public:
    map<pair<int,int>, int> dp;

    int dfs(vector<int>& nums, int ind, int target) {

        if (ind == 0) {
            if (target == 0 && nums[0] == 0) return 2;
            if (target == nums[0]) return 1;
            if (target == -nums[0]) return 1;
            return 0;
        }

        if (dp.count({ind, target}))
            return dp[{ind, target}];

        int plus = dfs(nums, ind - 1, target - nums[ind]);

        int minus = dfs(nums, ind - 1, target + nums[ind]);

        return dp[{ind, target}] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        return dfs(nums, nums.size() - 1, target);
    }
};