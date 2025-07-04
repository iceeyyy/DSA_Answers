class Solution {
    public int solve(int i ,int n,int dp[]){
        if(i==n) return 1;
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ways=0;
        ways+=solve(i+1,n,dp)+ solve(i+2,n,dp);

        return dp[i]=ways;
    }
    public int climbStairs(int n) {
        int dp[] = new int[n+1];

        Arrays.fill(dp,-1);

        return solve(0,n,dp);
    }
}