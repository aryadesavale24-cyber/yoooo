
class Solution {
public:
    int calculateSum(string str) {
        int sum = 0;

        for (char ch : str) {
            sum += ch - '0';
        }

        return sum;
    }

    string digitSum(string s, int k) {

        while (s.length() > k) {

            string temp = "";

            for (int i = 0; i < s.length(); i += k) {

                string group = s.substr(i, k);

                int sum = calculateSum(group);

                temp += to_string(sum);
            }

            s = temp;
        }

        return s;
    }
};
