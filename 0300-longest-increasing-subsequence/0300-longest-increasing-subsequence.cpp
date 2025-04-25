class Solution {
public:
    int solve(int ind,int prevInd,vector<int>& nums,vector<vector<int>>& dp){
        //Base Case when we cross the last index
        if(ind==nums.size()){
            return 0;
        }
        //we are  using prevInd+1 because it starts with -1 and we are shifting it to right
        // -1 -> 0
        //  0 -> 1
        if(dp[ind][prevInd+1]!=-1) return dp[ind][prevInd+1];

        int notPick=solve(ind+1,prevInd,nums,dp);

        int pick=0;

        if(prevInd==-1|| nums[prevInd]<nums[ind]){
            pick=1+solve(ind+1,ind,nums,dp);
        }

        return dp[ind][prevInd+1]=max(notPick,pick);
    }
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();

        vector<vector<int>> dp(n,vector<int> (n+1,-1));

        return solve(0,-1,nums,dp);
    }
};