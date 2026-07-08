class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // prefNZ[i] = number of non-zero digits in s[0...i-1]
        vector<int> prefNZ(n + 1, 0);

        vector<int> digits;

        for (int i = 0; i < n; i++) {
            prefNZ[i + 1] = prefNZ[i];
            if (s[i] != '0') {
                prefNZ[i + 1]++;
                digits.push_back(s[i] - '0');
            }
        }

        int m = digits.size();

        // powers of 10
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // prefix hash (concatenated number modulo MOD)
        vector<long long> hash(m + 1, 0);

        // prefix digit sum
        vector<long long> prefSum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            hash[i + 1] = (hash[i] * 10 + digits[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digits[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int L = prefNZ[l];
            int R = prefNZ[r + 1];

            if (L == R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L;

            long long x =
                (hash[R] - hash[L] * pow10[len] % MOD + MOD) % MOD;

            long long sum = prefSum[R] - prefSum[L];

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};