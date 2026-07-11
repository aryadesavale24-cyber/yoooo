class Solution {
public:
    void dfs(int node, vector<int>list[],vector<int>&vis,int &edge,int &vertices){
        vis[node]=1;
        vertices++;
        edge+=list[node].size();
        for(auto it:list[node]){
            if(!vis[it]){
                dfs(it,list,vis,edge,vertices);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans=0;
        vector<int>list[n];
        vector<int>vis(n,0);
        for(auto it:edges){
            int noo=it[0];
            int ad=it[1];
            list[noo].push_back(ad);
            list[ad].push_back(noo);
        }
        for(int i=0;i<n;i++){
            

            if(!vis[i]){
            int edge=0;
            int vertices=0;
                dfs(i,list,vis,edge,vertices);
                 edge/=2;
            if(edge==vertices*(vertices-1) / 2) ans++;
            }
            
         }
         return ans;

        
    }
};