class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>heal(n,vector<int>(m,-1));
        priority_queue<pair<int,pair<int,int>>>q;
        if(grid[0][0]==1) health--;
        heal[0][0]=health;
        q.push({health,{0,0}});
        int r[]={0,1,0,-1};
        int c[]={-1,0,1,0};
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int h=it.first;
            int x=it.second.first;
            int y=it.second.second;
            for(int i=0;i<4;i++){
                int rn=x+r[i];
                int cn=y+c[i];
                int a;
                if(rn>=0&&rn<n&&cn>=0&&cn<m){
                    if(grid[rn][cn]==1){
                        a=h-1;
                    }
                    else a=h;
                    

                if(rn==n-1&&cn==m-1&&a>=1) return true;

                    if(heal[rn][cn]<a){
                        heal[rn][cn]=a;
                        q.push({a,{rn,cn}});

                    }
                }
            

        }
    }
        return false;
    }
  
    
};