class Solution {
public:
    int dsum(int n){
        int ans=0;
        while(n>0){
            ans+=n%10;
            n=n/10;
        }
        return ans;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>aftersorted(nums);

        auto lambda=[&](int n1,int n2){
            int d1=dsum(n1);
            int d2=dsum(n2);
            if(d1!=d2){
                return d1<d2;
            }
            return n1<n2;

        };

        sort(begin(aftersorted),end(aftersorted),lambda);
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            map[nums[i]]=i;
        }
        int swap=0;
        for(int i=0;i<n;i++){
            int element=aftersorted[i];
            int mapped=map[element];
            if(nums[i]==aftersorted[i]) continue;
            int current=nums[i];
            nums[mapped]=nums[i];
            nums[i]=aftersorted[i];
            swap++;
            map[element]=i;
            map[current]=mapped;

        }
        return swap;
        
    }
};