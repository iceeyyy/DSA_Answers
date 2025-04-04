class Solution {
public:
    int help(int i,int n,vector<int>& dp){

        // if it reaches the top of staricase
        if(i==n){
            return 1;
        }
        //if it exceedes the staircase
        if(i>n){
            return 0;
        }
        //return if it is already calculated
        if(dp[i]!=-1) return dp[i];

        int l=help(i+1,n,dp);
        int r=help(i+2,n,dp);

        return dp[i]=l+r;
    }
    int climbStairs(int n) {

        vector<int> dp(n+1,-1);

        return help(0,n,dp);
    }
};