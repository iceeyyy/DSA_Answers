class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend==divisor) return 1;

        unsigned int  ans=0;
        bool sign=1;

        if(dividend>=0 && divisor<0) sign=0;
        else if(dividend<=0 && divisor>0) sign=0;

        unsigned int n=abs((long long)dividend);
        unsigned int d=abs((long long)divisor);

        while(n>=d){
            int cnt=0;
            while( n > (d*(1 << cnt+1))){
                cnt++;
            }
            ans+=(1<<cnt);
            n-=d*(1<<cnt); //(1<<cnt equals to 2 ** cnt)
        }

        if(ans == (1<<31) && !sign){
            return INT_MIN; //if term is neagtive
        }
        if(ans == (1<<31) && sign){
            return INT_MAX; //if term is positive
        }
        return sign ? ans: (-1*ans);
    }
};