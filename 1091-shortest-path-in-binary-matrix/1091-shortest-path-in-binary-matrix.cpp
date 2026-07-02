class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1) return -1;
        vector<vector<int>>vis(n,vector<int>(n,INT_MAX));
        queue<pair<pair<int,int>,int>>q;
   if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
    return -1;

vis[0][0] = 1;
q.push({{0,0},1});
        while(!q.empty()){

           int  x=q.front().first.first;
           int  y=q.front().first.second;
           int st=q.front().second;
           q.pop();
           if(x==n-1&&y==n-1){
            return st;
           }
            
        int drow[]={1,1,1,0,-1,-1,-1,0};
        int dcol[]={-1,0,1,1,1,0,-1,-1};
        for(int i=0;i<=7;i++){
            int nrow=x+drow[i];
            int ncol=y+dcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<n&&grid[nrow][ncol]==0){
                if(vis[nrow][ncol]>st+1){
                    q.push({{nrow,ncol},st+1});
                    vis[nrow][ncol]=st+1;
                }
                

            }
        }

        }
        return -1;
        
        
    }
};