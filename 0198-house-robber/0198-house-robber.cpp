class Solution {
public:
    int help(int i,vector<int>& dp,vector<int>& nums){
        
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];

        int rob=nums[i]+help(i+2,dp,nums);

        int skipp=help(i+1,dp,nums);

        return dp[i]=max(rob,skipp);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return help(0,dp,nums);
    }
};