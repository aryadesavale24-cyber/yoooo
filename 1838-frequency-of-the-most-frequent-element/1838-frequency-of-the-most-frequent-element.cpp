class Solution {
public:
    int binary_search(int k,vector<int>&nums,int target_index,vector<long>&pre_sum){
        int left=0;
        int right=target_index;
        int result=target_index;// index till the best_index
        while(left<=right){
            int mid=left+(right-left)/2;
            long long window_sum=pre_sum[target_index]-pre_sum[mid]+nums[mid];
            long long convert=1LL*nums[target_index]*(target_index-mid+1);
            long long operation=convert-window_sum;
            if(operation>k){
                left=mid+1;
            }
            else{
                result=mid;
                right=mid-1;
        }
    }
    return target_index-result+1; // no of element
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long>pre_sum(n);
        pre_sum[0]=nums[0];
        for(int i=1;i<n;i++){
            pre_sum[i]=pre_sum[i-1]+nums[i];
        }
        int maxx=0;
        for(int i=0;i<n;i++){
            maxx=max(maxx,binary_search(k,nums,i,pre_sum));
        }
        return maxx;
        
    }
};