class Solution {
public:
    vector<vector<int>>ans;
    
    void dfs(int target,int index,int n,vector<int>&temp){
        if(target==0&&temp.size()==n){
            ans.push_back(temp);
            return;
        }
        if(index>9) return;
        if(target<0) return;
        temp.push_back(index);
        dfs(target-index,index+1,n,temp);
        temp.pop_back();
        dfs(target,index+1,n,temp);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        dfs(n,1,k,temp);
        return ans;

        
    }
};