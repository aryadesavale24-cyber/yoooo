class Solution {
    class disjoint{
        public:
        vector<int>par;
        vector<int>size;
        disjoint(int n){
            par.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<n;i++){
                par[i]=i;
                size[i]=1;            
                }
                }
        int findup(int node){
            if(node==par[node]) return node;
            return par[node]=findup(par[node]);   //path compression 
        }
        void findun(int u,int v){
            int up=findup(u);
            int vp=findup(v);
            if(up==vp) return; //this is when they are in the same component
            if(size[up]<size[vp]){
                par[up]=par[vp];
                size[vp]+=size[up];
            }
            else{
                par[vp]=par[up];
                size[up]+=size[vp];
            }
        }
    };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjoint ds(n);
        int extra=0;
        for(auto it:connections){
            int a=it[0];
            int b=it[1];
            if(ds.findup(a)==ds.findup(b)) extra++;
            else ds.findun(a,b);
        }
        int component=0;
        for(int i=0;i<n;i++){
            if(ds.par[i]==i){
                component++;
            }
        }
        int need=component-1;
        return(extra>=need)?need:-1;

        
    }
};