class Solution {
public:
    vector<int>f(vector<int>&arr){
        stack<int>st;
        vector<int>arr1(arr.size());
        for(int i=0;i<arr.size();i++){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                arr1[i]=-1;
            }
            else arr1[i]=st.top();
            st.push(i);
        }
        return arr1;
    }
    vector<int>fe(vector<int>&arr){
        stack<int>st;
        vector<int>arr1(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                arr1[i]=arr.size();
            }
            else arr1[i]=st.top();
            st.push(i);
        }
        return arr1;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        vector<int>pse=f(arr);
        vector<int>nsee=fe(arr);
        long long ans=0;
        for(int i=0;i<arr.size();i++){
            long long left=i-pse[i];
            long long right=nsee[i]-i;
            long long contribution = (left * right % mod) * arr[i] % mod;
            ans = (ans + contribution) % mod;
           

        }
        return ans;
        



        
    }
};