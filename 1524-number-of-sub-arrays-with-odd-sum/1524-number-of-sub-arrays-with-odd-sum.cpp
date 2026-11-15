class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int m = 1e9 + 7;
        int n = arr.size();
        int odd_count = 0;
        int even_count = 1;
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = arr[i] + prefix[i - 1];
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (prefix[i] % 2 == 0) {
                count = (count + odd_count) % m;
                even_count++;
            } else {
                count = (count + even_count) % m;
                odd_count++;
            }
        }
        return count;
    }
};