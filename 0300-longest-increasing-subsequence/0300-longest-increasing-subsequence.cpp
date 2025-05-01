class Solution {
public:
int solve(int ind,int prevind,vector<int>& nums,vector<vector<int>>& dp){

    if(ind==nums.size()){
        return 0;
    }
    if(dp[ind][prevind+1]!=-1) return dp[ind][prevind+1];

    int notPick=solve(ind+1,prevind,nums,dp);
    int Pick=0;
    //if we include prevind==-1 then we can include 1st index
    if(prevind==-1 || nums[prevind]<nums[ind]){
        Pick=1+solve(ind+1,ind,nums,dp);
    }

    return dp[ind][prevind+1]=max(notPick,Pick);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return solve(0,-1,nums,dp);
    }
};