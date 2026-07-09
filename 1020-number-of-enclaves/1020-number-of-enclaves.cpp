class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ct=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                vis[i][0]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                q.push({0,i});
                vis[0][i]=1;
            }
        }
        for(int i=0;i<m;i++){
            if(grid[n-1][i]==1){
                q.push({n-1,i});
                vis[n-1][i]=1;
            }
        }
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==1&&vis[nr][nc]!=1){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }

            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&vis[i][j]==0){
                    ct++;
                }
            }
        }
        return ct;
        
    }
};