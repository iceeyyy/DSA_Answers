class Solution {
public:
    int solve(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        //Memoized Solution

        //Base Case 1 (if we reah our desired sum of the subset)
        if(target==0) return 1;
        //Base Case 2 (if we reach the last index we can return 1 or 0 base upon the value of target and element at that index)
        if(ind==nums.size()-1) return (nums[ind]==target);

        if(dp[ind][target]!=-1) return dp[ind][target];

        int notTake=solve(ind+1,target,nums,dp);

        int take =false;
        //take condition would be considered only if element at that index is smaller or equal to the target
        if(nums[ind]<=target){
            take=solve(ind+1,target-nums[ind],nums,dp);
        }
        return dp[ind][target] = notTake|take;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;

        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }
        //it is only possible if the sum of the array is even 
        if(totalSum % 2) return false;

        int target=totalSum/2;

        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));

        if(solve(0,target,nums,dp)){
            return true;
        }

        return false;
    }
};