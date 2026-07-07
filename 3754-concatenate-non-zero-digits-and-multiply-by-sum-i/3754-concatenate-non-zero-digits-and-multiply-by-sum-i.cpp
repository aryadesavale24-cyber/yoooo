class Solution {
public:
    long long reverseNumber(long long n) {
        long long rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }

    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long num = 0;

        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                sum += digit;
                num = num * 10 + digit;
            }
            n /= 10;
        }

        long long rev = reverseNumber(num);
        return sum * rev;
    }
};