class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>>q;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        int ct=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},ct});
                    vis[i][j]=1;
                    ans[i][j]=0;
                }
            }
}
while(!q.empty()){
    auto it=q.front();
    q.pop();
    int row=it.first.first;
    int col=it.first.second;
    int c=it.second;
    int drow[]={1,0,-1,0};
    int dcol[]={0,1,0,-1};
    for(int i=0;i<4;i++){
        int nr=drow[i]+row;
        int nc=dcol[i]+col;
        if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]!=1){
            q.push({{nr,nc},c+1});
            vis[nr][nc]=1;
            ans[nr][nc]=c+1;

        }

    }

}

return ans;

        
    }
};