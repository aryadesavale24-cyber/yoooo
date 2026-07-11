class Solution {
    class Disjoint{
        public:
        vector<int>par;
        vector<int>size;
        Disjoint(int n){
            par.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<n;i++){
                par[i]=i;
                size[i]=1;
            }
        }
        int findp(int node){
            if(par[node]==node) return node;
            return par[node]=findp(par[node]);

        }
        void findu(int u,int v){
            int uu=findp(u);
            int vv=findp(v);
            if(uu==vv) return;
            if(size[uu]<size[vv]){
                par[uu]=vv;
                size[vv]+=size[uu];
            }
            else{
                par[vv]=uu;
                size[uu]+=size[vv];
            }
        }

    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mp;
        int n=accounts.size();
        Disjoint ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){  //if the string is not in the map ok
                mp[mail]=i;
                }
                else ds.findu(mp[mail],i);
            }
        } // part 1 to iterate and put the element in the map according to the logic(it the same elemnt exist then we will just join the node and the parent consisting of that same element)
        vector<string>x[n];
        for(auto it:mp){
            string s=it.first;
            int q=ds.findp(it.second);
            x[q].push_back(s);
        }
        // now iterating stuff from the map and putting it in the string and taking care of the parent also 
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
        if(x[i].size()==0) continue;
        sort(x[i].begin(),x[i].end());
        vector<string>temp;
        temp.push_back(accounts[i][0]);
        for(auto y:x[i]){
            temp.push_back(y);

        }
        ans.push_back(temp);
}
return ans;
}
};