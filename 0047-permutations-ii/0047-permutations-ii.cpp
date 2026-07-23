class Solution {
public:
    void dfs(vector<int>&nums,vector<int>&ans,vector<vector<int>>&anss,int vis[]){
        int n=nums.size();
        if(ans.size()==nums.size()){
            anss.push_back(ans);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                ans.push_back(nums[i]);
                vis[i]=1;
                dfs(nums,ans,anss,vis);
                vis[i]=0;
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        int vis[n];
        for(int i=0;i<n;i++){
            vis[i]=0;
        }
        vector<int>ans;
        vector<vector<int>>anss;
        dfs(nums,ans,anss,vis);
       // return anss;
        set<vector<int>>st;
        for(auto it:anss){
            st.insert({it});
        }
        vector<vector<int>>a;
        for(auto it:st){
            a.push_back(it);
        }
        return a;
    }
}; 
