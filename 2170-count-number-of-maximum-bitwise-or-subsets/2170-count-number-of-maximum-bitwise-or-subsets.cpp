class Solution {
public:
    int solve(int i,int OR,int maxOr ,vector<int> &nums,vector<vector<int>>& dp){
        if(i==nums.size()){
            if(OR==maxOr){
                return 1;
            }
            return 0;
        }
        if(dp[i][OR]!=-1) return dp[i][OR];

        int take=0;
        int notTake=0;
        
        take+=solve(i+1,OR|nums[i],maxOr,nums,dp);
        notTake+=solve(i+1,OR,maxOr,nums,dp);
        

        return dp[i][OR]=take+notTake;
        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            maxOr |=nums[i];
        }
        vector<vector<int>> dp(n+1,vector<int> (maxOr+1,-1));

        return solve(0,0,maxOr,nums,dp);
    }
};