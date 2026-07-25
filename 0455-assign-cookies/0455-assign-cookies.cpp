class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        int gi=g.size(),si=s.size();
        while(i<gi&&j<si){
            if(s[j]>=g[i]){
                i++;
            }
            j++;
        }
        return i;
        
    }
};