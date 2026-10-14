class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>num*9) return "";
        int nines=sum/9;
        int remainder=sum%9;
        string ans(nines,'9');
        if(remainder>0){
            ans.push_back(remainder+'0');
        }
        ans.append(num-ans.length(),'0');
        return ans;
        
    }
};