class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long start=1000;
        while(start<=n){
            ans+=(n-start+1);
            start=start*1000;
        }
        return ans;
        
    }
    //logic is after every 10*3 there is a comma i have written that in my notebook green one so there are two code but logic is same notebook one is more optimized

};