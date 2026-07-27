class Solution {
public:
    bool rotateString(string s, string goal) {
        int ss=s.size();
        int a=ss;
        while(a!=0){
            char y=s[0];
        for(int i=1;i<ss;i++){
            s[i-1]=s[i];

            
        }
        s[ss-1]=y;
        if(s==goal) return true;
        a--;
        }
        return false;
        
    }
};