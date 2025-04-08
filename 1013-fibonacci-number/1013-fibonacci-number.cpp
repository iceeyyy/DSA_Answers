class Solution {
public:
 int solve(int n ,vector<int>&dp){
    if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }   
    if(dp[n]!=-1) return dp[n];

    return dp[n]=fib(n-1) +fib(n-2);
 }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};