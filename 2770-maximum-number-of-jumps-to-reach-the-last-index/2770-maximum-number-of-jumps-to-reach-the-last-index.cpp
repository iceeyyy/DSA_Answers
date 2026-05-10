class Solution {
public:
    int solve(int i,vector<int>& nums,int target,vector<int>& dp){
        if(nums.size()-1==i){
            return 0;
        }
        if(dp[i]!=INT_MIN) return dp[i];
        int res=INT_MIN;

        for(int j=i+1;j<nums.size();j++){
            if(abs(nums[j]-nums[i])<=target){
                int temp=1+solve(j,nums,target,dp);
                res=max(res,temp);
            }
        }

        return dp[i]=res;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n,INT_MIN);
        int result=solve(0,nums,target,dp);
        // return solve(0,nums,target);
        return result<0?-1:result;
    }
};