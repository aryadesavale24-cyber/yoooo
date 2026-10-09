class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                // We need two closing parentheses.
                if (balance % 2 == 1) {
                    ans++;
                    balance--;
                }

                balance += 2;
            } 
            else {
                balance--;

                if (balance < 0) {
                    // Insert an opening parenthesis.
                    ans++;
                    balance = 1;
                }
            }
        }

        return ans + balance;
    }
};