
class Solution {
public:
    int thirdMax(vector<int>& nums) {

        long long max1 = -10000000000LL;
        long long max2 = -10000000000LL;
        long long max3 = -10000000000LL;

        for (int i = 0; i < nums.size(); i++) {

            // Skip duplicates
            if (max1 != -10000000000LL && nums[i] == max1)
                continue;

            if (max2 != -10000000000LL && nums[i] == max2)
                continue;

            if (max3 != -10000000000LL && nums[i] == max3)
                continue;

            if (nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if (nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
            }
            else if (nums[i] > max3) {
                max3 = nums[i];
            }
        }

        // If fewer than 3 distinct elements exist
        if (max3 == -10000000000LL)
            return static_cast<int>(max1);

        return static_cast<int>(max3);
    }
};
