class Solution {
public:
    long long reverse(long long n){
        long long x=0;
        while(n){
            int y=n%10;
            n=n/10;
            x=x*10+y;

        }
        return x;

    }

    long long sumAndMultiply(long long n) {
        long long  sum=0;
        long long  r=0;
        while(n){
            long long x=n%10;
            if(x!=0){
            sum+=x;
            r=r*10+x;
            }
            n=n/10;
 } 
     long long a=reverse(r);
     return sum*a;

        
    }
};