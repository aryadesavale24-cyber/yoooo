class Solution {
public:

    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {

        int n = s.size();
        int ans = 0;

        int i = 0;

        while (i < n) {

            // First check palindrome of length k
            if (i + k - 1 < n &&
                isPalindrome(s, i, i + k - 1)) {

                ans++;
                i = i + k;
            }

            // Then check palindrome of length k + 1
            else if (i + k < n &&
                     isPalindrome(s, i, i + k)) {

                ans++;
                i = i + k + 1;
            }

            // No palindrome starting at i
            else {
                i++;
            }
        }

        return ans;
    }
};