class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if(meetings.size()==0) return days;
        int ans=0;
        sort(meetings.begin(),meetings.end());

        int s1=meetings[0][0];
        if(s1>1) ans+=s1-1;
        int prev=meetings[0][1];

        for(int i=1;i<meetings.size();i++){
            int start=meetings[i][0];
            int end=meetings[i][1];

            if(start>prev){
                ans+=start-prev-1;
            }
            prev=max(prev,end);

            

        }
        if(days>prev){
            ans+=days-prev;
        }
        return ans;


        
    }
};