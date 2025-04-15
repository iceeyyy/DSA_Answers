class Solution {
public:
    int solve(int ind,vector<int>& nums,vector<int>& dp){
        //memozied solution
        if(ind>=nums.size()){
            //if it goes out of bonds
            return 0;
        }
        if(ind==nums.size()-1){
            // if we reach the last index
            return 1;
        }

        if(dp[ind]!=-1) return dp[ind];

        
        for(int i=1;i<=nums[ind];i++){

           if(solve(ind+i,nums,dp)){
            return dp[ind]=1;
           }
        }
        return dp[ind]=0;
    }
    bool canJump(vector<int>& nums) {

        int n=nums.size();
        vector<int> dp(n,-1);

        return solve(0,nums,dp);

    }
};