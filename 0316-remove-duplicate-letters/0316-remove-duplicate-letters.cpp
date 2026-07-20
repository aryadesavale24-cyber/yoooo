class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>mp;
        vector<bool>vis(26,false);
        stack<char>st;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;                //make sure the last element of unique character 
        }
        for(int i=0;i<s.size();i++){
            if(vis[s[i]-'a']) continue;       // check if the element is present in stack
          
        while(!st.empty()&&mp[st.top()]>i&&st.top()>s[i]){
            vis[st.top()-'a']=false;
            st.pop();
        }
        vis[s[i]-'a']=true;
        st.push(s[i]);

        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};