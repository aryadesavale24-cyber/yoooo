class Solution {
public:
    int dfs(vector<int>&coins,int ind,int target,vector<vector<int>>&dp){
        if(ind==0){
            if(target%coins[ind]==0) return target/coins[ind];
            else return 1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nt=0+dfs(coins,ind-1,target,dp);
        int t=INT_MAX;
        if(coins[ind]<=target){
            t=1+dfs(coins,ind,target-coins[ind],dp);
}
        return dp[ind][target]=min(t,nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int x=dfs(coins,n-1,amount,dp);
        if (x >= 1e9)
    return -1;
else
    return x;


        
    }
};