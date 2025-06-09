class Solution {
public:
    int solve(int n,long long p1,long long p2){
        int diff=0;
        while(p1<=n){
            diff+=min((long long )n+1,p2)-p1;
            p1*=10;
            p2*=10;
        }
        return diff;
    }
    int findKthNumber(int n, int k) {
        int cur=1;
        k-=1;
        while(k){
            int diff=solve(n,cur,cur+1);
            if(diff<=k){
                k-=diff;
                cur++;
            }
            else{
                k--;
                cur*=10;
            }
        }
        return cur;
    }

};