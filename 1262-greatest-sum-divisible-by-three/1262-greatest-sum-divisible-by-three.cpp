class Solution {
public:
    int solve(int i,int rem ,vector<int>& nums,vector<vector<int>>& dp){
        if(i>=nums.size()){
            if(rem==0) return 0; //correct sum
            return INT_MIN; //invalid 
        }
        if(dp[i][rem]!=-1) return dp[i][rem];

        int take=nums[i]+solve(i+1,((rem+nums[i])%3),nums,dp);
        int notTake=solve(i+1,(rem)%3,nums,dp);

        return dp[i][rem] = max(take,notTake);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(3,-1)); //3 possible remainders

        return solve(0,0,nums,dp);
    }
};