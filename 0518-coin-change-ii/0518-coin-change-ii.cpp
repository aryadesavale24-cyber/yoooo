
class Solution {
public:
    int dfs(vector<int>&coins,int ind,int target,vector<vector<int>>&dp){
        if(target==0) return 1;
        if(ind==0){
            if(target%coins[ind]==0) return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nt=dfs(coins,ind-1,target,dp);
        int t=0;
        if(coins[ind]<=target){
            t=dfs(coins,ind,target-coins[ind],dp);
}
        return dp[ind][target]=nt+t;
    }
    int change(int amount,vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int x=dfs(coins,n-1,amount,dp);
        return x;



        
    }
};