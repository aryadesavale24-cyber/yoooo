class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1, max2, max3;

        max1 = -10000000000LL;
        max2 = -10000000000LL;
        max3 = -10000000000LL;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2 && nums[i] != max1) {
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i] > max3 && nums[i] != max1 && nums[i] != max2) {
                max3 = nums[i];
            }
        }

        if(max3 == -10000000000LL)
            return static_cast<int>(max1);

        return static_cast<int>(max3);
    }
};