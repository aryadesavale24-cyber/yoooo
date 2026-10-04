class Solution {
public:
    bool boolisvalid(int ind,int balance,string&s,vector<vector<int>>&dp){
        if(ind==s.length()) return balance==0;
    
    bool isvalid=false;
    if(dp[ind][balance]!=-1) return dp[ind][balance];
    if(s[ind]=='*'){
        isvalid |=boolisvalid(ind+1,balance+1,s,dp);
        isvalid|=boolisvalid(ind+1,balance,s,dp);
        if(balance>0) isvalid|=boolisvalid(ind+1,balance-1,s,dp);
    }
    else if(s[ind]=='('){
        isvalid|=boolisvalid(ind+1,balance+1,s,dp);
    }
    else{
         if(balance>0) isvalid|=boolisvalid(ind+1,balance-1,s,dp);
        }
        return dp[ind][balance]=isvalid;

    
}
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,-1));
        bool ans=boolisvalid(0,0,s,dp);
        return ans;
        
    }
};