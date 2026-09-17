class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0,j=0,currsum=0;
        int result=INT_MAX;
        int bestminlen=INT_MAX;
        vector<int>minTillindex(n,INT_MAX);
        for(int j=0;j<n;j++){
            currsum+=arr[j];
            while(i<j&&currsum>target){
                currsum-=arr[i];
                i++;
            }
            if(currsum==target){
                int len=j-i+1;
                if(i>0&&minTillindex[i-1]!=INT_MAX){
                    result=min(result,len+minTillindex[i-1]);
                }
                bestminlen=min(len,bestminlen);
            }
            minTillindex[j]=bestminlen;
        


        }
        return result==INT_MAX?-1:result;
        
    }
};