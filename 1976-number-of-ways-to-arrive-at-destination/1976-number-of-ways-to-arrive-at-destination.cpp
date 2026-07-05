class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
         const int mod = 1e9 + 7;
        for(auto it:roads){
            int no=it[0];
            int ad=it[1];
            int co=it[2];
            adj[no].push_back({ad,co});
            adj[ad].push_back({no,co});

        }
        vector<long long>dis(n,LLONG_MAX);
        vector<int>ways(n,0);
        dis[0]=0;
        ways[0]=1;
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > q;
        q.push({0,0});
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int node=it.second;
            long long cost=it.first;
            if(cost>dis[node]){
                continue;
            }
            for(auto it:adj[node]){
                int add=it.first;
                int c2=it.second;
                if(dis[add]>c2+cost){
                    dis[add]=c2+cost;
                    ways[add]=ways[node];
                    q.push({c2+cost,add});
                }
                else if(dis[add]==c2+cost){
                    ways[add]=(ways[add]+ways[node])%mod;
                    
                }
                
            }
        }
        return ways[n-1];


        
    }
};