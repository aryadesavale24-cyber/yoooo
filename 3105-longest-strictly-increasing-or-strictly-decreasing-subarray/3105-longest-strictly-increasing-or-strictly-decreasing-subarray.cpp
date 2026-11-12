class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int count=1;
        bool x=true;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                if(x){
                    count++;
                    ans=max(ans,count);
                }
                else {
                    count=2;
                    x=true;
                    ans=max(ans,count);
            }
        }
            else if(nums[i-1]>nums[i]){
                if(x){
                    count=2;
                    x=false;
                    ans=max(ans,count);
                }
                else{
                    count++;
                    ans=max(ans,count);
                }
            }
            else count=1;

        }
        return ans;
        
    }
};