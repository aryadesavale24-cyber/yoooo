class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long case1=nums[n-1]*nums[0]*nums[1];
        long long case2=nums[n-3]*nums[n-2]*nums[n-1];
        return int(max(case1,case2)); 
    }
};