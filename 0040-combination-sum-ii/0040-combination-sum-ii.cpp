class Solution {
public:
void dfs(int ind,vector<int>&cand,vector<vector<int>>&ans,vector<int>&ds,int size,int target){
    if(target==0) ans.push_back(ds);
    for(int i=ind;i<size;i++){
        if(i>ind && cand[i]==cand[i-1]) continue;
        if(cand[i]>target) break;
        ds.push_back(cand[i]);
        dfs(i+1,cand,ans,ds,size,target-cand[i]);
        ds.pop_back();

    }
}
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        int size=cand.size();
        vector<int>ds;
        vector<vector<int>>ans;
        sort(cand.begin(),cand.end());
        dfs(0,cand,ans,ds,size,target);
        return ans;

        
    }
};