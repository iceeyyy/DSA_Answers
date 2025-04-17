class Solution {
public:
    int solve(int ind,int sum,int target,vector<int>& nums,vector<vector<int>>& dp,int total){
        //memoized solution for better time complexity
        if(ind>=nums.size()){
            //we need to consider all the elements
            if(sum==target){
                return 1;
            }
            return 0;
        }
        //memoization check
        if(dp[ind][sum+total]!=-1) return dp[ind][sum+total];
        //there are two choices for every element whether we take add or subtract it
        int pos=nums[ind]+solve(ind+1,sum+nums[ind],target,nums,dp,total);
        int neg=-nums[ind]+solve(ind+1,sum-nums[ind],target,nums,dp,total);

        return dp[ind][sum+total]=pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        //sum can maximum go upto totalSum of the array
        vector<vector<int>> dp(n,vector<int> (2*total+1,-1));

        return solve(0,0,target,nums,dp,total);
    }
};