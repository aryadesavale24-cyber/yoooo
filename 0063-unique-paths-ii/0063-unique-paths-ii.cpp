class Solution {
public:
int f(int n,int m,vector<vector<int>>&dp,vector<vector<int>>& obs){
    if(n<0||m<0||obs[n][m]==1) return 0;
    if(n==0&&m==0) return 1;
    if(dp[n][m]!=-1) return dp[n][m];
    int up=f(n-1,m,dp,obs);
    int left=f(n,m-1,dp,obs);
    return dp[n][m]=up+left;

}
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int n=obs.size();
        int m=obs[0].size();
        vector<vector<int>>dp(n,vector(m,-1));
        int x=f(n-1,m-1,dp,obs);
        return x;

        
    }
};