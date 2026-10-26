class Solution {
public:
    int n,m;
    bool dfs(vector<vector<char>>& grid, string word,string&ans,int i,int j,vector<vector<int>>&visited){
        if(i>=n||i<0||j<0||j>=m||visited[i][j]==1) return false;
        ans.push_back(grid[i][j]);
        visited[i][j]=1;
        int len = ans.size();

        if (len > word.size() || ans[len - 1] != word[len - 1]) {
            ans.pop_back();
            visited[i][j] = 0;
            return false;
        }
        if(ans==word) return true;
        bool left=dfs(grid,word,ans,i-1,j,visited);
        bool right=dfs(grid,word,ans,i+1,j,visited);
        bool up=dfs(grid,word,ans,i,j+1,visited);
        bool down=dfs(grid,word,ans,i,j-1,visited);
        ans.pop_back();
        visited[i][j]=0;
        return up||down||right||left;
    }
    bool exist(vector<vector<char>>&grid, string word) {
        n=grid.size();
        m=grid[0].size();
        string ans="";
        vector<vector<int>>visited(n,vector<int>(m,0));
        bool arya=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arya|=dfs(grid,word,ans,i,j,visited);
                
            }
        }
        return arya;


        
    }
};