class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = nums.size() - 1;
        int count = 1;

        while (i > 0) {
            if (nums[i] != nums[i - 1]) {
                count++;

                if (count == 3)
                    return nums[i - 1];
            }

            i--;
        }

        return nums[nums.size() - 1];
    }
};